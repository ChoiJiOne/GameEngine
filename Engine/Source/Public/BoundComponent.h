#pragma once

#include "Component.h"


/**
 * @brief ���� ������Ʈ�� ������ �����ϴ� ������Ʈ�Դϴ�.
 */
class BoundComponent : public Component
{
public:
	/**
	 * @brief ���� ������Ʈ ������ �����Դϴ�.
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
	 * @brief ���� ������Ʈ�� ������ �����ϴ� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 * @param BoundaryShape ��� ������ ����Դϴ�.
	 */
	BoundComponent(GameObject* Object, const EBoundaryShape& BoundaryShape)
		: Component(Object)
		, BoundaryShape_(BoundaryShape)
	{}


	/**
	 * @brief ���� ������Ʈ�� ������ �����ϴ� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~BoundComponent() {}


	/**
	 * @brief ���� ������Ʈ�� ������ �����ϴ� ������Ʈ�� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(BoundComponent);


	/**
	 * @brief ���� ������Ʈ�� ���� ����� ����ϴ�.
	 * 
	 * @return ���� ������Ʈ�� ���� ����� ��ȯ�մϴ�.
	 */
	EBoundaryShape GetBoundaryShape() const { return BoundaryShape_; }


private:
	/**
	 * @brief ���� ������Ʈ�� ���� ����Դϴ�.
	 */
	EBoundaryShape BoundaryShape_ = EBoundaryShape::NONE;
};