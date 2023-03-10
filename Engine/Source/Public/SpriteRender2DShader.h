#pragma once

#include "Math.hpp"
#include "Shader.h"

class Texture2D;


/**
 * @brief 2D �ؽ�ó�� �������ϴ� ���̴��Դϴ�.
 */
class SpriteRender2DShader : public Shader
{
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
	SpriteRender2DShader(ID3D11Device* Device, const std::wstring& VertexShaderSourcePath, const std::wstring& PixelShaderSourcePath);


	/**
	 * @brief 2D �ؽ�ó�� �������ϴ� ���̴��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~SpriteRender2DShader();


	/**
	 * @brief ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(SpriteRender2DShader);


	/**
	 * @brief ���̴����� ����ϴ� ���� ����� �����մϴ�.
	 *
	 * @param Projection ������ ���� ����Դϴ�.
	 */
	void SetProjectionMatrix(const Matrix4x4F& Projection) { EveryFrameBufferResource_.Projection = Projection; }


	/**
	 * @brief �� ���ۿ� 2D ��������Ʈ�� �׸��ϴ�.
	 * 
	 * @ntoe ȸ������ ���� �����Դϴ�.
	 * 
	 * @param Context �������� ������ ���ؽ�Ʈ�Դϴ�.
	 * @param Texture ������ ����� �Ǵ� 2D ��������Ʈ�� �ؽ�ó�Դϴ�.
	 * @param Center �ؽ�ó�� �߽� ��ǥ�Դϴ�.
	 * @param Width �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param Height �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param Rotate �ؽ�ó�� ȸ�� �����Դϴ�. �⺻ ���� 0.0�Դϴ�.
	 */
	void RenderSprite2D(ID3D11DeviceContext* Context, Texture2D& Texture, const Vec3f& Center, float Width, float Height, float Rotate = 0.0f);
	

private:
	/**
	 * @brief �� ������ ����Ǵ� ���̴� ���� ��� �����Դϴ�.
	 */
	struct EveryFramConstantBuffer
	{
		Matrix4x4F Projection;
	};


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
	 * @brief �ؽ�ó�� ���� ����Դϴ�.
	 */
	std::vector<Vertex::PositionUV> QuadTextureVertex_;


	/**
	 * @brief �ؽ�ó�� ���� �����Դϴ�.
	 */
	ID3D11Buffer* QuadTextureVertexBuffer_ = nullptr;


	/**
	 * @brief �ؽ�ó�� �ε��� ����Դϴ�.
	 */
	std::vector<uint32_t> QuadTextureIndex_;


	/**
	 * @brief �ؽ�ó�� �ε��� �����Դϴ�.
	 */
	ID3D11Buffer* QuadTextureIndexBuffer_ = nullptr;


	/**
	 * @brief ���� �ؽ�ó ���÷��Դϴ�.
	 */
	ID3D11SamplerState* LinearSampler_ = nullptr;
};