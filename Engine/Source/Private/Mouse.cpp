#include "Mouse.h"

Mouse::Mouse(HWND WindowHandle)
	: WindowHandle_(WindowHandle)
{
	ButtonPressState_.insert({ EVirtualButton::CODE_LEFT, false });
	ButtonPressState_.insert({ EVirtualButton::CODE_RIGHT, false });
}

void Mouse::Tick()
{
	LastWindowMousePosition_ = CurrWindowMousePosition_;
	CurrWindowMousePosition_ = GetCurrentPosition();

	Vec2i DeltaPosition = GetDeltaPosition();
	bIsMove_ = !(DeltaPosition.x == 0 && DeltaPosition.y == 0);
}

Vec2i Mouse::GetPosition() const
{
	return CurrWindowMousePosition_;
}

Vec2i Mouse::GetDeltaPosition() const
{
	return CurrWindowMousePosition_ - LastWindowMousePosition_;
}

bool Mouse::IsPressButton(EVirtualButton VirtualButton)
{
	return ButtonPressState_[VirtualButton];
}

void Mouse::SetButtonPressState(EVirtualButton VirtualButton, bool bIsPressed)
{
	ButtonPressState_[VirtualButton] = bIsPressed;
}

Vec2i Mouse::GetCurrentPosition()
{
	POINT MousePosition;

	CHECK(GetCursorPos(&MousePosition), "failed to get current mouse position");
	CHECK(ScreenToClient(WindowHandle_, &MousePosition), "failed to convert mouse position");

	return Vec2i(static_cast<int32_t>(MousePosition.x), static_cast<int32_t>(MousePosition.y));
}