#pragma once

#include "Macro.h"
#include "Vector.hpp"

#include <windows.h>
#include <unordered_map>


/**
 * @brief ���콺�� ���� ��ư�� �ڵ� ���Դϴ�.
 */
enum class EVirtualButton
{
	CODE_LEFT  = 0x00,
	CODE_RIGHT = 0x01,
};


/**
 * @brief ���콺�� ���¸� �����ϴ� Ŭ�����Դϴ�.
 */
class Mouse
{
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
	 * @brief ���� ���콺 ��ġ�� ����ϴ�.
	 * 
	 * @return Tick ȣ�� ������ ���콺 ��ġ�� ��ȯ�մϴ�.
	 */
	Vec2i GetPosition() const;


	/**
	 * @brief Tick ȣ�� ���Ŀ� ������ ���̰��� ����ϴ�.
	 * 
	 * @return Tick ȣ�� ���Ŀ� ������ ���̰��� ��ȯ�մϴ�.
	 */
	Vec2i GetDeltaPosition() const;


	/**
	 * @brief ���콺�� �����̴��� Ȯ���մϴ�.
	 * 
	 * @return ���콺�� �����δٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsMove() const { return bIsMove_; }


	/**
	 * @brief ���콺 ��ư�� �Է� ���¸� ����ϴ�.
	 *
	 * @param VirtualButton �Է� ���¸� ���� ���콺 ��ư�Դϴ�.
	 *
	 * @return ���콺 ��ư�� �����ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsPressButton(EVirtualButton VirtualButton);


	/**
	 * @brief ���콺 ��ư�� �Է� ���¸� �����մϴ�.
	 * 
	 * @note InputManager �ܿ��� �ݵ�� ȣ���ϸ� �ȵŴ� �޼����Դϴ�.
	 * 
	 * @param VirtualButton �Է� ���¸� ������ ���콺 ��ư�Դϴ�.
	 * @param bIsPressed ���콺�� �Է� �����Դϴ�.
	 */
	void SetButtonPressState(EVirtualButton VirtualButton, bool bIsPressed);
	

private:
	/**
	 * @brief ���� ���콺�� ��ġ�� ����ϴ�.
	 *
	 * @note ������ ���� ������ â�Դϴ�.
	 * 
	 * @return ����͸� �������� ���� ���콺�� (X, Y) ��ġ�� ��ȯ�մϴ�.
	 */
	Vec2i GetCurrentPosition();


private:
	/**
	 * @brief ���콺 ��ġ ����� ���� ������ �ڵ��Դϴ�.
	 */
	HWND WindowHandle_ = nullptr;


	/**
	 * @brief ���콺�� �����̴��� Ȯ���մϴ�.
	 */
	bool bIsMove_ = false;


	/**
	 * @brief ���콺�� ���ȴ��� Ȯ���մϴ�.
	 */
	std::unordered_map<EVirtualButton, bool> ButtonPressState_;


	/**
	 * @brief ������Ʈ ����(Tick ȣ�� ����)�� ������ ���� ���콺 ��ġ�Դϴ�.
	 */
	Vec2i LastWindowMousePosition_;


	/**
	 * @brief ������Ʈ ����(Tick ȣ�� ��)�� ������ ���� ���콺 ��ġ�Դϴ�.
	 */
	Vec2i CurrWindowMousePosition_;
};