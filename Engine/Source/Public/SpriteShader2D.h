#pragma once

#include "Matrix.hpp"
#include "Shader2D.h"
#include "Vertex.h"

class Texture2D;


/**
 * @brief 2D �ؽ�ó�� �������ϴ� ���̴��Դϴ�.
 */
class SpriteShader2D : public Shader2D
{
public:
	/**
	 * @brief �� ������ ����Ǵ� ���̴� ���� ��� �����Դϴ�.
	 */
	struct EveryFramConstantBuffer
	{
		Matrix4x4F World;
		Matrix4x4F Projection;
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
	SpriteShader2D(ID3D11Device* Device, const std::wstring& VertexShaderSourcePath, const std::wstring& PixelShaderSourcePath);


	/**
	 * @brief 2D �ؽ�ó�� �������ϴ� ���̴��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~SpriteShader2D();


	/**
	 * @brief ���� �����ڿ� ���� �����ڸ� ���������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(SpriteShader2D);


	/**
	 * @brief ���̴����� ����ϴ� ���� ����� �����մϴ�.
	 *
	 * @param World ������ ���� ����Դϴ�.
	 */
	void SetWorldMatrix(const Matrix4x4F& World) { EveryFrameBufferResource_.World = World; }


	/**
	 * @brief ���̴����� ����ϴ� ���� ����� �����մϴ�.
	 *
	 * @param Projection ������ ���� ����Դϴ�.
	 */
	void SetProjectionMatrix(const Matrix4x4F& Projection) { EveryFrameBufferResource_.Projection = Projection; }


	/**
	 * @brief �� ���ۿ� 2D �ؽ�ó�� �׸��ϴ�.
	 * 
	 * @param Context �������� ������ ���ؽ�Ʈ�Դϴ�.
	 * @param Texture ������ ����� �Ǵ� 2D �ؽ�ó�Դϴ�.
	 * @param Center �ؽ�ó�� �߽� ��ǥ�Դϴ�.
	 * @param Width �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param Height �ؽ�ó�� ���� ũ���Դϴ�.
	 */
	void RenderTexture2D(ID3D11DeviceContext* Context, Texture2D& Texture, const Vec3f& Center, float Width, float Height);
	

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
	std::vector<VertexPosUV> QuadTextureVertex_;


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