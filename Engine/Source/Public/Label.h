#pragma once

#include "Color.h"
#include "Vector.hpp"
#include "GameObject.h"


/**
 * @brief ���� ���� �� ������Ʈ�Դϴ�.
 */
class Label : public GameObject
{
public:
	/**
	 * @brief ���� ���� �� �������Դϴ�.
	 * 
	 * @note �ؽ�Ʈ ���ڿ��� �ݵ�� �ƽ�Ű �ڵ� ���� ���� �ִ� ���ڵ�� �����Ǿ�� �մϴ�.
	 *
	 * @param Signature ���� ���� �ĺ����Դϴ�.
	 * @param Text ���� ���� �ؽ�Ʈ�Դϴ�.
	 * @param FontSignature ���� ���� ���ڿ��� ��Ʈ �ñ״�ó�Դϴ�.
	 * @param Position ���� ���� ���� �� ��ġ�Դϴ�.
	 * @param Color �ؽ�Ʈ�� �����Դϴ�.
	 */
	Label(
		const std::string& Signature, 
		const std::wstring& Text, 
		const std::string& FontSignature,
		const Vec2f& Position, 
		const LinearColor& Color
	);


	/**
	 * @brief ���� ���� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Label() {}


	/**
	 * @brief ��������� ���� �����ڿ� ���� �����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Label);


	/**
	 * @brief ���� �󺧸� ������Ʈ�մϴ�.
	 * 
	 * @param DeltaSeconds �ʴ��� ��Ÿ �ð����Դϴ�.
	 */
	virtual void Tick(float DeltaSeconds) override;


	/**
	 * @brief ���� ���� ���� �� ��ġ�� �����մϴ�.
	 *  
	 * @param Position ������ ���� ���� ��ġ�Դϴ�.
	 */
	void SetPosition(const Vec2f& Position) { Position_ = Position; }


	/**
	 * @brief ���� �󺧸� �����մϴ�.
	 *
	 * @note �ؽ�Ʈ ���ڿ��� �ݵ�� �ƽ�Ű �ڵ� ���� ���� �ִ� ���ڵ�� �����Ǿ�� �մϴ�.
	 *
	 * @param Text ������ ���� ���Դϴ�.
	 */
	void SetText(const std::wstring& Text) { Text_ = Text; }


	/**
	 * @brief ���� ���� ������ �����մϴ�.
	 * 
	 * @param Color ������ ���� ���� �����Դϴ�.
	 */
	void SetColor(const LinearColor& Color) { Color_ = Color; }


private:
	/**
	 * @brief ȭ�鿡 ǥ�õ� ���� ���Դϴ�.
	 */
	std::wstring Text_;


	/**
	 * @brief ���� �� ���ڿ��� ��Ʈ �ñ״�ó�Դϴ�.
	 */
	std::string FontSignature_;


	/**
	 * @brief ���� �� ǥ�õ� ���� ���� �߽� ��ġ�Դϴ�.
	 */
	Vec2f Position_;


	/**
	 * @brief ���忡 ǥ�õ� ���� �� �����Դϴ�.
	 */
	LinearColor Color_;
};