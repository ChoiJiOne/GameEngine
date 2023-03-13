#pragma once

#include "BoundComponent.h"
#include "Math.hpp"


/**
 * @brief 게임 오브젝트의 원 영역을 나타내는 컴포넌트입니다.
 */
class CircleComponent : public BoundComponent
{
public:
	/**
	 * @brief 게임 오브젝트의 영역 중 원 영역을 나타내는 컴포넌트의 생성자입니다.
	 *
	 * @param Object 이 컴포넌트를 소유하는 오브젝트의 포인터 값입니다.
	 */
	CircleComponent(GameObject* Object);


	/**
	 * @brief 게임 오브젝트의 영역 중 원 영역을 나타내는 컴포넌트의 생성자입니다.
	 * 
	 * @param Object 이 컴포넌트를 소유하는 오브젝트의 포인터 값입니다.
	 * @param Center 원 영역의 중심 좌표입니다.
	 * @param Radius 원 영역의 반지름 길이입니다.
	 */
	CircleComponent(GameObject* Object, const Vec2f& Center, const float& Radius);


	/**
	 * @brief 게임 오브젝트의 영역 중 원 영역을 나타내는 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~CircleComponent();


	/**
	 * @brief 게임 오브젝트의 영역 중 원 영역을 나타내는 컴포넌트의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(CircleComponent);


	/**
	 * @brief 원 영역의 중심 좌표를 얻습니다.
	 *
	 * @return 원 영역의 중심 좌표를 반환합니다.
	 */
	Vec2f GetCenter() const { return Center_; }


	/**
	 * @brief 원 영역의 중심 좌표를 설정합니다.
	 *
	 * @param Center 설정할 원 영역의 중심좌표입니다.
	 */
	void SetCenter(const Vec2f& Center) { Center_ = Center; }


	/**
	 * @brief 원 영역의 반지름 크기를 얻습니다.
	 *
	 * @return 원 영역의 반지름 크기를 반환합니다.
	 */
	float GetRadius() const { return Radius_; }


	/**
	 * @brief 원 영역의 반지름 크기를 설정합니다.
	 *
	 * @param Width 설정할 원 영역의 반지름 크기입니다.
	 */
	void SetRadius(const float& Radius) { Radius_ = Radius; }


private:
	/**
	 * @brief 원 영역의 중심 좌표입니다.
	 */
	Vec2f Center_;


	/**
	 * @brief 원 영역의 반지름 길이입니다.
	 */
	float Radius_ = 0.0f;
};