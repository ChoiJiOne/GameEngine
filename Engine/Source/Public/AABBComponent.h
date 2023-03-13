#pragma once

#include "BoundComponent.h"
#include "Math.hpp"

#include <array>


/**
 * @brief 게임 오브젝트의 AABB 컴포넌트입니다.
 */
class AABBComponent : public BoundComponent
{
public:
	/**
	 * @brief 게임 오브젝트의 영역 중 AABB 컴포넌트의 생성자입니다.
	 * 
	 * @param Object 이 컴포넌트를 소유하는 오브젝트의 포인터 값입니다.
	 */
	AABBComponent(GameObject* Object);


	/**
	 * @brief 게임 오브젝트의 영역 중 AABB 컴포넌트의 생성자입니다.
	 * 
	 * @param Object 이 컴포넌트를 소유하는 오브젝트의 포인터 값입니다.
	 * @param Center AABB의 중심 좌표입니다.
	 * @param Width AABB의 가로 크기입니다.
	 * @param Height AABB의 세로 크기입니다.
	 */
	AABBComponent(GameObject* Object, const Vec2f& Center, const float& Width, const float& Height);


	/**
	 * @brief 게임 오브젝트의 영역 중 AABB 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~AABBComponent();


	/**
	 * @brief 게임 오브젝트의 영역 중 AABB 컴포넌트의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(AABBComponent);


	/**
	 * @brief AABB 영역의 중심 좌표를 얻습니다.
	 * 
	 * @return AABB 영역의 중심 좌표를 반환합니다.
	 */
	Vec2f GetCenter() const { return Center_; }


	/**
	 * @brief AABB 영역의 중심 좌표를 설정합니다.
	 * 
	 * @param Center 설정할 AABB 영역의 중심좌표입니다.
	 */
	void SetCenter(const Vec2f& Center);


	/**
	 * @brief AABB 영역의 가로 크기를 얻습니다.
	 * 
	 * @return AABB 영역의 가로 크기를 반환합니다.
	 */
	float GetWidth() const { return Width_; }


	/**
	 * @brief AABB 영역의 가로 크기를 설정합니다.
	 * 
	 * @param Width 설정할 AABB 영역의 가로 크기입니다.
	 */
	void SetWidth(const float& Width);


	/**
	 * @brief AABB 영역의 세로 크기를 얻습니다.
	 *
	 * @return AABB 영역의 세로 크기를 반환합니다.
	 */
	float GetHeight() const { return Height_; }


	/**
	 * @brief AABB 영역의 세로 크기를 설정합니다.
	 *
	 * @param Height 설정할 AABB 영역의 세로 크기입니다.
	 */
	void SetHeight(const float& Height);


	/**
	 * @brief AABB 영역의 끝 점을 얻습니다.
	 * 
	 * @note 이 메서드를 이용하면 끝 점의 값은 변경할 수 없습니다.
	 * 
	 * @return AABB 영역의 끝 점들의 상수 참조자를 반환합니다.
	 */
	const std::array<Vec2f, 4>& GetBoundPositions() const { return BoundPositions_; }


	/**
	 * @brief AABB 영역의 최소 좌표 값을 얻습니다.
	 * 
	 * @return AABB 영역의 최소 좌표 값을 반환합니다.
	 */
	Vec2f GetMinBoundPosition() const { return BoundPositions_[INDEX_LB]; }


	/**
	 * @brief AABB 영역의 최대 좌표 값을 얻습니다.
	 * 
	 * @return AABB 영역의 최대 좌표 값을 반환합니다.
	 */
	Vec2f GetMaxBoundPosition() const { return BoundPositions_[INDEX_RT]; }


private:
	/**
	 * @brief AABB 영역의 끝점을 업데이트합니다.
	 */
	void UpdateBoundPositions();


private:
	/**
	 * @brief AABB 영역의 중심 좌표입니다.
	 */
	Vec2f Center_;


	/**
	 * @brief AABB 영역의 가로 크기입니다.
	 */
	float Width_ = 0.0f;


	/**
	 * @brief AABB 영역의 세로 크기입니다.
	 */
	float Height_ = 0.0f;


	/**
	 * @brief AABB 왼쪽 하단의 인덱스 값입니다.
	 * 
	 * @note LB = Left Bottom
	 */
	static const int32_t INDEX_LB = 0;


	/**
	 * AABB 왼쪽 상단의 인덱스 값입니다.
	 * 
	 * @note LT = Left Top
	 */
	static const int32_t INDEX_LT = 1;


	/**
	 * @brief AABB 오른쪽 하단의 인덱스 값입니다.
	 * 
	 * @note RB = Right Bottom
	 */
	static const int32_t INDEX_RB = 2;


	/**
	 * @brief AABB 오른쪽 상단의 인덱스 값입니다.
	 * 
	 * @note RT = Right Top
	 */
	static const int32_t INDEX_RT = 3;


	/**
	 * @brief AABB 영역의 끝점입니다.
	 */
	std::array<Vec2f, 4> BoundPositions_;
};