#pragma once

#include "Math.hpp"
#include "Shader.h"

class Font;


/**
 * @brief 2D �ؽ�Ʈ�� �������ϴ� ���̴��Դϴ�.
 */
class TextShader2D : public Shader
{
public:
	/**
	 * @brief �� ������ ����Ǵ� ���̴� ���� ��� �����Դϴ�.
	 */
	struct EveryFramConstantBuffer
	{
		Matrix4x4F Projection;
	};


	/**
	 * @brief �ؽ�Ʈ�� ������ ��Ÿ���� ��� �����Դϴ�.
	 */
	struct TextColorConstantBuffer
	{
		Vec4f TextColor;
	};


public:
	/**
	 * @brief ���̴��� �������ϰ� ���� ���̴��� �ȼ� ���̴��� �����մϴ�.
	 *
	 * @param Device ���̴� ���ҽ��� ������ �� ����� ����̽��Դϴ�.
	 * @param VertexShaderSourcePath ���� ���̴� �ҽ� ������ ����Դϴ�.
	 * @param PixelShaderSourcePath �ȼ� ���̴� �ҽ� ������ ����Դϴ�.
	 *
	 * @throws
	 * ���̴� �����Ͽ� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * ���̴� ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	TextShader2D(ID3D11Device* Device, const std::wstring& VertexShaderSourcePath, const std::wstring& PixelShaderSourcePath);


	/**
	 * @brief 2D �ؽ�Ʈ�� �������ϴ� ���̴��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~TextShader2D();


	/**
	 * @brief ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(TextShader2D);


	/**
	 * @brief ���̴����� ����ϴ� ���� ����� �����մϴ�.
	 *
	 * @param Projection ������ ���� ����Դϴ�.
	 */
	void SetProjectionMatrix(const Matrix4x4F& Projection) { EveryFrameBufferResource_.Projection = Projection; }


	/**
	 * @brief �� ���ۿ� 2D �ؽ�Ʈ�� �׸��ϴ�.
	 *
	 * @param Context �������� ������ ���ؽ�Ʈ�Դϴ�.
	 * @param FontResource �ؽ�Ʈ�� �������� �� ������ ��Ʈ ���ҽ��Դϴ�.
	 * @param Text �������� �ؽ�Ʈ�Դϴ�.
	 * @param Center �ؽ�ó�� �߽� ��ǥ�Դϴ�.
	 * @param Color �ؽ�Ʈ�� �����Դϴ�.
	 */
	void RenderText2D(ID3D11DeviceContext* Context, Font& FontResource, const std::wstring& Text, const Vec3f& Center, const Vec4f& Color);


private:
	/**
	 * @brief �� ������ ����Ǵ� ���̴� ���� ���ҽ��Դϴ�.
	 */
	EveryFramConstantBuffer EveryFrameBufferResource_;


	/**
	 * @brief �� ������ ����Ǵ� ���̴� ���� ��� �����Դϴ�.
	 */
	ID3D11Buffer* EveryFrameBuffer_ = nullptr;


	/**
	 * @brief �ؽ�Ʈ �����Դϴ�.
	 */
	TextColorConstantBuffer TextColorBufferResource_;


	/**
	 * @brief �ؽ�Ʈ ������ ��Ÿ���� ��� �����Դϴ�.
	 */
	ID3D11Buffer* TextColorBuffer_ = nullptr;


	/**
	 * @brief �ؽ�ó�� ���� ����Դϴ�.
	 */
	std::vector<Vertex::PositionUV> CharacterVertex_;


	/**
	 * @brief �ؽ�ó�� ���� �����Դϴ�.
	 */
	ID3D11Buffer* CharacterVertexBuffer_ = nullptr;


	/**
	 * @brief �ؽ�ó�� �ε��� ����Դϴ�.
	 */
	std::vector<uint32_t> CharacterIndex_;


	/**
	 * @brief �ؽ�ó�� �ε��� �����Դϴ�.
	 */
	ID3D11Buffer* CharacterIndexBuffer_ = nullptr;


	/**
	 * @brief ���� �ؽ�ó ���÷��Դϴ�.
	 */
	ID3D11SamplerState* LinearSampler_ = nullptr;
};