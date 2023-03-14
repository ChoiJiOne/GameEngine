#include "CollisionComponent.h"
#include "AABBComponent.h"
#include "CircleComponent.h"
#include "OBBComponent.h"

CollisionComponent::CollisionComponent(GameObject* Object)
	: Component(Object)
{
}

CollisionComponent::CollisionComponent(GameObject* Object, BoundComponent* Bound)
	: Component(Object)
	, BoundComponent_(Bound)
{}

CollisionComponent::~CollisionComponent()
{
}

void CollisionComponent::AttachBoundComponent(BoundComponent* Bound)
{
	BoundComponent_ = Bound;
}

bool CollisionComponent::IsDetectCollision(BoundComponent* TargetBound)
{
	if (!CanDetectCollision(TargetBound))
	{
		return false;
	}

	BoundComponent::EBoundaryShape BoundaryShape = BoundComponent_->GetBoundaryShape();
	BoundComponent::EBoundaryShape TargetBoundaryShape = TargetBound->GetBoundaryShape();

	bool bIsDetectCollision = false;

	if (BoundaryShape == BoundComponent::EBoundaryShape::AABB)
	{
		AABBComponent* LhsBoundComponent = reinterpret_cast<AABBComponent*>(BoundComponent_);

		if (TargetBoundaryShape == BoundComponent::EBoundaryShape::AABB)
		{
			AABBComponent* RhsBoundComponent = reinterpret_cast<AABBComponent*>(TargetBound);
			bIsDetectCollision = IsDetectCollisionAABBAndAABB(LhsBoundComponent, RhsBoundComponent);
		}
		else if (TargetBoundaryShape == BoundComponent::EBoundaryShape::OBB)
		{
			OBBComponent* RhsBoundComponent = reinterpret_cast<OBBComponent*>(TargetBound);
			bIsDetectCollision = IsDetectCollisionAABBAndOBB(LhsBoundComponent, RhsBoundComponent);
		}
		else // TargetBoundaryShape == BoundComponent::EBoundaryShape::CIRCLE
		{
			CircleComponent* RhsBoundComponent = reinterpret_cast<CircleComponent*>(TargetBound);
			bIsDetectCollision = IsDetectCollisionAABBAndCIRCLE(LhsBoundComponent, RhsBoundComponent);
		}
	}
	else if (BoundaryShape == BoundComponent::EBoundaryShape::OBB)
	{
		OBBComponent* LhsBoundComponent = reinterpret_cast<OBBComponent*>(BoundComponent_);

		if (TargetBoundaryShape == BoundComponent::EBoundaryShape::AABB)
		{
			AABBComponent* RhsBoundComponent = reinterpret_cast<AABBComponent*>(TargetBound);
			bIsDetectCollision = IsDetectCollisionOBBAndAABB(LhsBoundComponent, RhsBoundComponent);
		}
		else if (TargetBoundaryShape == BoundComponent::EBoundaryShape::OBB)
		{
			OBBComponent* RhsBoundComponent = reinterpret_cast<OBBComponent*>(TargetBound);
			bIsDetectCollision = IsDetectCollisionOBBAndOBB(LhsBoundComponent, RhsBoundComponent);
		}
		else // TargetBoundaryShape == BoundComponent::EBoundaryShape::CIRCLE
		{
			CircleComponent* RhsBoundComponent = reinterpret_cast<CircleComponent*>(TargetBound);
			bIsDetectCollision = IsDetectCollisionOBBAndCIRCLE(LhsBoundComponent, RhsBoundComponent);
		}
	}
	else // BoundaryShape == BoundComponent::EBoundaryShape::CIRCLE
	{
		CircleComponent* LhsBoundComponent = reinterpret_cast<CircleComponent*>(BoundComponent_);

		if (TargetBoundaryShape == BoundComponent::EBoundaryShape::AABB)
		{
			AABBComponent* RhsBoundComponent = reinterpret_cast<AABBComponent*>(TargetBound);
			bIsDetectCollision = IsDetectCollisionCIRCLEAndAABB(LhsBoundComponent, RhsBoundComponent);
		}
		else if (TargetBoundaryShape == BoundComponent::EBoundaryShape::OBB)
		{
			OBBComponent* RhsBoundComponent = reinterpret_cast<OBBComponent*>(TargetBound);
			bIsDetectCollision = IsDetectCollisionCIRCLEAndOBB(LhsBoundComponent, RhsBoundComponent);
		}
		else // TargetBoundaryShape == BoundComponent::EBoundaryShape::CIRCLE
		{
			CircleComponent* RhsBoundComponent = reinterpret_cast<CircleComponent*>(TargetBound);
			bIsDetectCollision = IsDetectCollisionCIRCLEAndCIRCLE(LhsBoundComponent, RhsBoundComponent);
		}
	}
	
	return bIsDetectCollision;
}

bool CollisionComponent::CanDetectCollision(BoundComponent* TargetBound) const
{
	if (!BoundComponent_ || !TargetBound)
	{
		return false;
	}

	BoundComponent::EBoundaryShape BoundaryShape = BoundComponent_->GetBoundaryShape();
	BoundComponent::EBoundaryShape TargetBoundaryShape = TargetBound->GetBoundaryShape();

	if (BoundaryShape == BoundComponent::EBoundaryShape::NONE || TargetBoundaryShape == BoundComponent::EBoundaryShape::NONE)
	{
		return false;
	}

	return true;
}

bool CollisionComponent::IsDetectCollisionAABBAndAABB(AABBComponent* LhsBoundComponent, AABBComponent* RhsBoundComponent)
{
	return false;
}

bool CollisionComponent::IsDetectCollisionAABBAndOBB(AABBComponent* LhsBoundComponent, OBBComponent* RhsBoundComponent)
{
	return false;
}

bool CollisionComponent::IsDetectCollisionAABBAndCIRCLE(AABBComponent* LhsBoundComponent, CircleComponent* RhsBoundComponent)
{
	return false;
}

bool CollisionComponent::IsDetectCollisionOBBAndAABB(OBBComponent* LhsBoundComponent, AABBComponent* RhsBoundComponent)
{
	return false;
}

bool CollisionComponent::IsDetectCollisionOBBAndOBB(OBBComponent* LhsBoundComponent, OBBComponent* RhsBoundComponent)
{
	return false;
}

bool CollisionComponent::IsDetectCollisionOBBAndCIRCLE(OBBComponent* LhsBoundComponent, CircleComponent* RhsBoundComponent)
{
	return false;
}

bool CollisionComponent::IsDetectCollisionCIRCLEAndAABB(CircleComponent* LhsBoundComponent, AABBComponent* RhsBoundComponent)
{
	return false;
}

bool CollisionComponent::IsDetectCollisionCIRCLEAndOBB(CircleComponent* LhsBoundComponent, OBBComponent* RhsBoundComponent)
{
	return false;
}

bool CollisionComponent::IsDetectCollisionCIRCLEAndCIRCLE(CircleComponent* LhsBoundComponent, CircleComponent* RhsBoundComponent)
{
	return false;
}
