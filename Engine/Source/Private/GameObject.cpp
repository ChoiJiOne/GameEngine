#include "GameObject.h"
#include "Component.h"

GameObject::GameObject(const std::string& Signature)
	: Signature_(Signature)
{
}

GameObject::~GameObject()
{
	for (auto& OwnComponent : OwnComponents_)
	{
		OwnComponent.second.reset();
	}
}