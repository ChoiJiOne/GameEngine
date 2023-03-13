#include "Object.h"
#include "InputComponent.h"
#include "AABBComponent.h"
#include "CircleComponent.h"
#include "RenderManager.h"

Object::Object(const std::string& Signature)
	: GameObject(Signature)
{
	InputComponent* ObjectInputComponent = CreateComponent<InputComponent>("InputComponent");
	CreateComponent<AABBComponent>("BoundComponent", Vec2f(0.0f, 0.0f), 200.0f, 200.0f);
	CreateComponent<CircleComponent>("CircleComponent", Vec2f(0.0f, 0.0f), 100.0f);

	ObjectInputComponent->BindKeyAction(
		"LEFT",
		KeyAction{
			EVirtualKey::CODE_LEFT,
			EPressState::PRESSED,
			[&] {
				AABBComponent* ObjectBoundComponent = GetComponent<AABBComponent>("BoundComponent");
				Vec2f Center = ObjectBoundComponent->GetCenter();
				Center.x -= 10;
				ObjectBoundComponent->SetCenter(Center);
			}
		}
	);

	ObjectInputComponent->BindKeyAction(
		"RIGHT",
		KeyAction{
			EVirtualKey::CODE_RIGHT,
			EPressState::PRESSED,
			[&] {
				AABBComponent* ObjectBoundComponent = GetComponent<AABBComponent>("BoundComponent");
				Vec2f Center = ObjectBoundComponent->GetCenter();
				Center.x += 10;
				ObjectBoundComponent->SetCenter(Center);
			}
		}
	);
}

void Object::Tick(float DeltaSeconds)
{
	GetComponent<InputComponent>("InputComponent")->Tick();

	AABBComponent* ObjectBoundComponent = GetComponent<AABBComponent>("BoundComponent");

	RenderManager::Get().DrawWireframeQuad2D(
		ObjectBoundComponent->GetCenter(),
		Color::RED,
		ObjectBoundComponent->GetWidth(),
		ObjectBoundComponent->GetHeight()
	);

	RenderManager::Get().DrawWireframeCircle(
		GetComponent<CircleComponent>("CircleComponent")->GetCenter(),
		Color::BLUE,
		GetComponent<CircleComponent>("CircleComponent")->GetRadius()
	);
}