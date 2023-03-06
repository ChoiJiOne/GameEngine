#include "Keyboard.h"

Keyboard::Keyboard()
	: LastKeyboardState_(VIRTUAL_KEYS, 0)
	, CurrKeyboardState_(VIRTUAL_KEYS, 0) {}

void Keyboard::Tick()
{
	std::copy(CurrKeyboardState_.begin(), CurrKeyboardState_.end(), LastKeyboardState_.begin());
	CHECK(GetKeyboardState(&CurrKeyboardState_[0]), "failed to get keyboard state");
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

bool Keyboard::IsPressKey(const std::vector<uint8_t>& KeyboardState, const EVirtualKey& VirtualKey) const
{
	return (KeyboardState[static_cast<int32_t>(VirtualKey)] & 0x80);
}