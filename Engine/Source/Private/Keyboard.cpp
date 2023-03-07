#include "Keyboard.h"
#include "Utils.hpp"

Keyboard::Keyboard()
	: LastKeyboardState_(VIRTUAL_KEYS, 0)
	, CurrKeyboardState_(VIRTUAL_KEYS, 0) {}

void Keyboard::Tick()
{
	std::copy(CurrKeyboardState_.begin(), CurrKeyboardState_.end(), LastKeyboardState_.begin());
	CHECK(GetKeyboardState(&CurrKeyboardState_[0]), "failed to get keyboard state");

	for (auto& Action : KeyActions_)
	{
		KeyAction& CurrentAction = Action.second;

		if (GetKeyPressState(CurrentAction.VirtualKey) == CurrentAction.PressState)
		{
			CurrentAction.Action();
		}
	}
}

EKeyPressState Keyboard::GetKeyPressState(const EVirtualKey& VirtualKey) const
{
	EKeyPressState PressState = EKeyPressState::NONE;

	if (IsPressKey(LastKeyboardState_, VirtualKey))
	{
		if (IsPressKey(CurrKeyboardState_, VirtualKey))
		{
			PressState = EKeyPressState::HELD;
		}
		else
		{
			PressState = EKeyPressState::RELEASED;
		}
	}
	else
	{
		if (IsPressKey(CurrKeyboardState_, VirtualKey))
		{
			PressState = EKeyPressState::PRESSED;
		}
		else
		{
			PressState = EKeyPressState::NONE;
		}
	}

	return PressState;
}

void Keyboard::BindKeyAction(const std::string& Name, const KeyAction& Action)
{
	if (IsExistKey<std::string, KeyAction>(Name, KeyActions_))
	{
		return;
	}

	KeyActions_.insert({ Name, Action });
}

void Keyboard::UnbindKeyAction(const std::string& Name)
{
	if (!IsExistKey<std::string, KeyAction>(Name, KeyActions_))
	{
		return;
	}

	RemoveValue<std::string, KeyAction>(Name, KeyActions_);
}

bool Keyboard::IsPressKey(const std::vector<uint8_t>& KeyboardState, const EVirtualKey& VirtualKey) const
{
	return (KeyboardState[static_cast<int32_t>(VirtualKey)] & 0x80);
}