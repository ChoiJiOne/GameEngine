#include "BoundRenderComponent.h"
#include "AABBComponent.h"
#include "BoundComponent.h"
#include "CircleComponent.h"
#include "OBBComponent.h"
#include "RenderManager.h"

BoundRenderComponent::BoundRenderComponent(GameObject* Object)
	: Component(Object)
{}

BoundRenderComponent::BoundRenderComponent(GameObject* Object, BoundComponent* Bound, const LinearColor& BoundColor)
	: Component(Object)
	, BoundComponent_(Bound)
	, BoundColor_(BoundColor)
{}

BoundRenderComponent::~BoundRenderComponent()
{
}

void BoundRenderComponent::AttachBoundComponent(BoundComponent* Bound)
{
	BoundComponent_ = Bound;
}

void BoundRenderComponent::Tick()
{
	if (!BoundComponent_)
	{
		return;
	}

	BoundComponent::EBoundaryShape BoundaryShape = BoundComponent_->GetBoundaryShape();

	if (BoundaryShape == BoundComponent::EBoundaryShape::NONE)
	{
		return;
	}

	if (BoundaryShape == BoundComponent::EBoundaryShape::AABB)
	{
		AABBComponent* ObjectComponent = reinterpret_cast<AABBComponent*>(BoundComponent_);

		RenderManager::Get().DrawWireframeQuad2D(
			ObjectComponent->GetCenter(),
			BoundColor_,
			ObjectComponent->GetWidth(),
			ObjectComponent->GetHeight()
		);
	}
	else if (BoundaryShape == BoundComponent::EBoundaryShape::OBB)
	{
		OBBComponent* ObjectComponent = reinterpret_cast<OBBComponent*>(BoundComponent_);

		RenderManager::Get().DrawWireframeQuad2D(
			ObjectComponent->GetCenter(),
			BoundColor_,
			ObjectComponent->GetWidth(),
			ObjectComponent->GetHeight(),
			ObjectComponent->GetRotate()
		);
	}
	else // BoundaryShape == BoundComponent::EBoundaryShape::CIRCLE
	{
		CircleComponent* ObjectComponent = reinterpret_cast<CircleComponent*>(BoundComponent_);

		RenderManager::Get().DrawWireframeCircle(
			ObjectComponent->GetCenter(),
			BoundColor_,
			ObjectComponent->GetRadius()
		);
	}
}
