#pragma once

#include "Vector.hpp"
#include "InputManager.h"
#include "InputComponent.h"

#include <functional>


/**
 * @brief ��ư�� �Է� ó���� �����ϴ� ������Ʈ�Դϴ�.
 */
class ButtonInputComponent : public InputComponent
{
public:
	/**
	 * @brief ��ư�� �Է� ó���� �����ϴ� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 */
	ButtonInputComponent(
		GameObject* Object,
		const Vec2f& Position,
		const float& Width,
		const float& Height,
		const EKeyCode& KeyCode,
		const std::function<void()>& ClickEvent,
		const float& ReduceRate = 1.0f,
		bool bIsMouseMode = true
	);


	/**
	 * @brief ��ư�� �Է� ó���� �����ϴ� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~ButtonInputComponent();


	/**
	 * ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(ButtonInputComponent);


	/**
	 * @brief ��ư�� �Է� ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 */
	void Tick();


private:
	/**
	 * @brief ���콺�� ���� ���� �ִ��� Ȯ���մϴ�.
	 *
	 * @return ���콺�� ���� ���� �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsDetectMouse() const;


	/**
	 * @brief ��ư�� �Է� ó���� �����մϴ�.
	 * 
	 * @param ButtonWidth[out] �Է� ó�� ����� ����� ��ư�� ���� ũ���Դϴ�.
	 * @param ButtonHeight[out] �Է� ó�� ����� ����� ��ư�� ���� ũ���Դϴ�. 
	 */
	void ProcessButtonInput(float& ButtonWidth, float& ButtonHeight);


private:
	/**
	 * @brief ���콺�� ��ư ���� �ִ��� Ȯ���մϴ�.
	 */
	bool bIsDetectMouse_ = false;


	/**
	 * @brief ���� ���� �簢�� ��ư �߽� ��ǥ�Դϴ�.
	 */
	Vec2f Position_;


	/**
	 * @brief �簢�� ��ư�� ���� ũ���Դϴ�.
	 */
	float Width_ = 0.0f;


	/**
	 * @brief �簢�� ��ư�� ���� ũ���Դϴ�.
	 */
	float Height_ = 0.0f;


	/**
	 * @brief ��ư�� �����ϴ� Ű �ڵ� ���Դϴ�.
	 */
	EKeyCode KeyCode_ = EKeyCode::CODE_NONE;


	/**
	 * @brief ��ư Ŭ�� �� �߻��� �̺�Ʈ�Դϴ�.
	 */
	std::function<void()> ClickEvent_ = nullptr;


	/**
	 * @brief ��ư Ŭ�� �� �پ��� ��ư�� �����Դϴ�.
	 */
	float ReduceRate_ = 0.0f;


	/**
	 * @brief ��ư�� ���콺�� �����ϴ� ������� Ȯ���մϴ�.
	 */
	bool bIsMouseMode_ = true;
};