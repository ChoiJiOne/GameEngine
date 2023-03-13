#pragma once

#include "Component.h"

class BoundComponent;


/**
 * @brief ��������Ʈ�� �������ϴ� ������Ʈ�Դϴ�.
 */
class SpriteRenderComponent : public Component
{
public:
	/**
	 * @brief ��������Ʈ�� �������ϴ� ������Ʈ�� �������Դϴ�.
	 *
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 */
	SpriteRenderComponent(GameObject* Object);


	/**
	 * @brief ��������Ʈ�� �������ϴ� ������Ʈ�� �������Դϴ�.
	 *
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 * @param Bound �� ������Ʈ���� ������ ��� ���� ������Ʈ�Դϴ�.
	 * @param SpriteTextureID �������� ��������Ʈ �ؽ�ó�� ���̵��Դϴ�.
	 */
	SpriteRenderComponent(GameObject* Object, BoundComponent* Bound, const int32_t& SpriteTextureID);


	/**
	 * @brief ��������Ʈ�� �������ϴ� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~SpriteRenderComponent();


	/**
	 * @brief ��������Ʈ�� �������ϴ� ������Ʈ�� ���� �����ڿ� ���� �����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(SpriteRenderComponent);


	/**
	 * @brief ���� ������Ʈ�� ���� ������Ʈ�� ��� ������ ���Դϴ�.
	 *
	 * @param Bound �� ������Ʈ���� ������ ��� ���� ������Ʈ�Դϴ�.
	 */
	void AttachBoundComponent(BoundComponent* Bound);


	/**
	 * @brief ���� ������Ʈ�� ��������Ʈ �ؽ�ó ���̵� �����մϴ�.
	 * 
	 * @param SpriteTextureID ������ ��������Ʈ �ؽ�ó ���̵��Դϴ�.
	 */
	void SetSpriteTextureID(const int32_t SpriteTextureID);


	/**
	 * @brief ��������Ʈ�� �������ϴ� ������Ʈ�� ������Ʈ�մϴ�.
	 */
	void Tick();


private:
	/**
	 * @brief ��������Ʈ �ؽ�ó�� �������� �� �ִ��� Ȯ���մϴ�.
	 * 
	 * @return �������� �� �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool CanRenderSprite();


private:
	/**
	 * @brief �� ������Ʈ�� ������ ���� ������Ʈ�� ��� �����Դϴ�.
	 */
	BoundComponent* BoundComponent_ = nullptr;


	/**
	 * @brief ��������Ʈ �ؽ�ó�� ���̵� ���Դϴ�.
	 */
	int32_t SpriteTextureID_ = -1;
};