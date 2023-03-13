#include "AABBObject.h"
#include "BoundRenderComponent.h"
#include "InputComponent.h"
#include "AABBComponent.h"
#include "SpriteRenderComponent.h"

AABBObject::AABBObject(const std::string& Signature)
	: GameObject(Signature)
{
	InputComponent_ = CreateComponent<InputComponent>("InputComponent");
	BoundComponent_ = CreateComponent<AABBComponent>("AABBComponent", Vec2f(0.0f, 0.0f), 200.0f, 200.0f);
	RenderComponent_ = CreateComponent<BoundRenderComponent>("BoundRenderComponent", BoundComponent_, Color::RED);
	SpriteRenderComponent_ = CreateComponent<SpriteRenderComponent>("SpriteRenderComponent", BoundComponent_, 0);
}

void AABBObject::Tick(float DeltaSeconds)
{
	InputComponent_->Tick();
	SpriteRenderComponent_->Tick();
	RenderComponent_->Tick();
}