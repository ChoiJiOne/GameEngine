#pragma once

#include "Component.h"


/**
 * @brief ���� ������Ʈ�� �����ϴ� �׷��Ƚ� ������Ʈ�Դϴ�.
 * 
 * @note �� ������Ʈ���� �ݵ�� ������ ���� ������ �־�� �մϴ�.
 */
class GraphicsComponent : public Component
{
public:
	/**
	 * @brief ���� ������Ʈ�� ������ �׷��Ƚ� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 */
	GraphicsComponent(GameObject* Object)
		: Component(Object) {}


	/**
	 * @brief ���� ������Ʈ�� �����ϴ� �׷��Ƚ� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~GraphicsComponent() {}


	/**
	 * @brief ������Ʈ�� ���� ������ �� ���Կ����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(GraphicsComponent);
};