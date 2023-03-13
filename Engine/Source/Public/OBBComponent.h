#pragma once

#include "BoundComponent.h"
#include "Math.hpp"

#include <array>


/**
 * @brief ���� ������Ʈ�� OBB ������Ʈ�Դϴ�.
 */
class OBBComponent : public BoundComponent
{
public:
	/**
	 * @brief ���� ������Ʈ�� ���� �� OBB ������Ʈ�� �������Դϴ�.
	 *
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 */
	OBBComponent(GameObject* Object);


	/**
	 * @brief ���� ������Ʈ�� ���� �� OBB ������Ʈ�� �������Դϴ�.
	 *
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 * @param Center OBB�� �߽� ��ǥ�Դϴ�.
	 * @param Width OBB�� ���� ũ���Դϴ�.
	 * @param Height OBB�� ���� ũ���Դϴ�.
	 * @param Rotate OBB ���� �����Դϴ�.
	 */
	OBBComponent(GameObject* Object, const Vec2f& Center, const float& Width, const float& Height, const float& Rotate);


	/**
	 * @brief ���� ������Ʈ�� ���� �� OBB ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~OBBComponent();


	/**
	 * @brief ���� ������Ʈ�� ���� �� OBB ������Ʈ�� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(OBBComponent);


	/**
	 * @brief OBB ������ �߽� ��ǥ�� ����ϴ�.
	 *
	 * @return OBB ������ �߽� ��ǥ�� ��ȯ�մϴ�.
	 */
	Vec2f GetCenter() const { return Center_; }


	/**
	 * @brief OBB ������ �߽� ��ǥ�� �����մϴ�.
	 *
	 * @param Center ������ OBB ������ �߽���ǥ�Դϴ�.
	 */
	void SetCenter(const Vec2f& Center);


	/**
	 * @brief OBB ������ ���� ũ�⸦ ����ϴ�.
	 *
	 * @return OBB ������ ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	float GetWidth() const { return Width_; }


	/**
	 * @brief OBB ������ ���� ũ�⸦ �����մϴ�.
	 *
	 * @param Width ������ OBB ������ ���� ũ���Դϴ�.
	 */
	void SetWidth(const float& Width);


	/**
	 * @brief OBB ������ ���� ũ�⸦ ����ϴ�.
	 *
	 * @return OBB ������ ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	float GetHeight() const { return Height_; }


	/**
	 * @brief OBB ������ ���� ũ�⸦ �����մϴ�.
	 *
	 * @param Height ������ OBB ������ ���� ũ���Դϴ�.
	 */
	void SetHeight(const float& Height);


	/**
	 * @brief OBB ���� ���� ȸ������ ����ϴ�.
	 * 
	 * @return OBB ���� ���� ȸ������ ��ȯ�մϴ�.
	 */
	float GetRotate() const { return Rotate_; }


	/**
	 * @brief OBB ���� ���� ȸ������ �����մϴ�.
	 * 
	 * @param Rotate ������ OBB ���� ���� ȸ�����Դϴ�.
	 */
	void SetRotate(const float& Rotate);


	/**
	 * @brief OBB ������ �� ���� ����ϴ�.
	 *
	 * @note �� �޼��带 �̿��ϸ� �� ���� ���� ������ �� �����ϴ�.
	 *
	 * @return OBB ������ �� ������ ��� �����ڸ� ��ȯ�մϴ�.
	 */
	const std::array<Vec2f, 4>& GetBoundPositions() const { return BoundPositions_; }


private:
	/**
	 * @brief OBB ������ ������ ������Ʈ�մϴ�.
	 */
	void UpdateBoundPositions();


private:
	/**
	 * @brief OBB ������ �߽� ��ǥ�Դϴ�.
	 */
	Vec2f Center_;


	/**
	 * @brief OBB ������ ���� ũ���Դϴ�.
	 */
	float Width_ = 0.0f;


	/**
	 * @brief OBB ������ ���� ũ���Դϴ�.
	 */
	float Height_ = 0.0f;


	/**
	 * @brief OBB ������ ȸ�� ���� �����Դϴ�.
	 */
	float Rotate_ = 0.0f;


	/**
	 * @brief OBB ���� �ϴ��� �ε��� ���Դϴ�.
	 *
	 * @note LB = Left Bottom
	 */
	static const int32_t INDEX_LB = 0;


	/**
	 * OBB ���� ����� �ε��� ���Դϴ�.
	 *
	 * @note LT = Left Top
	 */
	static const int32_t INDEX_LT = 1;


	/**
	 * @brief OBB ������ �ϴ��� �ε��� ���Դϴ�.
	 *
	 * @note RB = Right Bottom
	 */
	static const int32_t INDEX_RB = 2;


	/**
	 * @brief OBB ������ ����� �ε��� ���Դϴ�.
	 *
	 * @note RT = Right Top
	 */
	static const int32_t INDEX_RT = 3;


	/**
	 * @brief OBB ������ �����Դϴ�.
	 */
	std::array<Vec2f, 4> BoundPositions_;
};