#pragma once

#include "Component.h"

class BoundComponent;


/**
 * @brief 스프라이트를 렌더링하는 컴포넌트입니다.
 */
class SpriteRenderComponent : public Component
{
public:
	/**
	 * @brief 스프라이트를 렌더링하는 컴포넌트의 생성자입니다.
	 *
	 * @param Object 이 컴포넌트를 소유하는 오브젝트의 포인터 값입니다.
	 */
	SpriteRenderComponent(GameObject* Object);


	/**
	 * @brief 스프라이트를 렌더링하는 컴포넌트의 생성자입니다.
	 *
	 * @param Object 이 컴포넌트를 소유하는 오브젝트의 포인터 값입니다.
	 * @param Bound 이 컴포넌트에서 참조할 경계 영역 컴포넌트입니다.
	 * @param SpriteTextureID 렌더링할 스프라이트 텍스처의 아이디입니다.
	 */
	SpriteRenderComponent(GameObject* Object, BoundComponent* Bound, const int32_t& SpriteTextureID);


	/**
	 * @brief 스프라이트를 렌더링하는 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~SpriteRenderComponent();


	/**
	 * @brief 스프라이트를 렌더링하는 컴포넌트의 복사 생성자와 대입 연산자를 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(SpriteRenderComponent);


	/**
	 * @brief 현재 컴포넌트에 게임 오브젝트의 경계 영역을 붙입니다.
	 *
	 * @param Bound 이 컴포넌트에서 참조할 경계 영역 컴포넌트입니다.
	 */
	void AttachBoundComponent(BoundComponent* Bound);


	/**
	 * @brief 현재 컴포넌트에 스프라이트 텍스처 아이디를 설정합니다.
	 * 
	 * @param SpriteTextureID 설정할 스프라이트 텍스처 아이디입니다.
	 */
	void SetSpriteTextureID(const int32_t SpriteTextureID);


	/**
	 * @brief 스프라이트를 렌더링하는 컴포넌트를 업데이트합니다.
	 */
	void Tick();


private:
	/**
	 * @brief 스프라이트 텍스처를 렌더링할 수 있는지 확인합니다.
	 * 
	 * @return 렌더링할 수 있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool CanRenderSprite();


private:
	/**
	 * @brief 이 컴포넌트를 소유한 게임 오브젝트의 경계 영역입니다.
	 */
	BoundComponent* BoundComponent_ = nullptr;


	/**
	 * @brief 스프라이트 텍스처의 아이디 값입니다.
	 */
	int32_t SpriteTextureID_ = -1;
};