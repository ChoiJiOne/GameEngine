#include "OBBComponent.h"

OBBComponent::OBBComponent(GameObject* Object)
	: BoundComponent(Object, BoundComponent::EBoundaryShape::OBB)
{}

OBBComponent::OBBComponent(GameObject* Object, const Vec2f& Center, const float& Width, const float& Height, const float& Rotate)
	: BoundComponent(Object, BoundComponent::EBoundaryShape::OBB)
	, Center_(Center)
	, Width_(Width)
	, Height_(Height)
	, Rotate_(Rotate)
{
	UpdateBoundPositions();
}

OBBComponent::~OBBComponent()
{}

void OBBComponent::SetCenter(const Vec2f& Center)
{
	Center_ = Center;
	UpdateBoundPositions();
}

void OBBComponent::SetWidth(const float& Width)
{
	Width_ = Width;
	UpdateBoundPositions();
}

void OBBComponent::SetHeight(const float& Height)
{
	Height_ = Height;
	UpdateBoundPositions();
}

void OBBComponent::SetRotate(const float& Rotate)
{
	Rotate_ = Rotate;
	UpdateBoundPositions();
}

void OBBComponent::UpdateBoundPositions()
{
	BoundPositions_[INDEX_LB] = Vec2f(-Width_ / 2.0f, -Height_ / 2.0f);
	BoundPositions_[INDEX_LT] = Vec2f(-Width_ / 2.0f, +Height_ / 2.0f);
	BoundPositions_[INDEX_RB] = Vec2f(+Width_ / 2.0f, -Height_ / 2.0f);
	BoundPositions_[INDEX_RT] = Vec2f(+Width_ / 2.0f, +Height_ / 2.0f);

	float Radian = ToRadian(Rotate_);
	float Cos = cos(Radian);
	float Sin = sin(Radian);

	for (auto& BoundPosition : BoundPositions_)
	{
		Vec2f RotatePosition;

		RotatePosition.x = Cos * BoundPosition.x - Sin * BoundPosition.y;
		RotatePosition.y = Sin * BoundPosition.x + Cos * BoundPosition.y;

		BoundPosition = RotatePosition;
		BoundPosition += Center_;
	}
}