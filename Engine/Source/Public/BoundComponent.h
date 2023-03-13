#pragma once

#include "Component.h"


/**
 * @brief 게임 오브젝트의 영역을 정의하는 컴포넌트입니다.
 */
class BoundComponent : public Component
{
public:
	/**
	 * @brief 게임 오브젝트 영역의 종류입니다.
	 */
	enum class EBoundaryShape
	{
		NONE   = 0x00,
		AABB   = 0x01,
		OBB    = 0x02,
		CIRCLE = 0x03
	};


public:
	/**
	 * @brief 게임 오브젝트의 영역을 정의하는 컴포넌트의 생성자입니다.
	 * 
	 * @param Object 이 컴포넌트를 소유하는 오브젝트의 포인터 값입니다.
	 * @param BoundaryShape 경계 영역의 모양입니다.
	 */
	BoundComponent(GameObject* Object, const EBoundaryShape& BoundaryShape)
		: Component(Object)
		, BoundaryShape_(BoundaryShape)
	{}


	/**
	 * @brief 게임 오브젝트의 영역을 정의하는 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~BoundComponent() {}


	/**
	 * @brief 게임 오브젝트의 영역을 정의하는 컴포넌트의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(BoundComponent);


	/**
	 * @brief 게임 오브젝트의 영역 모양을 얻습니다.
	 * 
	 * @return 게임 오브젝트의 영역 모양을 반환합니다.
	 */
	EBoundaryShape GetBoundaryShape() const { return BoundaryShape_; }


private:
	/**
	 * @brief 게임 오브젝트의 영역 모양입니다.
	 */
	EBoundaryShape BoundaryShape_ = EBoundaryShape::NONE;
};