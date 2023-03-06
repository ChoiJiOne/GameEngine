#pragma once

#include <Windows.h>

#include "Macro.h"
#include "Vector.hpp"


/**
 * @brief 마우스의 상태를 관리하는 클래스입니다.
 */
class Mouse
{
public:
	/**
	 * @brief 마우스 위치의 타입입니다.
	 */
	enum class EPositionType : int32_t
	{
		SCREEN = 0,
		WINDOW = 1
	};


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
	 * @brief Tick 호출 이전의 마우스 위치를 얻습니다.
	 * 
	 * @param PositionType 마우스 위치의 종류입니다.
	 * 
	 * @return Tick 호출 이전의 마우스 위치를 반환합니다.
	 */
	Vec2i GetLastPosition(const EPositionType& PositionType) const;


	/**
	 * @brief Tick 호출 이후의 마우스 위치를 얻습니다.
	 * 
	 * @param PositionType 마우스 위치의 종류입니다.
	 * 
	 * @return Tick 호출 이후의 마우스 위치를 반환합니다.
	 */
	Vec2i GetCurrPosition(const EPositionType& PositionType) const;


	/**
	 * @brief Tick 호출 이후와 이전의 차이값을 얻습니다.
	 * 
	 * @param PositionType 마우스 위치의 종류입니다.
	 * 
	 * @return Tick 호출 이후와 이전의 차이값을 반환합니다.
	 */
	Vec2i GetDeltaPosition(const EPositionType& PositionType) const;


private:
	/**
	 * @brief 모니터를 기준으로 현재 마우스의 위치를 얻습니다.
	 *
	 * @return 모니터를 기준으로 현재 마우스의 (X, Y) 위치를 반환합니다.
	 */
	Vec2i GetPositionFromScreen();


	/**
	 * @brief 윈도우를 기준으로 현재 마우스의 위치를 얻습니다.
	 *
	 * @see https://stackoverflow.com/questions/6423729/get-current-cursor-position
	 *
	 * @return 윈도우를 기준으로 현재 마우스의 (X, Y) 위치를 반환합니다.
	 */
	Vec2i GetPositionFromWindow();


private:
	/**
	 * @brief 마우스 위치 계산을 위한 윈도우 핸들입니다.
	 */
	HWND WindowHandle_ = nullptr;


	/**
	 * @brief 업데이트 이전(Tick 호출 이전)의 화면 기준 마우스 위치입니다.
	 */
	Vec2i LastScreenMousePosition_;


	/**
	 * @brief 업데이트 이전(Tick 호출 이전)의 윈도우 기준 마우스 위치입니다.
	 */
	Vec2i LastWindowMousePosition_;


	/**
	 * @brief 업데이트 후(Tick 호출 후)의 화면 기준 마우스 위치입니다.
	 */
	Vec2i CurrScreenMousePosition_;


	/**
	 * @brief 업데이트 이전(Tick 호출 후)의 윈도우 기준 마우스 위치입니다.
	 */
	Vec2i CurrWindowMousePosition_;
};