#pragma once

#include "Component.h"
#include "BoundComponent.h"

class AABBComponent;
class CircleComponent;
class OBBComponent;


/**
 * @brief 게임 오브젝트의 충돌을 검출하는 컴포넌트입니다.
 */
class CollisionComponent : public Component
{
public:
	/**
	 * @brief 게임 오브젝트의 충돌을 검출하는 컴포넌트의 생상자입니다.
	 * 
	 * @param Object 이 컴포넌트를 소유하고 있는 오브젝트의 포인터 값입니다.
	 */
	CollisionComponent(GameObject* Object);


	/**
	 * @brief 게임 오브젝트의 충돌을 검출하는 컴포넌트의 생상자입니다.
	 *
	 * @param Object 이 컴포넌트를 소유하는 오브젝트의 포인터 값입니다.
	 * @param Bound 이 컴포넌트에서 참조할 경계 영역 컴포넌트입니다.
	 */
	CollisionComponent(GameObject* Object, BoundComponent* Bound);


	/**
	 * @brief 게임 오브젝트의 충돌을 검출하는 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~CollisionComponent();


	/**
	 * @brief 게임 오브젝트의 충돌을 검출하는 컴포넌트의 복사 생성자와 대입 연산자를 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(CollisionComponent);


	/**
	 * @brief 현재 컴포넌트에 게임 오브젝트의 경계 영역을 붙입니다.
	 *
	 * @param Bound 이 컴포넌트에서 참조할 경계 영역 컴포넌트입니다.
	 */
	void AttachBoundComponent(BoundComponent* Bound);


	/**
	 * @brief 다른 경계 영역과 충돌하는지 검사합니다.
	 * 
	 * @param TargetBound 충돌을 검사할 경계 영역입니다.
	 */
	bool IsDetectCollision(BoundComponent* TargetBound);


private:
	/**
	 * @brief 충돌 검사를 수행할 수 있는지 확인합니다.
	 * 
	 * @param TargetBound 충돌을 검사할 경계 영역입니다.
	 * 
	 * @return 충돌 검사를 할 수 있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool CanDetectCollision(BoundComponent* TargetBound) const;


	/**
	 * @brief AABB와 AABB 사이의 충돌을 검사합니다.
	 * 
	 * @param LhsBoundComponent 충돌 여부를 검사할 경계 영역입니다. 
	 * @param RhsBoundComponent 충돌 여부를 검사할 또다른 경계 영역입니다. 
	 */
	bool IsDetectCollisionAABBAndAABB(AABBComponent* LhsBoundComponent, AABBComponent* RhsBoundComponent);


	/**
	 * @brief AABB와 OBB 사이의 충돌을 검사합니다.
	 * 
	 * @param LhsBoundComponent 충돌 여부를 검사할 경계 영역입니다.
	 * @param RhsBoundComponent 충돌 여부를 검사할 또다른 경계 영역입니다.
	 */
	bool IsDetectCollisionAABBAndOBB(AABBComponent* LhsBoundComponent, OBBComponent* RhsBoundComponent);


	/**
	 * @brief AABB와 CIRCLE 사이의 충돌을 검사합니다.
	 * 
	 * @param LhsBoundComponent 충돌 여부를 검사할 경계 영역입니다.
	 * @param RhsBoundComponent 충돌 여부를 검사할 또다른 경계 영역입니다.
	 */
	bool IsDetectCollisionAABBAndCIRCLE(AABBComponent* LhsBoundComponent, CircleComponent* RhsBoundComponent);


	/**
	 * @brief OBB와 AABB 사이의 충돌을 검사합니다.
	 *
	 * @param LhsBoundComponent 충돌 여부를 검사할 경계 영역입니다.
	 * @param RhsBoundComponent 충돌 여부를 검사할 또다른 경계 영역입니다.
	 */
	bool IsDetectCollisionOBBAndAABB(OBBComponent* LhsBoundComponent, AABBComponent* RhsBoundComponent);


	/**
	 * @brief OBB와 OBB 사이의 충돌을 검사합니다.
	 * 
	 * @param LhsBoundComponent 충돌 여부를 검사할 경계 영역입니다.
	 * @param RhsBoundComponent 충돌 여부를 검사할 또다른 경계 영역입니다.
	 */
	bool IsDetectCollisionOBBAndOBB(OBBComponent* LhsBoundComponent, OBBComponent* RhsBoundComponent);


	/**
	 * @brief OBB와 CIRCLE 사이의 충돌을 검사합니다.
	 * 
	 * @param LhsBoundComponent 충돌 여부를 검사할 경계 영역입니다.
	 * @param RhsBoundComponent 충돌 여부를 검사할 또다른 경계 영역입니다.
	 */
	bool IsDetectCollisionOBBAndCIRCLE(OBBComponent* LhsBoundComponent, CircleComponent* RhsBoundComponent);


	/**
	 * @brief CIRCLE와 AABB 사이의 충돌을 검사합니다.
	 *
	 * @param LhsBoundComponent 충돌 여부를 검사할 경계 영역입니다.
	 * @param RhsBoundComponent 충돌 여부를 검사할 또다른 경계 영역입니다.
	 */
	bool IsDetectCollisionCIRCLEAndAABB(CircleComponent* LhsBoundComponent, AABBComponent* RhsBoundComponent);


	/**
	 * @brief CIRCLE와 AABB 사이의 충돌을 검사합니다.
	 *
	 * @param LhsBoundComponent 충돌 여부를 검사할 경계 영역입니다.
	 * @param RhsBoundComponent 충돌 여부를 검사할 또다른 경계 영역입니다.
	 */
	bool IsDetectCollisionCIRCLEAndOBB(CircleComponent* LhsBoundComponent, OBBComponent* RhsBoundComponent);


	/**
	 * @brief CIRCLE와 CIRCLE 사이의 충돌을 검사합니다.
	 * 
	 * @param LhsBoundComponent 충돌 여부를 검사할 경계 영역입니다.
	 * @param RhsBoundComponent 충돌 여부를 검사할 또다른 경계 영역입니다.
	 */
	bool IsDetectCollisionCIRCLEAndCIRCLE(CircleComponent* LhsBoundComponent, CircleComponent* RhsBoundComponent);


private:
	/**
	 * @brief 이 컴포넌트를 소유한 게임 오브젝트의 경계 영역입니다.
	 */
	BoundComponent* BoundComponent_ = nullptr;
};