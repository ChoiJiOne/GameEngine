#pragma once

#include "Macro.h"

class GameObject;


/**
 * @brief ���� ������Ʈ�� �����ϴ� ������Ʈ�Դϴ�.
 */
class Component
{
public:
	/**
	 * @brief ���� ������Ʈ�� �����ϴ� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 */
	Component(GameObject* Object)
		: Object_(Object) { }


	/**
	 * @brief ���� ������Ʈ�� �����ϴ� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Component() {}


	/**
	 * @brief ������Ʈ�� ���� ������ �� ���Կ����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Component);


	/**
	 * @brief �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �����͸� ����ϴ�.
	 *
	 * @return �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �����͸� ��ȯ�մϴ�.
	 */
	GameObject* GetOwnerObject() { return Object_; }

	
private:
	/**
	 * @brief �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�Դϴ�.
	 */
	GameObject* Object_ = nullptr;
};