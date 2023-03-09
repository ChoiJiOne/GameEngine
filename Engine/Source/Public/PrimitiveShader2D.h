#pragma once

#include "Math.hpp"
#include "Shader.h"

#include <unordered_map>
#include <vector>


/**
 * @brief 2D �⺻ ������ �������ϴ� ���̴��Դϴ�.
 */
class PrimitiveShader2D : public Shader
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
	PrimitiveShader2D(ID3D11Device* Device, const std::wstring& VertexShaderSourcePath, const std::wstring& PixelShaderSourcePath);
	

	/**
	 * @brief �⺻ ������ �������ϴ� ���̴��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~PrimitiveShader2D();


	/**
	 * @brief ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(PrimitiveShader2D);


	/**
	 * @brief ���̴����� ����ϴ� ���� ����� �����մϴ�.
	 * 
	 * @param Projection ������ ���� ����Դϴ�.
	 */
	void SetProjectionMatrix(const Matrix4x4F& Projection) { EveryFrameBufferResource_.Projection = Projection; }


	/**
	 * @brief �� ���ۿ� 2D ���� �׸��ϴ�.
	 * 
	 * @param Context �������� ������ ���ؽ�Ʈ�Դϴ�.
	 * @param Position ���� ��ġ�Դϴ�.
	 * @param Color ���� �����Դϴ�.
	 */
	void RenderPoint(
		ID3D11DeviceContext* Context,
		const Vec3f& Position, const Vec4f& Color
	);


	/**
	 * @brief �� ���ۿ� 2D ���� �׸��ϴ�.
	 * 
	 * @param Context �������� ������ ���ؽ�Ʈ�Դϴ�.
	 * @param PositionFrom ���� �������Դϴ�.
	 * @param ColorFrom ���� ������ �����Դϴ�.
	 * @param PositionTo ���� �����Դϴ�.
	 * @param ColorTo ���� ���� �����Դϴ�.
	 */
	void RenderLine(
		ID3D11DeviceContext* Context,
		const Vec3f& PositionFrom, const Vec4f& ColorFrom,
		const Vec3f& PositionTo, const Vec4f& ColorTo
	);


	/**
	 * @brief �� ���ۿ� 2D ä�� �ﰢ���� �׸��ϴ�.
	 * 
	 * @param Context �������� ������ ���ؽ�Ʈ�Դϴ�.
	 * @param PositionFrom �ﰢ�� ������ �������Դϴ�.
	 * @param ColorFrom �ﰢ�� ������ ������ �����Դϴ�.
	 * @param PositionBy �ﰢ�� ������ �߰����Դϴ�.
	 * @param ColorBy �ﰢ�� ������ �߰��� �����Դϴ�.
	 * @param PositionTo �ﰢ�� ������ �����Դϴ�.
	 * @param ColorTo �ﰢ�� ������ ���� �����Դϴ�.
	 */
	void RenderFillTriangle(
		ID3D11DeviceContext* Context,
		const Vec3f& PositionFrom, const Vec4f& ColorFrom,
		const Vec3f& PositionBy, const Vec4f& ColorBy,
		const Vec3f& PositionTo, const Vec4f& ColorTo
	);


	/**
	 * @brief �� ���ۿ� 2D ���̾� ������ �ﰢ���� �׸��ϴ�.
	 * 
	 * @param Context �������� ������ ���ؽ�Ʈ�Դϴ�.
	 * @param PositionFrom �ﰢ�� ������ �������Դϴ�.
	 * @param ColorFrom �ﰢ�� ������ ������ �����Դϴ�.
	 * @param PositionBy �ﰢ�� ������ �߰����Դϴ�.
	 * @param ColorBy �ﰢ�� ������ �߰��� �����Դϴ�.
	 * @param PositionTo �ﰢ�� ������ �����Դϴ�.
	 * @param ColorTo �ﰢ�� ������ ���� �����Դϴ�.
	 */
	void RenderWireframeTriangle(
		ID3D11DeviceContext* Context,
		const Vec3f& PositionFrom, const Vec4f& ColorFrom,
		const Vec3f& PositionBy, const Vec4f& ColorBy,
		const Vec3f& PositionTo, const Vec4f& ColorTo
	);


	/**
	 * @brief �� ���ۿ� 2D ä�� �簢���� �׸��ϴ�.
	 * 
	 * @param Context �������� ������ ���ؽ�Ʈ�Դϴ�.
	 * @param Center �簢���� �߽� ��ǥ�Դϴ�.
	 * @param Color �簢���� �����Դϴ�.
	 * @param Width �簢���� ���� ũ���Դϴ�.
	 * @param Height �簢���� ���� ũ���Դϴ�.
	 * @param Rotate �簢���� ȸ�� �����Դϴ�. �⺻ ���� 0.0�Դϴ�.
	 */
	void RenderFillQuad(ID3D11DeviceContext* Context, const Vec3f& Center, const Vec4f& Color, float Width, float Height, float Rotate = 0.0f);


	/**
	 * @brief �� ���ۿ� 2D ���̾� ������ �簢���� �׸��ϴ�.
	 * 
	 * @param Context �������� ������ ���ؽ�Ʈ�Դϴ�.
	 * @param Center �簢���� �߽� ��ǥ�Դϴ�.
	 * @param Color �簢���� �����Դϴ�.
	 * @param Width �簢���� ���� ũ���Դϴ�.
	 * @param Height �簢���� ���� ũ���Դϴ�.
	 * @param Rotate �簢���� ȸ�� �����Դϴ�. �⺻ ���� 0.0�Դϴ�.
	 */
	void RenderWireframeQuad(ID3D11DeviceContext* Context, const Vec3f& Center, const Vec4f& Color, float Width, float Height, float Rotate = 0.0f);


	/**
	 * @brief �� ���ۿ� ä�� ���� �׸��ϴ�.
	 * 
	 * @param Context �������� ������ ���ؽ�Ʈ�Դϴ�.
	 * @param Center ���� �߽� ��ǥ�Դϴ�.
	 * @param Color ���� �����Դϴ�.
	 * @param Radius ���� ������ �����Դϴ�.
	 */
	void RenderFillCircle(ID3D11DeviceContext* Context, const Vec3f& Center, const Vec4f& Color, float Radius);


	/**
	 * @brief �� ���ۿ� ���̾������� ���� �׸��ϴ�.
	 * 
	 * @param Context �������� ������ ���ؽ�Ʈ�Դϴ�.
	 * @param Center ���� �߽� ��ǥ�Դϴ�.
	 * @param Color ���� �����Դϴ�.
	 * @param Radius ���� ������ �����Դϴ�.
	 */
	void RenderWireframeCircle(ID3D11DeviceContext* Context, const Vec3f& Center, const Vec4f& Color, float Radius);


private:
	/**
	 * @brief ���� ������ Ÿ���Դϴ�.
	 */
	enum class ERenderType
	{
		POINT    = 0,
		LINE     = 1,
		TRIANGLE = 2
	};


	/**
	 * @brief �� ������ ����Ǵ� ���̴� ���� ��� �����Դϴ�.
	 */
	struct EveryFramConstantBuffer
	{
		Matrix4x4F Projection;
	};


	/**
	 * @brief ���� ���ۿ� �ε��� ���۸� �����մϴ�.
	 * 
	 * @param Device ���� ���� �� ����� ����̽��Դϴ�.
	 * @param Name ���� ���ۿ� �ε��� ������ �̸��Դϴ�.
	 * @param Vertices ���� ���� ���� �� ������ �����Դϴ�.
	 * @param Indices �ε��� ���� ���� �� ������ �ε����Դϴ�.
	 * 
	 * @throws 
	 * ���� ���ۿ� �ε��� ������ �̸��� �̹� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * ���� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void BuildVertexAndIndexBuffer(ID3D11Device* Device, const std::string& Name, const std::vector<Vertex::PositionColor>& Vertices, const std::vector<uint32_t>& Indices);


	/**
	 * @brief �⺻ ������ ȭ�鿡 �׸��ϴ�.
	 * 
	 * @param Context �������� ������ ���ؽ�Ʈ�Դϴ�.
	 * @param PrimitiveSignature �⺻ ������ ���� �ñ״�ó�Դϴ�.
	 * @param RenderType ������ Ÿ���Դϴ�.
	 */
	void RenderPrimitive(ID3D11DeviceContext* Context, const std::string& PrimitiveSignature, const ERenderType& RenderType);


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
	 * @brief �⺻ ������ ���� ����Դϴ�.
	 */
	std::unordered_map<std::string, std::vector<Vertex::PositionColor>> PrimitiveVertex_;


	/**
	 * @brief �⺻ ������ ���� �����Դϴ�.
	 */
	std::unordered_map<std::string, ID3D11Buffer*> PrimitiveVertexBuffer_;


	/**
	 * @brief �⺻ ������ �ε��� ����Դϴ�.
	 */
	std::unordered_map<std::string, std::vector<uint32_t>> PrimitiveIndex_;


	/**
	 * @brief �⺻ ������ �ε��� �����Դϴ�.
	 */
	std::unordered_map<std::string, ID3D11Buffer*> PrimitiveIndexBuffer_;
};