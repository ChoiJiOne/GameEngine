#pragma once

#include "Macro.h"
#include "Vector.hpp"

#include <windows.h>
#include <unordered_map>


/**
 * @brief 마우스의 가상 버튼의 코드 값입니다.
 */
enum class EVirtualButton
{
	CODE_LEFT  = 0x00,
	CODE_RIGHT = 0x01,
};


/**
 * @brief 마우스의 상태를 관리하는 클래스입니다.
 */
class Mouse
{
public:
	/**
	 * @brief 마우스의 상태를 관리하는 클래스의 생성자입니다.
	 * 
	 * @param WindowHandle 마우스의 상대 위치를 계산할 윈도우 창의 핸들입니다.
	 */
	Mouse(HWND WindowHandle);


	/**
	 * @brief 마우스의 상태를 관리하는 클래스의 가상 소멸자입니다.
	 */
	virtual ~Mouse() {}

	
	/**
	 * @brief 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Mouse);


	/**
	 * @brief 마우스의 상태를 업데이트합니다.
	 */
	void Tick();


	/**
	 * @brief 현재 마우스 위치를 얻습니다.
	 * 
	 * @return Tick 호출 이후의 마우스 위치를 반환합니다.
	 */
	Vec2i GetPosition() const;


	/**
	 * @brief Tick 호출 이후와 이전의 차이값을 얻습니다.
	 * 
	 * @return Tick 호출 이후와 이전의 차이값을 반환합니다.
	 */
	Vec2i GetDeltaPosition() const;


	/**
	 * @brief 마우스가 움직이는지 확인합니다.
	 * 
	 * @return 마우스가 움직인다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsMove() const { return bIsMove_; }


	/**
	 * @brief 마우스 버튼의 입력 상태를 얻습니다.
	 *
	 * @param VirtualButton 입력 상태를 얻을 마우스 버튼입니다.
	 *
	 * @return 마우스 버튼이 눌려있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool IsPressButton(EVirtualButton VirtualButton);


	/**
	 * @brief 마우스 버튼의 입력 상태를 설정합니다.
	 * 
	 * @note InputManager 외에는 반드시 호출하면 안돼는 메서드입니다.
	 * 
	 * @param VirtualButton 입력 상태를 설정할 마우스 버튼입니다.
	 * @param bIsPressed 마우스의 입력 상태입니다.
	 */
	void SetButtonPressState(EVirtualButton VirtualButton, bool bIsPressed);
	

private:
	/**
	 * @brief 현재 마우스의 위치를 얻습니다.
	 *
	 * @note 기준은 현재 윈도우 창입니다.
	 * 
	 * @return 모니터를 기준으로 현재 마우스의 (X, Y) 위치를 반환합니다.
	 */
	Vec2i GetCurrentPosition();


private:
	/**
	 * @brief 마우스 위치 계산을 위한 윈도우 핸들입니다.
	 */
	HWND WindowHandle_ = nullptr;


	/**
	 * @brief 마우스가 움직이는지 확인합니다.
	 */
	bool bIsMove_ = false;


	/**
	 * @brief 마우스가 눌렸는지 확인합니다.
	 */
	std::unordered_map<EVirtualButton, bool> ButtonPressState_;


	/**
	 * @brief 업데이트 이전(Tick 호출 이전)의 윈도우 기준 마우스 위치입니다.
	 */
	Vec2i LastWindowMousePosition_;


	/**
	 * @brief 업데이트 이전(Tick 호출 후)의 윈도우 기준 마우스 위치입니다.
	 */
	Vec2i CurrWindowMousePosition_;
};