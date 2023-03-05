#pragma once

#include "Component.h"


/**
 * @brief ���� ������Ʈ�� �����ϴ� ���� ������Ʈ�Դϴ�.
 */
class BoundComponent : public Component
{
public:
	/**
	 * @brief ���� ������Ʈ�� ������ ���� ������Ʈ�� �������Դϴ�.
	 *
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 */
	BoundComponent(GameObject* Object)
		: Component(Object) {}


	/**
	 * @brief ���� ������Ʈ�� �����ϴ� ���� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~BoundComponent() {}


	/**
	 * @brief ������Ʈ�� ���� ������ �� ���Կ����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(BoundComponent);
};