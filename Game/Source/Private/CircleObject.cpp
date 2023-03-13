#include "CircleObject.h"
#include "BoundRenderComponent.h"
#include "CircleComponent.h"
#include "InputComponent.h"

CircleObject::CircleObject(const std::string& Signature)
	: GameObject(Signature)
{
	InputComponent_ = CreateComponent<InputComponent>("InputComponent");
	BoundComponent_ = CreateComponent<CircleComponent>("CircleComponent", Vec2f(0.0f, 0.0f), 100.0f);
	RenderComponent_ = CreateComponent<BoundRenderComponent>("BoundRenderComponent", BoundComponent_, Color::BLUE);
}

void CircleObject::Tick(float DeltaSeconds)
{
	InputComponent_->Tick();
	RenderComponent_->Tick();
}