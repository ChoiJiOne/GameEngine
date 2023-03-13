#include "Object.h"
#include "InputComponent.h"
#include "RenderManager.h"

Object::Object(const std::string& Signature)
	: GameObject(Signature)
{
	InputComponent* ObjectInputComponent = CreateComponent<InputComponent>("InputComponent");
	ObjectInputComponent->BindKeyAction(
		"ENTER",
		KeyAction{
			EVirtualKey::CODE_RETURN,
			EPressState::PRESSED,
			[&] {
				RenderManager::Get().DrawText2D(0, L"Hello World!", Vec2f(0.0f, 0.0f), Color::RED);
			}
		}
	);

	ObjectInputComponent->BindKeyAction(
		"LEFT",
		KeyAction{
			EVirtualKey::CODE_LEFT,
			EPressState::PRESSED,
			[&] {
				Position.x -= 10;
			}
		}
	);

	ObjectInputComponent->BindKeyAction(
		"RIGHT",
		KeyAction{
			EVirtualKey::CODE_RIGHT,
			EPressState::PRESSED,
			[&] {
				Position.x += 10;
			}
		}
	);
}

void Object::Tick(float DeltaSeconds)
{
	GetComponent<InputComponent>("InputComponent")->Tick();

	RenderManager::Get().DrawSprite2D(0, Position, 100.0f, 100.0f);
}