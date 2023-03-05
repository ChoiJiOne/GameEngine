#pragma once

#include "Component.h"


/**
 * @brief ���� ������Ʈ�� �����ϴ� �Է� ó�� ������Ʈ�Դϴ�.
 */
class InputComponent : public Component
{
public:
	/**
	 * @brief ���� ������Ʈ�� ������ �Է� ó�� ������Ʈ�� �������Դϴ�.
	 *
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 */
	InputComponent(GameObject* Object)
		: Component(Object) {}


	/**
	 * @brief ���� ������Ʈ�� �����ϴ� �Է� ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~InputComponent() {}


	/**
	 * @brief ������Ʈ�� ���� ������ �� ���Կ����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(InputComponent);
};