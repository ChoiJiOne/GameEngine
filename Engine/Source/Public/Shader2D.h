#pragma once

#include "Shader.h"


/**
 * @brief 2D �������� �����ϴ� ���̴��� �������̽��Դϴ�.
 */
class Shader2D : public Shader
{
public:
	/**
	 * @brief 2D �������� �����ϴ� ���̴��� ����Ʈ �������Դϴ�.
	 */
	Shader2D() = default;


	/**
	 * @brief 2D �������� �����ϴ� ���̴��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Shader2D();


	/**
	 * @brief ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Shader2D);


protected:
	/**
	 * @brief ���� ���̴� �ҽ� ���ҽ��Դϴ�.
	 */
	ID3DBlob* VertexShaderSource_ = nullptr;


	/**
	 * @brief ���� ���̴� ���ҽ��Դϴ�.
	 */
	ID3D11VertexShader* VertexShader_ = nullptr;


	/**
	 * @brief �ȼ� ���̴� �ҽ� ���ҽ��Դϴ�.
	 */
	ID3DBlob* PixelShaderSource_ = nullptr;


	/**
	 * @brief �ȼ� ���̴� ���ҽ��Դϴ�.
	 */
	ID3D11PixelShader* PixelShader_ = nullptr;


	/**
	 * @brief ������ ������������ ���� �����͸� �����մϴ�.
	 *
	 * @note https://learn.microsoft.com/en-us/windows/win32/api/d3d11/nn-d3d11-id3d11inputlayout
	 */
	ID3D11InputLayout* InputLayout_ = nullptr;
};