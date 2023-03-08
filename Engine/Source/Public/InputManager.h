#pragma once

#include "Macro.h"
#include "Vector.hpp"
#include "Keyboard.h"
#include "Mouse.h"

#include <cstdint>
#include <vector>
#include <functional>
#include <unordered_map>
#include <windows.h>

class Window;


/**
 * @brief �Է� ���¸� ��Ÿ���ϴ�.
 *
 * ----------------------------------------
 * | ���� ������ | ���� ������ | �Է� ����  |
 * ----------------------------------------
 * |     0      |     0      | NONE       |
 * |     0      |     1      | PRESSED    |
 * |     1      |     0      | RELEASED   |
 * |     1      |     1      | HELD       |
 * ----------------------------------------
 */
enum class EPressState
{
	NONE     = 0,
	PRESSED  = 1,
	RELEASED = 2,
	HELD     = 3
};


/**
 * @brief ������ �̺�Ʈ Ű ���Դϴ�.
 */
enum class EWindowEvent
{
	NONE           = 0,
	ACTIVE         = 1,
	INACTIVE       = 2,
	MINIMZED       = 3,
	MAXIMIZED      = 4,
	RESIZE         = 5,
	ENTERSIZEMOVE  = 6,
	EXITSIZEMOVE   = 7,
	LBUTTONDOWN    = 8,
	LBUTTONUP      = 9,
	RBUTTONDOWN    = 10,
	RBUTTONUP      = 11,
	MOUSEMOVE      = 12,
	CLOSE          = 13,
	MAXHIDE        = 14, /* https://learn.microsoft.com/ko-kr/windows/win32/winmsg/wm-size */
	MAXSHOW        = 15, /* https://learn.microsoft.com/ko-kr/windows/win32/winmsg/wm-size */
	MOUSEWHEELUP   = 16,
	MOUSEWHEELDOWN = 17,
};


/**
 * @brief �Է� ó�� �� Ű����, ���콺�� ���¸� �����մϴ�.
 * 
 * @note �� Ŭ������ �̱������� ����� �߰��ϸ� �ٷ� ����� �� �ֽ��ϴ�.
 */
class InputManager
{
public:
	/**
	 * @brief ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(InputManager);


	/**
	 * @brief InputManager�� �ν��Ͻ��� ����ϴ�.
	 * 
	 * @return InputManager�� �ν��Ͻ� �����ڸ� ��ȯ�մϴ�.
	 */
	static InputManager& Get()
	{
		static InputManager Instance;
		return Instance;
	}


	/**
	 * @brief InutManager�� ��������� �ʱ�ȭ�մϴ�.
	 * 
	 * @param MainWindow �Է� ó�� ����� �Ǵ� ���� �������Դϴ�.
	 * 
	 * @thorws �ʱ�ȭ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void Setup(Window* MainWindow);


	/**
	 * @brief InputManager�� ���θ� ��������� �����մϴ�.
	 */
	void Cleanup();


	/**
	 * @brief ������ �޽��� �ڵ鷯�Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/learnwin32/writing-the-window-procedure
	 *
	 * @param WindowHandle ������ â�� ���� �ڵ��Դϴ�.
	 * @param Message ������ �޽��� �ڵ��Դϴ�.
	 * @param WParam ������ �޽����� �߰� �������Դϴ�.
	 * @param LParam ������ �޽����� �߰� �������Դϴ�.
	 *
	 * @return �����쿡 ��ȯ�� ���Դϴ�.
	 */
	LRESULT ProcessWindowMessage(HWND WindowHandle, uint32_t Message, WPARAM WParam, LPARAM LParam);


	/**
	 * @brief ������ �̺�Ʈ�� �����ϴ� �ݹ��� ���ε��մϴ�.
	 * 
	 * @note �̺�Ʈ�� �����ϴ� ���� ��ƾ�� �����մϴ�. ���ο� ��ƾ�� �����Ϸ��� �ٽ� ����ؾ� �մϴ�.
	 * 
	 * @param WindowEvent ����� ������ �̺�Ʈ �����Դϴ�.
	 * @param EventCallback �̺�Ʈ ���� �� ������ ��ƾ�Դϴ�.
	 */
	void BindWindowEvent(const EWindowEvent& WindowEvent, const std::function<void()>& EventCallback);


	/**
	 * @brief ������ �̺�Ʈ�� ���ε� �����մϴ�.
	 * 
	 * @param WindowEvent ���ε� ������ ������ �̺�Ʈ�Դϴ�.
	 */
	void UnbindWindowEvent(const EWindowEvent& WindowEvent);


	/**
	 * @brief �Է� ���¸� ������Ʈ�մϴ�.
	 * 
	 * @note �� �޼���� �� ������ ȣ���ؾ� �մϴ�.
	 */
	void Tick();


	/**
	 * @brief InputManager�� �����ϴ� Ű���带 ����ϴ�.
	 * 
	 * @return InputManager�� �����ϴ� Ű������ ��� �����ڸ� ��ȯ�մϴ�.
	 */
	const Keyboard& GetKeyboard() const { return *Keyboard_.get(); }


	/**
	 * @brief InputManager�� �����ϴ� Ű���带 ����ϴ�.
	 *
	 * @return InputManager�� �����ϴ� Ű������ �����ڸ� ��ȯ�մϴ�.
	 */
	Keyboard& GetKeyboard() { return *Keyboard_.get(); }


	/**
	 * @brief InputManager�� �����ϴ� ���콺�� ����ϴ�.
	 * 
	 * return InputManager�� �����ϴ� Ű������ ��� �����ڸ� ��ȯ�մϴ�.
	 */
	const Mouse& GetMouse() const { return *Mouse_.get(); }


	/**
	 * @brief InputManager�� �����ϴ� ���콺�� ����ϴ�.
	 *
	 * return InputManager�� �����ϴ� Ű������ �����ڸ� ��ȯ�մϴ�.
	 */
	Mouse& GetMouse() { return *Mouse_.get(); }


private:
	/**
	 * @brief �Է� ó���� �����ϴ� Ŭ������ �������Դϴ�.
	 */
	InputManager() = default;


	/**
	 * @brief �Է� ó���� �����ϴ� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~InputManager() = default;


	/**
	 * @brief �̺�Ʈ ť�� ������ �̺�Ʈ�� ó���մϴ�.
	 */
	void PollEventMessage();


	/**
	 * @brief ������ �̺�Ʈ�� �����ϴ� ��ƾ�� �����մϴ�.
	 *
	 * @param WindowEvent ������ ������ �̺�Ʈ�Դϴ�.
	 */
	void HandleWindowEvent(const EWindowEvent& WindowEvent);


private:
	/**
	 * @brief �ʱ�ȭ �� ���� �ִ��� Ȯ���մϴ�.
	 */
	bool bIsSetup_ = false;


	/**
	 * @brief �̺�Ʈ ó�� ����� �Ǵ� ������ �ڵ��Դϴ�.
	 */
	HWND WindowHandle_ = nullptr;


	/**
	 * @brief ������ â�� ũ�Ⱑ ���� ������ Ȯ���մϴ�.
	 */
	bool bIsResizing_ = false;


	/**
	 * @brief InputManager�� �����ϴ� Ű���� �����Դϴ�.
	 */
	std::unique_ptr<Keyboard> Keyboard_ = nullptr;


	/**
	 * @brief InputManager�� �����ϴ� ���콺 �����Դϴ�.
	 */
	std::unique_ptr<Mouse> Mouse_ = nullptr;


	/**
	 * @brief ������ �̺�Ʈ Ű ���� �����ϴ� �̺�Ʈ�Դϴ�.
	 */
	std::unordered_map<EWindowEvent, std::function<void()>> WindowEvents_;
};