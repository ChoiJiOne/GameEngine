#include "AABBComponent.h"

AABBComponent::AABBComponent(GameObject* Object)
	: BoundComponent(Object, BoundComponent::EBoundaryShape::AABB)
{}

AABBComponent::AABBComponent(GameObject * Object, const Vec2f & Center, const float& Width, const float& Height)
	: BoundComponent(Object, BoundComponent::EBoundaryShape::AABB)
	, Center_(Center)
	, Width_(Width)
	, Height_(Height)
{
	UpdateBoundPositions();
}

AABBComponent::~AABBComponent()
{}

void AABBComponent::SetCenter(const Vec2f& Center)
{
	Center_ = Center;
	UpdateBoundPositions();
}

void AABBComponent::SetWidth(const float& Width)
{
	Width_ = Width;
	UpdateBoundPositions();
}

void AABBComponent::SetHeight(const float& Height)
{
	Height_ = Height;
	UpdateBoundPositions();
}

void AABBComponent::UpdateBoundPositions()
{
	BoundPositions_[INDEX_LB] = Center_ + Vec2f(-Width_ / 2.0f, -Height_ / 2.0f);
	BoundPositions_[INDEX_LT] = Center_ + Vec2f(-Width_ / 2.0f, +Height_ / 2.0f);
	BoundPositions_[INDEX_RB] = Center_ + Vec2f(+Width_ / 2.0f, -Height_ / 2.0f);
	BoundPositions_[INDEX_RT] = Center_ + Vec2f(+Width_ / 2.0f, +Height_ / 2.0f);
}
