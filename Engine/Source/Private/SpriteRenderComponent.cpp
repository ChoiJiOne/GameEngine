#include "SpriteRenderComponent.h"
#include "AABBComponent.h"
#include "CircleComponent.h"
#include "OBBComponent.h"
#include "RenderManager.h"

SpriteRenderComponent::SpriteRenderComponent(GameObject* Object)
	: Component(Object)
{}

SpriteRenderComponent::SpriteRenderComponent(GameObject* Object, BoundComponent* Bound, const int32_t& SpriteTextureID)
	: Component(Object)
	, BoundComponent_(Bound)
	, SpriteTextureID_(SpriteTextureID)
{
}

SpriteRenderComponent::~SpriteRenderComponent()
{
}

void SpriteRenderComponent::AttachBoundComponent(BoundComponent* Bound)
{
	BoundComponent_ = Bound;
}

void SpriteRenderComponent::SetSpriteTextureID(const int32_t SpriteTextureID)
{
	SpriteTextureID_ = SpriteTextureID;
}

void SpriteRenderComponent::Tick()
{
	if (!CanRenderSprite())
	{
		return;
	}

	Vec2f Center;
	float Width = 0.0f, Height = 0.0f, Rotate = 0.0f;
	BoundComponent::EBoundaryShape BoundaryShape = BoundComponent_->GetBoundaryShape();

	if (BoundaryShape == BoundComponent::EBoundaryShape::AABB)
	{
		AABBComponent* ObjectComponent = reinterpret_cast<AABBComponent*>(BoundComponent_);

		Center = ObjectComponent->GetCenter();
		Width = ObjectComponent->GetWidth();
		Height = ObjectComponent->GetHeight();
	}
	else if (BoundaryShape == BoundComponent::EBoundaryShape::OBB)
	{
		OBBComponent* ObjectComponent = reinterpret_cast<OBBComponent*>(BoundComponent_);

		Center = ObjectComponent->GetCenter();
		Width = ObjectComponent->GetWidth();
		Height = ObjectComponent->GetHeight();
		Rotate = ObjectComponent->GetRotate();
	}
	else // BoundaryShape == BoundComponent::EBoundaryShape::CIRCLE
	{
		CircleComponent* ObjectComponent = reinterpret_cast<CircleComponent*>(BoundComponent_);

		Center = ObjectComponent->GetCenter();
		Width = 2.0f * ObjectComponent->GetRadius();
		Height = 2.0f * ObjectComponent->GetRadius();
	}

	RenderManager::Get().DrawSprite2D(SpriteTextureID_, Center, Width, Height, Rotate);
}

bool SpriteRenderComponent::CanRenderSprite()
{
	if (!BoundComponent_ || SpriteTextureID_ == -1)
	{
		return false;
	}

	BoundComponent::EBoundaryShape BoundaryShape = BoundComponent_->GetBoundaryShape();

	if (BoundaryShape == BoundComponent::EBoundaryShape::NONE)
	{
		return false;
	}

	return true;
}
