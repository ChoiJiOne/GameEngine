#pragma once

#include "Component.h"


/**
 * @brief ���� ������Ʈ�� �����ϴ� ����� ó�� ������Ʈ�Դϴ�.
 */
class AudioComponent : public Component
{
public:
	/**
	 * @brief ���� ������Ʈ�� ������ ����� ó�� ������Ʈ�� �������Դϴ�.
	 *
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 */
	AudioComponent(GameObject* Object)
		: Component(Object) {}


	/**
	 * @brief ���� ������Ʈ�� �����ϴ� ����� ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~AudioComponent() {}


	/**
	 * @brief ������Ʈ�� ���� ������ �� ���Կ����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(AudioComponent);
};