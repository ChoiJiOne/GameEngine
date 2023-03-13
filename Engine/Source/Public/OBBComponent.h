#pragma once

#include "BoundComponent.h"
#include "Math.hpp"

#include <array>


/**
 * @brief 게임 오브젝트의 OBB 컴포넌트입니다.
 */
class OBBComponent : public BoundComponent
{
public:
	/**
	 * @brief 게임 오브젝트의 영역 중 OBB 컴포넌트의 생성자입니다.
	 *
	 * @param Object 이 컴포넌트를 소유하는 오브젝트의 포인터 값입니다.
	 */
	OBBComponent(GameObject* Object);


	/**
	 * @brief 게임 오브젝트의 영역 중 OBB 컴포넌트의 생성자입니다.
	 *
	 * @param Object 이 컴포넌트를 소유하는 오브젝트의 포인터 값입니다.
	 * @param Center OBB의 중심 좌표입니다.
	 * @param Width OBB의 가로 크기입니다.
	 * @param Height OBB의 세로 크기입니다.
	 * @param Rotate OBB 축의 각도입니다.
	 */
	OBBComponent(GameObject* Object, const Vec2f& Center, const float& Width, const float& Height, const float& Rotate);


	/**
	 * @brief 게임 오브젝트의 영역 중 OBB 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~OBBComponent();


	/**
	 * @brief 게임 오브젝트의 영역 중 OBB 컴포넌트의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(OBBComponent);


	/**
	 * @brief OBB 영역의 중심 좌표를 얻습니다.
	 *
	 * @return OBB 영역의 중심 좌표를 반환합니다.
	 */
	Vec2f GetCenter() const { return Center_; }


	/**
	 * @brief OBB 영역의 중심 좌표를 설정합니다.
	 *
	 * @param Center 설정할 OBB 영역의 중심좌표입니다.
	 */
	void SetCenter(const Vec2f& Center);


	/**
	 * @brief OBB 영역의 가로 크기를 얻습니다.
	 *
	 * @return OBB 영역의 가로 크기를 반환합니다.
	 */
	float GetWidth() const { return Width_; }


	/**
	 * @brief OBB 영역의 가로 크기를 설정합니다.
	 *
	 * @param Width 설정할 OBB 영역의 가로 크기입니다.
	 */
	void SetWidth(const float& Width);


	/**
	 * @brief OBB 영역의 세로 크기를 얻습니다.
	 *
	 * @return OBB 영역의 세로 크기를 반환합니다.
	 */
	float GetHeight() const { return Height_; }


	/**
	 * @brief OBB 영역의 세로 크기를 설정합니다.
	 *
	 * @param Height 설정할 OBB 영역의 세로 크기입니다.
	 */
	void SetHeight(const float& Height);


	/**
	 * @brief OBB 영역 축의 회전각을 얻습니다.
	 * 
	 * @return OBB 영역 축의 회전각을 반환합니다.
	 */
	float GetRotate() const { return Rotate_; }


	/**
	 * @brief OBB 영역 축의 회전각을 설정합니다.
	 * 
	 * @param Rotate 설정할 OBB 영역 축의 회전각입니다.
	 */
	void SetRotate(const float& Rotate);


	/**
	 * @brief OBB 영역의 끝 점을 얻습니다.
	 *
	 * @note 이 메서드를 이용하면 끝 점의 값은 변경할 수 없습니다.
	 *
	 * @return OBB 영역의 끝 점들의 상수 참조자를 반환합니다.
	 */
	const std::array<Vec2f, 4>& GetBoundPositions() const { return BoundPositions_; }


private:
	/**
	 * @brief OBB 영역의 끝점을 업데이트합니다.
	 */
	void UpdateBoundPositions();


private:
	/**
	 * @brief OBB 영역의 중심 좌표입니다.
	 */
	Vec2f Center_;


	/**
	 * @brief OBB 영역의 가로 크기입니다.
	 */
	float Width_ = 0.0f;


	/**
	 * @brief OBB 영역의 세로 크기입니다.
	 */
	float Height_ = 0.0f;


	/**
	 * @brief OBB 영역의 회전 축의 각도입니다.
	 */
	float Rotate_ = 0.0f;


	/**
	 * @brief OBB 왼쪽 하단의 인덱스 값입니다.
	 *
	 * @note LB = Left Bottom
	 */
	static const int32_t INDEX_LB = 0;


	/**
	 * OBB 왼쪽 상단의 인덱스 값입니다.
	 *
	 * @note LT = Left Top
	 */
	static const int32_t INDEX_LT = 1;


	/**
	 * @brief OBB 오른쪽 하단의 인덱스 값입니다.
	 *
	 * @note RB = Right Bottom
	 */
	static const int32_t INDEX_RB = 2;


	/**
	 * @brief OBB 오른쪽 상단의 인덱스 값입니다.
	 *
	 * @note RT = Right Top
	 */
	static const int32_t INDEX_RT = 3;


	/**
	 * @brief OBB 영역의 끝점입니다.
	 */
	std::array<Vec2f, 4> BoundPositions_;
};