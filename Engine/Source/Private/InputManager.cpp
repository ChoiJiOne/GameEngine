#include "InputManager.h"
#include "Window.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Utils.hpp"

void InputManager::Setup(Window* MainWindow)
{
	WindowHandle_ = MainWindow->GetHandle();

	Keyboard_ = std::make_unique<Keyboard>();
	Mouse_ = std::make_unique<Mouse>(WindowHandle_);

	bIsSetup_ = true;
}

void InputManager::Cleanup()
{
	Mouse_.reset();
	Keyboard_.reset();

	bIsSetup_ = false;
}

LRESULT InputManager::ProcessWindowMessage(HWND WindowHandle, uint32_t Message, WPARAM WParam, LPARAM LParam)
{
	EWindowEvent WindowEvent = EWindowEvent::NONE;

	switch (Message)
	{
	case WM_ACTIVATE:
		WindowEvent = (LOWORD(WParam) == WA_INACTIVE) ? EWindowEvent::INACTIVE : EWindowEvent::ACTIVE;
		break;

	case WM_SIZE:
		switch (WParam)
		{
		case SIZE_MINIMIZED:
			WindowEvent = EWindowEvent::MINIMZED;
			break;

		case SIZE_MAXIMIZED:
			WindowEvent = EWindowEvent::MAXIMIZED;
			break;

		case SIZE_RESTORED:
			WindowEvent = EWindowEvent::RESIZE;
			break;

		case SIZE_MAXHIDE:
			WindowEvent = EWindowEvent::MAXHIDE;
			break;

		case SIZE_MAXSHOW:
			WindowEvent = EWindowEvent::MAXSHOW;
			break;

		default:
			ENFORCE_THROW_EXCEPTION("undefined WM_SIZE event");
		}
		break;

	case WM_ENTERSIZEMOVE:
		bIsResizing_ = true;
		WindowEvent = EWindowEvent::ENTERSIZEMOVE;
		break;

	case WM_EXITSIZEMOVE:
		bIsResizing_ = false;
		WindowEvent = EWindowEvent::EXITSIZEMOVE;
		break;

	case WM_LBUTTONDOWN:
		Mouse_->SetButtonPressState(EVirtualButton::CODE_LEFT, true);
		WindowEvent = EWindowEvent::LBUTTONDOWN;
		break;

	case WM_LBUTTONUP:
		Mouse_->SetButtonPressState(EVirtualButton::CODE_LEFT, false);
		WindowEvent = EWindowEvent::LBUTTONUP;
		break;

	case WM_RBUTTONDOWN:
		Mouse_->SetButtonPressState(EVirtualButton::CODE_RIGHT, true);
		WindowEvent = EWindowEvent::RBUTTONDOWN;
		break;

	case WM_RBUTTONUP:
		Mouse_->SetButtonPressState(EVirtualButton::CODE_RIGHT, false);
		WindowEvent = EWindowEvent::RBUTTONUP;
		break;

	case WM_MOUSEMOVE:
		WindowEvent = EWindowEvent::MOUSEMOVE;
		break;

	case WM_MOUSEHWHEEL:
		WindowEvent = (HIWORD(WParam) > 0) ? EWindowEvent::MOUSEWHEELUP : EWindowEvent::MOUSEWHEELDOWN;
		break;
	
	case WM_CLOSE:
		WindowEvent = EWindowEvent::CLOSE;
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(WindowHandle, Message, WParam, LParam);
	}

	HandleWindowEvent(WindowEvent);
	return 0;
}

void InputManager::BindWindowEvent(const EWindowEvent& WindowEvent, const std::function<void()>& EventCallback)
{
	WindowEvents_.insert({ WindowEvent, EventCallback });
}

void InputManager::UnbindWindowEvent(const EWindowEvent& WindowEvent)
{
	RemoveValue<EWindowEvent, std::function<void()>>(WindowEvent, WindowEvents_);
}

void InputManager::Tick()
{
	PollEventMessage();

	Keyboard_->Tick();
	Mouse_->Tick();
}

void InputManager::PollEventMessage()
{
	MSG EventMessage = {};

	while (PeekMessage(&EventMessage, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&EventMessage);
		DispatchMessage(&EventMessage);
	}
}

void InputManager::HandleWindowEvent(const EWindowEvent& WindowEvent)
{
	if (IsExistKey<EWindowEvent, std::function<void()>>(WindowEvent, WindowEvents_))
	{
		WindowEvents_.at(WindowEvent)();
	}
}