#pragma once

#include "Component.h"


/**
 * @brief 게임 오브젝트가 소유하는 영역 컴포넌트입니다.
 */
class BoundComponent : public Component
{
public:
	/**
	 * @brief 게임 오브젝트가 소유한 영역 컴포넌트의 생성자입니다.
	 *
	 * @param Object 이 컴포넌트를 소유하는 오브젝트의 포인터 값입니다.
	 */
	BoundComponent(GameObject* Object)
		: Component(Object) {}


	/**
	 * @brief 게임 오브젝트가 소유하는 영역 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~BoundComponent() {}


	/**
	 * @brief 컴포넌트의 복사 생성자 및 대입연산자를 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(BoundComponent);
};