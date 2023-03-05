#pragma once

#include "Vector.hpp"
#include "GraphicsComponent.h"


/**
 * @brief ��������Ʈ�� �������ϴ� ������Ʈ�Դϴ�.
 */
class SpriteRenderComponent : public GraphicsComponent
{
public:
	/**
	 * @brief ���� ������Ʈ�� ������ ��������Ʈ ���� ������Ʈ�� �������Դϴ�.
	 *
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 * @param TextureSignature ��������Ʈ�� �����ϴ� �ؽ�ó�� �ñ״�ó ���Դϴ�.
	 * @param Position ��������Ʈ�� �߽� ��ǥ�Դϴ�.
	 * @param Width ��������Ʈ�� ���� ũ���Դϴ�.
	 * @param Height ��������Ʈ�� ���� ũ���Դϴ�.
	 */
	SpriteRenderComponent(
		GameObject* Object,
		const std::string& TextureSignature,
		const Vec2f& Position,
		const float& Width,
		const float& Height
	) : GraphicsComponent(Object),
		TextureSignature_(TextureSignature),
		Position_(Position),
		Width_(Width),
		Height_(Height)
	{
	}


	/**
	 * @brief ���� ������Ʈ�� �����ϴ� ��������Ʈ ���� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~SpriteRenderComponent() {}


	/**
	 * @brief ������Ʈ�� ���� ������ �� ���Կ����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(SpriteRenderComponent);


	/**
	 * @brief ��������Ʈ ���� ������Ʈ�� ������Ʈ�մϴ�.
	 */
	virtual void Tick();


	/**
	 * @brief ��������Ʈ�� �����ϴ� �ؽ�ó�� �ñ״�ó ���� �����մϴ�.
	 * 
	 * @param TextureSignature ������ �ؽ�ó �ñ״�ó ���Դϴ�.
	 */
	void SetTextureSignature(const std::string& TextureSignature) { TextureSignature_ = TextureSignature; }


	/**
	 * @brief ��������Ʈ�� �߽� ��ǥ�� �����մϴ�
	 * 
	 * @param Position ������ ��������Ʈ�� �߽� ��ǥ�Դϴ�.
	 */
	void SetPosition(const Vec2f& Position) { Position_ = Position; }


	/**
	 * @brief ��������Ʈ�� ���� ũ�⸦ �����մϴ�.
	 * 
	 * @param Width ������ ��������Ʈ�� ���� ũ���Դϴ�.
	 */
	void SetWidth(const float& Width) { Width_ = Width; }


	/**
	 * @brief ��������Ʈ�� ���� ũ�⸦ �����մϴ�.
	 * 
	 * @param Width ������ ��������Ʈ�� ���� ũ���Դϴ�.
	 */
	void SetHeight(const float& Height) { Height_ = Height; }


private:
	/**
	 * @brief ��������Ʈ�� �����ϴ� �ؽ�ó�� �ñ״�ó ���Դϴ�.
	 */
	std::string TextureSignature_;


	/**
	 * @brief ��������Ʈ�� �߽� ��ǥ�Դϴ�.
	 */
	Vec2f Position_;


	/**
	 * @brief ��������Ʈ�� ���� ũ���Դϴ�.
	 */
	float Width_;


	/**
	 * @brief ��������Ʈ�� ���� ũ���Դϴ�.
	 */
	float Height_;
};