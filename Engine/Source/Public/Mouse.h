#pragma once

#include <Windows.h>

#include "Macro.h"
#include "Vector.hpp"


/**
 * @brief ���콺�� ���¸� �����ϴ� Ŭ�����Դϴ�.
 */
class Mouse
{
public:
	/**
	 * @brief ���콺 ��ġ�� Ÿ���Դϴ�.
	 */
	enum class EPositionType : int32_t
	{
		SCREEN = 0,
		WINDOW = 1
	};


public:
	/**
	 * @brief ���콺�� ���¸� �����ϴ� Ŭ������ �������Դϴ�.
	 * 
	 * @param WindowHandle ���콺�� ��� ��ġ�� ����� ������ â�� �ڵ��Դϴ�.
	 */
	Mouse(HWND WindowHandle);


	/**
	 * @brief ���콺�� ���¸� �����ϴ� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Mouse() {}

	
	/**
	 * @brief ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Mouse);


	/**
	 * @brief ���콺�� ���¸� ������Ʈ�մϴ�.
	 */
	void Tick();


	/**
	 * @brief Tick ȣ�� ������ ���콺 ��ġ�� ����ϴ�.
	 * 
	 * @param PositionType ���콺 ��ġ�� �����Դϴ�.
	 * 
	 * @return Tick ȣ�� ������ ���콺 ��ġ�� ��ȯ�մϴ�.
	 */
	Vec2i GetLastPosition(const EPositionType& PositionType) const;


	/**
	 * @brief Tick ȣ�� ������ ���콺 ��ġ�� ����ϴ�.
	 * 
	 * @param PositionType ���콺 ��ġ�� �����Դϴ�.
	 * 
	 * @return Tick ȣ�� ������ ���콺 ��ġ�� ��ȯ�մϴ�.
	 */
	Vec2i GetCurrPosition(const EPositionType& PositionType) const;


	/**
	 * @brief Tick ȣ�� ���Ŀ� ������ ���̰��� ����ϴ�.
	 * 
	 * @param PositionType ���콺 ��ġ�� �����Դϴ�.
	 * 
	 * @return Tick ȣ�� ���Ŀ� ������ ���̰��� ��ȯ�մϴ�.
	 */
	Vec2i GetDeltaPosition(const EPositionType& PositionType) const;


private:
	/**
	 * @brief ����͸� �������� ���� ���콺�� ��ġ�� ����ϴ�.
	 *
	 * @return ����͸� �������� ���� ���콺�� (X, Y) ��ġ�� ��ȯ�մϴ�.
	 */
	Vec2i GetPositionFromScreen();


	/**
	 * @brief �����츦 �������� ���� ���콺�� ��ġ�� ����ϴ�.
	 *
	 * @see https://stackoverflow.com/questions/6423729/get-current-cursor-position
	 *
	 * @return �����츦 �������� ���� ���콺�� (X, Y) ��ġ�� ��ȯ�մϴ�.
	 */
	Vec2i GetPositionFromWindow();


private:
	/**
	 * @brief ���콺 ��ġ ����� ���� ������ �ڵ��Դϴ�.
	 */
	HWND WindowHandle_ = nullptr;


	/**
	 * @brief ������Ʈ ����(Tick ȣ�� ����)�� ȭ�� ���� ���콺 ��ġ�Դϴ�.
	 */
	Vec2i LastScreenMousePosition_;


	/**
	 * @brief ������Ʈ ����(Tick ȣ�� ����)�� ������ ���� ���콺 ��ġ�Դϴ�.
	 */
	Vec2i LastWindowMousePosition_;


	/**
	 * @brief ������Ʈ ��(Tick ȣ�� ��)�� ȭ�� ���� ���콺 ��ġ�Դϴ�.
	 */
	Vec2i CurrScreenMousePosition_;


	/**
	 * @brief ������Ʈ ����(Tick ȣ�� ��)�� ������ ���� ���콺 ��ġ�Դϴ�.
	 */
	Vec2i CurrWindowMousePosition_;
};