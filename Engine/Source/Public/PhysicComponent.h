#pragma once

#include "Component.h"


/**
 * @brief ���� ������Ʈ�� �����ϴ� ���� ó�� ������Ʈ�Դϴ�.
 */
class PhysicComponent : public Component
{
public:
	/**
	 * @brief ���� ������Ʈ�� ������ ���� ó�� ������Ʈ�� �������Դϴ�.
	 *
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 */
	PhysicComponent(GameObject* Object)
		: Component(Object) {}


	/**
	 * @brief ���� ������Ʈ�� �����ϴ� ���� ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~PhysicComponent() {}


	/**
	 * @brief ������Ʈ�� ���� ������ �� ���Կ����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(PhysicComponent);
};