#include "CircleComponent.h"

CircleComponent::CircleComponent(GameObject* Object)
	: BoundComponent(Object, BoundComponent::EBoundaryShape::CIRCLE)
{}

CircleComponent::CircleComponent(GameObject* Object, const Vec2f& Center, const float& Radius)
	: BoundComponent(Object, BoundComponent::EBoundaryShape::CIRCLE)
	, Center_(Center)
	, Radius_(Radius)
{}

CircleComponent::~CircleComponent()
{}