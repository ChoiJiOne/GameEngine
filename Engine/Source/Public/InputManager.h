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
 * @brief 입력 상태를 나타냅니다.
 *
 * ----------------------------------------
 * | 이전 프레임 | 현재 프레임 | 입력 상태  |
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
 * @brief 윈도우 이벤트 키 값입니다.
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
 * @brief 입력 처리 및 키보드, 마우스의 상태를 관리합니다.
 * 
 * @note 이 클래스는 싱글턴으로 헤더만 추가하면 바로 사용할 수 있습니다.
 */
class InputManager
{
public:
	/**
	 * @brief 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(InputManager);


	/**
	 * @brief InputManager의 인스턴스를 얻습니다.
	 * 
	 * @return InputManager의 인스턴스 참조자를 반환합니다.
	 */
	static InputManager& Get()
	{
		static InputManager Instance;
		return Instance;
	}


	/**
	 * @brief InutManager를 명시적으로 초기화합니다.
	 * 
	 * @param MainWindow 입력 처리 대상이 되는 메인 윈도우입니다.
	 * 
	 * @thorws 초기화에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void Setup(Window* MainWindow);


	/**
	 * @brief InputManager의 내부를 명시적으로 정리합니다.
	 */
	void Cleanup();


	/**
	 * @brief 윈도우 메시지 핸들러입니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/learnwin32/writing-the-window-procedure
	 *
	 * @param WindowHandle 윈도우 창에 대한 핸들입니다.
	 * @param Message 윈도우 메시지 코드입니다.
	 * @param WParam 윈도우 메시지의 추가 데이터입니다.
	 * @param LParam 윈도우 메시지의 추가 데이터입니다.
	 *
	 * @return 윈도우에 반환할 값입니다.
	 */
	LRESULT ProcessWindowMessage(HWND WindowHandle, uint32_t Message, WPARAM WParam, LPARAM LParam);


	/**
	 * @brief 윈도우 이벤트에 대응하는 콜백을 바인딩합니다.
	 * 
	 * @note 이벤트에 대응하는 실행 루틴은 유일합니다. 새로운 루틴을 실행하려면 다시 등록해야 합니다.
	 * 
	 * @param WindowEvent 등록할 윈도우 이벤트 종류입니다.
	 * @param EventCallback 이벤트 감지 시 실행할 루틴입니다.
	 */
	void BindWindowEvent(const EWindowEvent& WindowEvent, const std::function<void()>& EventCallback);


	/**
	 * @brief 윈도우 이벤트를 바인딩 해제합니다.
	 * 
	 * @param WindowEvent 바인딩 해제할 윈도우 이벤트입니다.
	 */
	void UnbindWindowEvent(const EWindowEvent& WindowEvent);


	/**
	 * @brief 입력 상태를 업데이트합니다.
	 * 
	 * @note 이 메서드는 매 프레임 호출해야 합니다.
	 */
	void Tick();


	/**
	 * @brief InputManager가 관리하는 키보드를 얻습니다.
	 * 
	 * @return InputManager가 관리하는 키보드의 상수 참조자를 반환합니다.
	 */
	const Keyboard& GetKeyboard() const { return *Keyboard_.get(); }


	/**
	 * @brief InputManager가 관리하는 키보드를 얻습니다.
	 *
	 * @return InputManager가 관리하는 키보드의 참조자를 반환합니다.
	 */
	Keyboard& GetKeyboard() { return *Keyboard_.get(); }


	/**
	 * @brief InputManager가 관리하는 마우스를 얻습니다.
	 * 
	 * return InputManager가 관리하는 키보드의 상수 참조자를 반환합니다.
	 */
	const Mouse& GetMouse() const { return *Mouse_.get(); }


	/**
	 * @brief InputManager가 관리하는 마우스를 얻습니다.
	 *
	 * return InputManager가 관리하는 키보드의 참조자를 반환합니다.
	 */
	Mouse& GetMouse() { return *Mouse_.get(); }


private:
	/**
	 * @brief 입력 처리를 수행하는 클래스의 생성자입니다.
	 */
	InputManager() = default;


	/**
	 * @brief 입력 처리를 수행하는 클래스의 가상 소멸자입니다.
	 */
	virtual ~InputManager() = default;


	/**
	 * @brief 이벤트 큐의 윈도우 이벤트를 처리합니다.
	 */
	void PollEventMessage();


	/**
	 * @brief 윈도우 이벤트에 대응하는 루틴을 실행합니다.
	 *
	 * @param WindowEvent 실행할 윈도우 이벤트입니다.
	 */
	void HandleWindowEvent(const EWindowEvent& WindowEvent);


private:
	/**
	 * @brief 초기화 된 적이 있는지 확인합니다.
	 */
	bool bIsSetup_ = false;


	/**
	 * @brief 이벤트 처리 대상이 되는 윈도우 핸들입니다.
	 */
	HWND WindowHandle_ = nullptr;


	/**
	 * @brief 윈도우 창의 크기가 변경 중인지 확인합니다.
	 */
	bool bIsResizing_ = false;


	/**
	 * @brief InputManager가 관리하는 키보드 상태입니다.
	 */
	std::unique_ptr<Keyboard> Keyboard_ = nullptr;


	/**
	 * @brief InputManager가 관리하는 마우스 상태입니다.
	 */
	std::unique_ptr<Mouse> Mouse_ = nullptr;


	/**
	 * @brief 윈도우 이벤트 키 값에 대응하는 이벤트입니다.
	 */
	std::unordered_map<EWindowEvent, std::function<void()>> WindowEvents_;
};