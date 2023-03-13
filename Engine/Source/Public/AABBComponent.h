#pragma once

#include "BoundComponent.h"
#include "Math.hpp"

#include <array>


/**
 * @brief ���� ������Ʈ�� AABB ������Ʈ�Դϴ�.
 */
class AABBComponent : public BoundComponent
{
public:
	/**
	 * @brief ���� ������Ʈ�� ���� �� AABB ������Ʈ�� �������Դϴ�.
	 * 
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 */
	AABBComponent(GameObject* Object);


	/**
	 * @brief ���� ������Ʈ�� ���� �� AABB ������Ʈ�� �������Դϴ�.
	 * 
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 * @param Center AABB�� �߽� ��ǥ�Դϴ�.
	 * @param Width AABB�� ���� ũ���Դϴ�.
	 * @param Height AABB�� ���� ũ���Դϴ�.
	 */
	AABBComponent(GameObject* Object, const Vec2f& Center, const float& Width, const float& Height);


	/**
	 * @brief ���� ������Ʈ�� ���� �� AABB ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~AABBComponent();


	/**
	 * @brief ���� ������Ʈ�� ���� �� AABB ������Ʈ�� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(AABBComponent);


	/**
	 * @brief AABB ������ �߽� ��ǥ�� ����ϴ�.
	 * 
	 * @return AABB ������ �߽� ��ǥ�� ��ȯ�մϴ�.
	 */
	Vec2f GetCenter() const { return Center_; }


	/**
	 * @brief AABB ������ �߽� ��ǥ�� �����մϴ�.
	 * 
	 * @param Center ������ AABB ������ �߽���ǥ�Դϴ�.
	 */
	void SetCenter(const Vec2f& Center);


	/**
	 * @brief AABB ������ ���� ũ�⸦ ����ϴ�.
	 * 
	 * @return AABB ������ ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	float GetWidth() const { return Width_; }


	/**
	 * @brief AABB ������ ���� ũ�⸦ �����մϴ�.
	 * 
	 * @param Width ������ AABB ������ ���� ũ���Դϴ�.
	 */
	void SetWidth(const float& Width);


	/**
	 * @brief AABB ������ ���� ũ�⸦ ����ϴ�.
	 *
	 * @return AABB ������ ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	float GetHeight() const { return Height_; }


	/**
	 * @brief AABB ������ ���� ũ�⸦ �����մϴ�.
	 *
	 * @param Height ������ AABB ������ ���� ũ���Դϴ�.
	 */
	void SetHeight(const float& Height);


	/**
	 * @brief AABB ������ �� ���� ����ϴ�.
	 * 
	 * @note �� �޼��带 �̿��ϸ� �� ���� ���� ������ �� �����ϴ�.
	 * 
	 * @return AABB ������ �� ������ ��� �����ڸ� ��ȯ�մϴ�.
	 */
	const std::array<Vec2f, 4>& GetBoundPositions() const { return BoundPositions_; }


	/**
	 * @brief AABB ������ �ּ� ��ǥ ���� ����ϴ�.
	 * 
	 * @return AABB ������ �ּ� ��ǥ ���� ��ȯ�մϴ�.
	 */
	Vec2f GetMinBoundPosition() const { return BoundPositions_[INDEX_LB]; }


	/**
	 * @brief AABB ������ �ִ� ��ǥ ���� ����ϴ�.
	 * 
	 * @return AABB ������ �ִ� ��ǥ ���� ��ȯ�մϴ�.
	 */
	Vec2f GetMaxBoundPosition() const { return BoundPositions_[INDEX_RT]; }


private:
	/**
	 * @brief AABB ������ ������ ������Ʈ�մϴ�.
	 */
	void UpdateBoundPositions();


private:
	/**
	 * @brief AABB ������ �߽� ��ǥ�Դϴ�.
	 */
	Vec2f Center_;


	/**
	 * @brief AABB ������ ���� ũ���Դϴ�.
	 */
	float Width_ = 0.0f;


	/**
	 * @brief AABB ������ ���� ũ���Դϴ�.
	 */
	float Height_ = 0.0f;


	/**
	 * @brief AABB ���� �ϴ��� �ε��� ���Դϴ�.
	 * 
	 * @note LB = Left Bottom
	 */
	static const int32_t INDEX_LB = 0;


	/**
	 * AABB ���� ����� �ε��� ���Դϴ�.
	 * 
	 * @note LT = Left Top
	 */
	static const int32_t INDEX_LT = 1;


	/**
	 * @brief AABB ������ �ϴ��� �ε��� ���Դϴ�.
	 * 
	 * @note RB = Right Bottom
	 */
	static const int32_t INDEX_RB = 2;


	/**
	 * @brief AABB ������ ����� �ε��� ���Դϴ�.
	 * 
	 * @note RT = Right Top
	 */
	static const int32_t INDEX_RT = 3;


	/**
	 * @brief AABB ������ �����Դϴ�.
	 */
	std::array<Vec2f, 4> BoundPositions_;
};