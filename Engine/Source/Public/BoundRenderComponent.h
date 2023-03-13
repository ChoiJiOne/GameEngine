#pragma once

#include "Component.h"
#include "Math.hpp"

class BoundComponent;


/**
 * @brief 게임 오브젝트의 경계 영역을 그리는 컴포넌트입니다.
 */
class BoundRenderComponent : public Component
{
public:
	/**
	 * @brief 게임 오브젝트의 경계 영역을 그리는 컴포넌트의 생성자입니다.
	 * 
	 * @param Object 이 컴포넌트를 소유하는 오브젝트의 포인터 값입니다.
	 */
	BoundRenderComponent(GameObject* Object);


	/**
	 * @brief 게임 오브젝트의 경계 영역을 그리는 컴포넌트의 생성자입니다.
	 * 
	 * @param Object 이 컴포넌트를 소유하는 오브젝트의 포인터 값입니다.
	 * @param Bound 이 컴포넌트에서 참조할 경계 영역 컴포넌트입니다.
	 * @param BoundColor 경계 영역의 색상입니다.
	 */
	BoundRenderComponent(GameObject* Object, BoundComponent* Bound, const LinearColor& BoundColor);


	/**
	 * @brief 게임 오브젝트의 경계 영역을 그리는 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~BoundRenderComponent();


	/**
	 * @brief 게임 오브젝트의 경계 영역을 그리는 컴포넌트의 복사 생성자와 대입 연산자를 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(BoundRenderComponent);


	/**
	 * @brief 현재 컴포넌트에 게임 오브젝트의 경계 영역을 붙입니다.
	 * 
	 * @param Bound 이 컴포넌트에서 참조할 경계 영역 컴포넌트입니다.
	 */
	void AttachBoundComponent(BoundComponent* Bound);


	/**
	 * @brief 경계 영역의 색상을 설정합니다.
	 * 
	 * @param BoundColor 설정할 경계 영역의 색상입니다.
	 */
	void SetBoundColor(const LinearColor& BoundColor) { BoundColor_ = BoundColor; }


	/**
	 * @brief 게임 오브젝트의 경계 영역을 그리는 컴포넌트를 업데이트합니다.
	 */
	void Tick();


private:
	/**
	 * @brief 게임 오브젝트의 경계 영역입니다.
	 */
	BoundComponent* BoundComponent_ = nullptr;


	/**
	 * @brief 경계 영역의 색상입니다.
	 */
	LinearColor BoundColor_;
};