#pragma once

#include "Component.h"
#include "Math.hpp"

class BoundComponent;


/**
 * @brief ���� ������Ʈ�� ��� ������ �׸��� ������Ʈ�Դϴ�.
 */
class BoundRenderComponent : public Component
{
public:
	/**
	 * @brief ���� ������Ʈ�� ��� ������ �׸��� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 */
	BoundRenderComponent(GameObject* Object);


	/**
	 * @brief ���� ������Ʈ�� ��� ������ �׸��� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 * @param Bound �� ������Ʈ���� ������ ��� ���� ������Ʈ�Դϴ�.
	 * @param BoundColor ��� ������ �����Դϴ�.
	 */
	BoundRenderComponent(GameObject* Object, BoundComponent* Bound, const LinearColor& BoundColor);


	/**
	 * @brief ���� ������Ʈ�� ��� ������ �׸��� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~BoundRenderComponent();


	/**
	 * @brief ���� ������Ʈ�� ��� ������ �׸��� ������Ʈ�� ���� �����ڿ� ���� �����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(BoundRenderComponent);


	/**
	 * @brief ���� ������Ʈ�� ���� ������Ʈ�� ��� ������ ���Դϴ�.
	 * 
	 * @param Bound �� ������Ʈ���� ������ ��� ���� ������Ʈ�Դϴ�.
	 */
	void AttachBoundComponent(BoundComponent* Bound);


	/**
	 * @brief ��� ������ ������ �����մϴ�.
	 * 
	 * @param BoundColor ������ ��� ������ �����Դϴ�.
	 */
	void SetBoundColor(const LinearColor& BoundColor) { BoundColor_ = BoundColor; }


	/**
	 * @brief ���� ������Ʈ�� ��� ������ �׸��� ������Ʈ�� ������Ʈ�մϴ�.
	 */
	void Tick();


private:
	/**
	 * @brief ���� ������Ʈ�� ��� �����Դϴ�.
	 */
	BoundComponent* BoundComponent_ = nullptr;


	/**
	 * @brief ��� ������ �����Դϴ�.
	 */
	LinearColor BoundColor_;
};