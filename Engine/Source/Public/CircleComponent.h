#pragma once

#include "BoundComponent.h"
#include "Math.hpp"


/**
 * @brief ���� ������Ʈ�� �� ������ ��Ÿ���� ������Ʈ�Դϴ�.
 */
class CircleComponent : public BoundComponent
{
public:
	/**
	 * @brief ���� ������Ʈ�� ���� �� �� ������ ��Ÿ���� ������Ʈ�� �������Դϴ�.
	 *
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 */
	CircleComponent(GameObject* Object);


	/**
	 * @brief ���� ������Ʈ�� ���� �� �� ������ ��Ÿ���� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 * @param Center �� ������ �߽� ��ǥ�Դϴ�.
	 * @param Radius �� ������ ������ �����Դϴ�.
	 */
	CircleComponent(GameObject* Object, const Vec2f& Center, const float& Radius);


	/**
	 * @brief ���� ������Ʈ�� ���� �� �� ������ ��Ÿ���� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~CircleComponent();


	/**
	 * @brief ���� ������Ʈ�� ���� �� �� ������ ��Ÿ���� ������Ʈ�� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(CircleComponent);


	/**
	 * @brief �� ������ �߽� ��ǥ�� ����ϴ�.
	 *
	 * @return �� ������ �߽� ��ǥ�� ��ȯ�մϴ�.
	 */
	Vec2f GetCenter() const { return Center_; }


	/**
	 * @brief �� ������ �߽� ��ǥ�� �����մϴ�.
	 *
	 * @param Center ������ �� ������ �߽���ǥ�Դϴ�.
	 */
	void SetCenter(const Vec2f& Center) { Center_ = Center; }


	/**
	 * @brief �� ������ ������ ũ�⸦ ����ϴ�.
	 *
	 * @return �� ������ ������ ũ�⸦ ��ȯ�մϴ�.
	 */
	float GetRadius() const { return Radius_; }


	/**
	 * @brief �� ������ ������ ũ�⸦ �����մϴ�.
	 *
	 * @param Width ������ �� ������ ������ ũ���Դϴ�.
	 */
	void SetRadius(const float& Radius) { Radius_ = Radius; }


private:
	/**
	 * @brief �� ������ �߽� ��ǥ�Դϴ�.
	 */
	Vec2f Center_;


	/**
	 * @brief �� ������ ������ �����Դϴ�.
	 */
	float Radius_ = 0.0f;
};