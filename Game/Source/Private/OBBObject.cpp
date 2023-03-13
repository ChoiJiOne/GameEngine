#include "OBBObject.h"
#include "BoundRenderComponent.h"
#include "InputComponent.h"
#include "OBBComponent.h"
#include "RenderManager.h"

OBBObject::OBBObject(const std::string& Signature)
	: GameObject(Signature)
{
	InputComponent_ = CreateComponent<InputComponent>("InputComponent");
	BoundComponent_ = CreateComponent<OBBComponent>("OBBComponent", Vec2f(0.0f, 0.0f), 200.0f, 200.0f, 45.0f);
	RenderComponent_ = CreateComponent<BoundRenderComponent>("BoundRenderComponent", BoundComponent_, Color::GREEN);
}

void OBBObject::Tick(float DeltaSeconds)
{
	InputComponent_->Tick();
	RenderComponent_->Tick();

	RenderManager::Get().DrawLine2D(
		Vec2f(-200.0f, -200.0f), Color::RED,
		Vec2f(+200.0f, +200.0f), Color::RED
	);
}