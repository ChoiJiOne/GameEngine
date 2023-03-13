#include "InputComponent.h"
#include "Utils.hpp"

void InputComponent::Tick()
{
	for (auto& Action : KeyActions_)
	{
		KeyAction& CurrentAction = Action.second;

		if (InputManager::Get().GetKeyPressState(CurrentAction.VirtualKey) == CurrentAction.PressState)
		{
			CurrentAction.Action();
		}
	}

	for (auto& Action : EventActions_)
	{
		EventAction& CurrentAction = Action.second;

		if (CurrentAction.Condition())
		{
			CurrentAction.Action();
		}
	}
}

void InputComponent::BindKeyAction(const std::string& Name, const KeyAction& Action)
{
	if (IsExistKey<std::string, KeyAction>(Name, KeyActions_))
	{
		return;
	}

	KeyActions_.insert({ Name, Action });
}

void InputComponent::BindEventAction(const std::string& Name, const EventAction& Action)
{
	if (IsExistKey<std::string, EventAction>(Name, EventActions_))
	{
		return;
	}

	EventActions_.insert({ Name, Action });
}

void InputComponent::UnbindKeyAction(const std::string& Name)
{
	if (!IsExistKey<std::string, KeyAction>(Name, KeyActions_))
	{
		return;
	}

	RemoveValue<std::string, KeyAction>(Name, KeyActions_);
}

void InputComponent::UnbindEventAction(const std::string& Name)
{
	if (!IsExistKey<std::string, EventAction>(Name, EventActions_))
	{
		return;
	}

	RemoveValue<std::string, EventAction>(Name, EventActions_);
}
