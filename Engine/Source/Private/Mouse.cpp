#include "Mouse.h"

Mouse::Mouse(HWND WindowHandle)
	: WindowHandle_(WindowHandle)
{
}

void Mouse::Tick()
{
	LastScreenMousePosition_ = CurrScreenMousePosition_;
	LastWindowMousePosition_ = CurrWindowMousePosition_;

	CurrScreenMousePosition_ = GetPositionFromScreen();
	CurrWindowMousePosition_ = GetPositionFromWindow();
}

Vec2i Mouse::GetLastPosition(const EPositionType& PositionType)
{
	Vec2i LastPosition;

	switch (PositionType)
	{
	case EPositionType::WINDOW:
		LastPosition = LastWindowMousePosition_;
		break;

	case EPositionType::SCREEN:
		LastPosition = LastScreenMousePosition_;
		break;

	default:
		ENFORCE_THROW_EXCEPTION("undefine position type...");
		break;
	}

	return LastPosition;
}

Vec2i Mouse::GetCurrPosition(const EPositionType& PositionType)
{
	Vec2i CurrPosition;

	switch (PositionType)
	{
	case EPositionType::WINDOW:
		CurrPosition = CurrWindowMousePosition_;
		break;

	case EPositionType::SCREEN:
		CurrPosition = CurrScreenMousePosition_;
		break;

	default:
		ENFORCE_THROW_EXCEPTION("undefine position type...");
		break;
	}

	return CurrPosition;
}

Vec2i Mouse::GetDeltaPosition(const EPositionType& PositionType)
{
	Vec2i DeltaPosition;

	switch (PositionType)
	{
	case EPositionType::WINDOW:
		DeltaPosition = CurrWindowMousePosition_ - LastWindowMousePosition_;
		break;

	case EPositionType::SCREEN:
		DeltaPosition = CurrScreenMousePosition_ - LastScreenMousePosition_;
		break;

	default:
		ENFORCE_THROW_EXCEPTION("undefine position type...");
		break;
	}

	return DeltaPosition;
}

Vec2i Mouse::GetPositionFromScreen()
{
	POINT MousePosition;
	CHECK(GetCursorPos(&MousePosition), "failed to get current mouse position");

	return Vec2i(static_cast<int32_t>(MousePosition.x), static_cast<int32_t>(MousePosition.y));
}

Vec2i Mouse::GetPositionFromWindow()
{
	POINT MousePosition;

	CHECK(GetCursorPos(&MousePosition), "failed to get current mouse position");
	CHECK(ScreenToClient(WindowHandle_, &MousePosition), "failed to convert mouse position");

	return Vec2i(static_cast<int32_t>(MousePosition.x), static_cast<int32_t>(MousePosition.y));
}