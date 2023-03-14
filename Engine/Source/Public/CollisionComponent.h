#pragma once

#include "Component.h"
#include "BoundComponent.h"

class AABBComponent;
class CircleComponent;
class OBBComponent;


/**
 * @brief ���� ������Ʈ�� �浹�� �����ϴ� ������Ʈ�Դϴ�.
 */
class CollisionComponent : public Component
{
public:
	/**
	 * @brief ���� ������Ʈ�� �浹�� �����ϴ� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param Object �� ������Ʈ�� �����ϰ� �ִ� ������Ʈ�� ������ ���Դϴ�.
	 */
	CollisionComponent(GameObject* Object);


	/**
	 * @brief ���� ������Ʈ�� �浹�� �����ϴ� ������Ʈ�� �������Դϴ�.
	 *
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 * @param Bound �� ������Ʈ���� ������ ��� ���� ������Ʈ�Դϴ�.
	 */
	CollisionComponent(GameObject* Object, BoundComponent* Bound);


	/**
	 * @brief ���� ������Ʈ�� �浹�� �����ϴ� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~CollisionComponent();


	/**
	 * @brief ���� ������Ʈ�� �浹�� �����ϴ� ������Ʈ�� ���� �����ڿ� ���� �����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(CollisionComponent);


	/**
	 * @brief ���� ������Ʈ�� ���� ������Ʈ�� ��� ������ ���Դϴ�.
	 *
	 * @param Bound �� ������Ʈ���� ������ ��� ���� ������Ʈ�Դϴ�.
	 */
	void AttachBoundComponent(BoundComponent* Bound);


	/**
	 * @brief �ٸ� ��� ������ �浹�ϴ��� �˻��մϴ�.
	 * 
	 * @param TargetBound �浹�� �˻��� ��� �����Դϴ�.
	 */
	bool IsDetectCollision(BoundComponent* TargetBound);


private:
	/**
	 * @brief �浹 �˻縦 ������ �� �ִ��� Ȯ���մϴ�.
	 * 
	 * @param TargetBound �浹�� �˻��� ��� �����Դϴ�.
	 * 
	 * @return �浹 �˻縦 �� �� �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool CanDetectCollision(BoundComponent* TargetBound) const;


	/**
	 * @brief AABB�� AABB ������ �浹�� �˻��մϴ�.
	 * 
	 * @param LhsBoundComponent �浹 ���θ� �˻��� ��� �����Դϴ�. 
	 * @param RhsBoundComponent �浹 ���θ� �˻��� �Ǵٸ� ��� �����Դϴ�. 
	 */
	bool IsDetectCollisionAABBAndAABB(AABBComponent* LhsBoundComponent, AABBComponent* RhsBoundComponent);


	/**
	 * @brief AABB�� OBB ������ �浹�� �˻��մϴ�.
	 * 
	 * @param LhsBoundComponent �浹 ���θ� �˻��� ��� �����Դϴ�.
	 * @param RhsBoundComponent �浹 ���θ� �˻��� �Ǵٸ� ��� �����Դϴ�.
	 */
	bool IsDetectCollisionAABBAndOBB(AABBComponent* LhsBoundComponent, OBBComponent* RhsBoundComponent);


	/**
	 * @brief AABB�� CIRCLE ������ �浹�� �˻��մϴ�.
	 * 
	 * @param LhsBoundComponent �浹 ���θ� �˻��� ��� �����Դϴ�.
	 * @param RhsBoundComponent �浹 ���θ� �˻��� �Ǵٸ� ��� �����Դϴ�.
	 */
	bool IsDetectCollisionAABBAndCIRCLE(AABBComponent* LhsBoundComponent, CircleComponent* RhsBoundComponent);


	/**
	 * @brief OBB�� AABB ������ �浹�� �˻��մϴ�.
	 *
	 * @param LhsBoundComponent �浹 ���θ� �˻��� ��� �����Դϴ�.
	 * @param RhsBoundComponent �浹 ���θ� �˻��� �Ǵٸ� ��� �����Դϴ�.
	 */
	bool IsDetectCollisionOBBAndAABB(OBBComponent* LhsBoundComponent, AABBComponent* RhsBoundComponent);


	/**
	 * @brief OBB�� OBB ������ �浹�� �˻��մϴ�.
	 * 
	 * @param LhsBoundComponent �浹 ���θ� �˻��� ��� �����Դϴ�.
	 * @param RhsBoundComponent �浹 ���θ� �˻��� �Ǵٸ� ��� �����Դϴ�.
	 */
	bool IsDetectCollisionOBBAndOBB(OBBComponent* LhsBoundComponent, OBBComponent* RhsBoundComponent);


	/**
	 * @brief OBB�� CIRCLE ������ �浹�� �˻��մϴ�.
	 * 
	 * @param LhsBoundComponent �浹 ���θ� �˻��� ��� �����Դϴ�.
	 * @param RhsBoundComponent �浹 ���θ� �˻��� �Ǵٸ� ��� �����Դϴ�.
	 */
	bool IsDetectCollisionOBBAndCIRCLE(OBBComponent* LhsBoundComponent, CircleComponent* RhsBoundComponent);


	/**
	 * @brief CIRCLE�� AABB ������ �浹�� �˻��մϴ�.
	 *
	 * @param LhsBoundComponent �浹 ���θ� �˻��� ��� �����Դϴ�.
	 * @param RhsBoundComponent �浹 ���θ� �˻��� �Ǵٸ� ��� �����Դϴ�.
	 */
	bool IsDetectCollisionCIRCLEAndAABB(CircleComponent* LhsBoundComponent, AABBComponent* RhsBoundComponent);


	/**
	 * @brief CIRCLE�� AABB ������ �浹�� �˻��մϴ�.
	 *
	 * @param LhsBoundComponent �浹 ���θ� �˻��� ��� �����Դϴ�.
	 * @param RhsBoundComponent �浹 ���θ� �˻��� �Ǵٸ� ��� �����Դϴ�.
	 */
	bool IsDetectCollisionCIRCLEAndOBB(CircleComponent* LhsBoundComponent, OBBComponent* RhsBoundComponent);


	/**
	 * @brief CIRCLE�� CIRCLE ������ �浹�� �˻��մϴ�.
	 * 
	 * @param LhsBoundComponent �浹 ���θ� �˻��� ��� �����Դϴ�.
	 * @param RhsBoundComponent �浹 ���θ� �˻��� �Ǵٸ� ��� �����Դϴ�.
	 */
	bool IsDetectCollisionCIRCLEAndCIRCLE(CircleComponent* LhsBoundComponent, CircleComponent* RhsBoundComponent);


private:
	/**
	 * @brief �� ������Ʈ�� ������ ���� ������Ʈ�� ��� �����Դϴ�.
	 */
	BoundComponent* BoundComponent_ = nullptr;
};