#pragma once

#include "BoundComponent.h"
#include "Vector.hpp"


/**
 * @brief ���� ������Ʈ�� �����ϴ� AABB(�� ���� ��� ����) ������Ʈ�Դϴ�.
 * +y
 * ��    ��������������������������Max
 * ��    ��           ��
 * ��    ��           �� �� AABB!
 * ��    ��           ��
 * �� Min��������������������������
 * ��
 * ��������������������������������������������������+x
 */
class AABBComponent : public BoundComponent
{
public:
	/**
	 * @brief ���� ������Ʈ�� ������ AABB ������Ʈ�� �������Դϴ�.
	 * 
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 * @param Center AABB�� �߽� ��ǥ�Դϴ�.
	 * @param Width AABB�� ���� ũ���Դϴ�.
	 * @param Height AABB�� ���� ũ���Դϴ�.
	 */
	AABBComponent(GameObject* Object, const Vec2f& Center, const float& Width, const float& Height)
		: BoundComponent(Object)
		, Center_(Center)
		, Width_(Width)
		, Height_(Height) {}


	/**
	 * @brief ���� ������Ʈ�� ������ AABB ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~AABBComponent() {}


	/**
	 * @brief ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(AABBComponent);


	/**
	 * @brief �ٸ� AABB���� �浹�� �˻��մϴ�.
	 * 
	 * @param BoundingBox �˻縦 ������ AABB�Դϴ�.
	 * 
	 * @return �浹�Ѵٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsCollision(const AABBComponent* BoundingBox);


	/**
	 * @brief AABB�� �߽� ��ǥ�� ����ϴ�.
	 * 
	 * @return AABB�� �߽� ��ǥ�� ��ȯ�մϴ�.
	 */
	Vec2f GetCenter() const { return Center_; }


	/**
	 * @brief AABB�� �߽� ��ǥ�� �����մϴ�.
	 * 
	 * @param Center ������ �߽� ��ǥ�Դϴ�.
	 */
	void SetCenter(const Vec2f& Center) { Center_ = Center; }


	/**
	 * @brief AABB�� ���� ũ�⸦ ����ϴ�.
	 * 
	 * @return AABB�� ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	float GetWidth() const { return Width_; }


	/**
	 * @brief AABB�� ���� ũ�⸦ �����մϴ�.
	 * 
	 * @param Width ������ AABB�� ���� ũ���Դϴ�.
	 */
	void SetWidth(float Width) { Width_ = Width; }


	/**
	 * @brief AABB�� ���� ũ�⸦ ����ϴ�.
	 *
	 * @return AABB�� ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	float GetHeight() const { return Height_; }


	/**
	 * @brief AABB�� ���� ũ�⸦ �����մϴ�.
	 *
	 * @param Height ������ AABB�� ���� ũ���Դϴ�.
	 */
	void SetHeight(float Height) { Height_ = Height; }

	
private:
	/**
	 * @brief AABB�� LEFT BOTTON ��ġ�� ����ϴ�.
	 * 
	 * @note �Ʒ� �׸��� Min ��ǥ ���� ��ȯ
	 * +y
	 * ��    ��������������������������Max
	 * ��    ��           ��
	 * ��    ��           �� �� AABB!
	 * ��    ��           ��
	 * �� Min��������������������������
	 * �� (�� �� ��ȯ!)
	 * ��������������������������������������������������+x
	 */
	inline Vec2f GetMinPosition() const
	{
		return Vec2f(Center_.x - Width_ / 2.0f, Center_.y - Height_ / 2.0f);
	}


	/**
	 * @biref AABB�� RIGHT TOP�� ��ġ�� ����ϴ�.
	 * 
	 * @note �Ʒ� �׸��� Max ��ǥ ���� ��ȯ
	 * +y
	 * ��    ��������������������������Max (�� �� ��ȯ!)
	 * ��    ��           ��
	 * ��    ��           �� �� AABB!
	 * ��    ��           ��
	 * �� Min��������������������������
	 * ��
	 * ��������������������������������������������������+x
	 */
	inline Vec2f GetMaxPosition() const
	{
		return Vec2f(Center_.x + Width_ / 2.0f, Center_.y + Height_ / 2.0f);
	}


private:
	/**
	 * @brief AABB�� �߽����Դϴ�.
	 */
	Vec2f Center_;


	/**
	 * @brief AABB�� ���� ũ���Դϴ�.
	 */
	float Width_ = 0.0f;


	/**
	 * @brief AABB�� ���� ũ���Դϴ�.
	 */
	float Height_ = 0.0f;
};