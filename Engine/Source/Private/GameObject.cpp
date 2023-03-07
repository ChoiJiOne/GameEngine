#include "GameObject.h"
#include "Component.h"

GameObject::GameObject(const std::string& Signature)
	: Signature_(Signature)
{
}

GameObject::~GameObject()
{
	for (auto& OwnComponent : Components_)
	{
		OwnComponent.second.reset();
	}
}