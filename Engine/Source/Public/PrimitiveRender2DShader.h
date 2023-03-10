#pragma once

#include "Math.hpp"
#include "Shader.h"

#include <unordered_map>
#include <vector>


/**
 * @brief 2D 기본 도형을 렌더링하는 셰이더입니다.
 */
class PrimitiveRender2DShader : public Shader
{
public:
	/**
	 * @brief 셰이더를 컴파일하고 정점 셰이더와 픽셀 셰이더를 생성합니다.
	 *
	 * @param Device 셰이더 리소스를 생성할 때 사용할 디바이스입니다.
	 * @param VertexShaderSourcePath 정점 셰이더 소스 파일의 경로입니다.
	 * @param PixelShaderSourcePath 픽셀 셰이더 소스 파일의 경로입니다.
	 *
	 * @throws
	 * 셰이더 컴파일에 실패하면 C++ 표준 예외를 던집니다.
	 * 셰이더 리소스 생성에 실패하면 C++ 표준 예외를 던집니다.
	 */
	PrimitiveRender2DShader(ID3D11Device* Device, const std::wstring& VertexShaderSourcePath, const std::wstring& PixelShaderSourcePath);
	

	/**
	 * @brief 기본 도형을 렌더링하는 셰이더의 가상 소멸자입니다.
	 */
	virtual ~PrimitiveRender2DShader();


	/**
	 * @brief 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(PrimitiveRender2DShader);


	/**
	 * @brief 셰이더에서 사용하는 투영 행렬을 설정합니다.
	 * 
	 * @param Projection 설정할 투영 행렬입니다.
	 */
	void SetProjectionMatrix(const Matrix4x4F& Projection) { EveryFrameBufferResource_.Projection = Projection; }


	/**
	 * @brief 백 버퍼에 2D 점을 그립니다.
	 * 
	 * @param Context 렌더링을 수행할 컨텍스트입니다.
	 * @param Position 점의 위치입니다.
	 * @param Color 점의 색상입니다.
	 */
	void RenderPoint(
		ID3D11DeviceContext* Context,
		const Vec3f& Position, const Vec4f& Color
	);


	/**
	 * @brief 백 버퍼에 2D 선을 그립니다.
	 * 
	 * @param Context 렌더링을 수행할 컨텍스트입니다.
	 * @param PositionFrom 선의 시작점입니다.
	 * @param ColorFrom 선의 시작점 색상입니다.
	 * @param PositionTo 선의 끝점입니다.
	 * @param ColorTo 선의 끝점 색상입니다.
	 */
	void RenderLine(
		ID3D11DeviceContext* Context,
		const Vec3f& PositionFrom, const Vec4f& ColorFrom,
		const Vec3f& PositionTo, const Vec4f& ColorTo
	);


	/**
	 * @brief 백 버퍼에 2D 채움 삼각형을 그립니다.
	 * 
	 * @param Context 렌더링을 수행할 컨텍스트입니다.
	 * @param PositionFrom 삼각형 정점의 시작점입니다.
	 * @param ColorFrom 삼각형 정점의 시작점 색상입니다.
	 * @param PositionBy 삼각형 정점의 중간점입니다.
	 * @param ColorBy 삼각형 정점의 중간점 색상입니다.
	 * @param PositionTo 삼각형 정점의 끝점입니다.
	 * @param ColorTo 삼각형 정점의 끝점 색상입니다.
	 */
	void RenderFillTriangle(
		ID3D11DeviceContext* Context,
		const Vec3f& PositionFrom, const Vec4f& ColorFrom,
		const Vec3f& PositionBy, const Vec4f& ColorBy,
		const Vec3f& PositionTo, const Vec4f& ColorTo
	);


	/**
	 * @brief 백 버퍼에 2D 와이어 프레임 삼각형을 그립니다.
	 * 
	 * @param Context 렌더링을 수행할 컨텍스트입니다.
	 * @param PositionFrom 삼각형 정점의 시작점입니다.
	 * @param ColorFrom 삼각형 정점의 시작점 색상입니다.
	 * @param PositionBy 삼각형 정점의 중간점입니다.
	 * @param ColorBy 삼각형 정점의 중간점 색상입니다.
	 * @param PositionTo 삼각형 정점의 끝점입니다.
	 * @param ColorTo 삼각형 정점의 끝점 색상입니다.
	 */
	void RenderWireframeTriangle(
		ID3D11DeviceContext* Context,
		const Vec3f& PositionFrom, const Vec4f& ColorFrom,
		const Vec3f& PositionBy, const Vec4f& ColorBy,
		const Vec3f& PositionTo, const Vec4f& ColorTo
	);


	/**
	 * @brief 백 버퍼에 2D 채움 사각형을 그립니다.
	 * 
	 * @param Context 렌더링을 수행할 컨텍스트입니다.
	 * @param Center 사각형의 중심 좌표입니다.
	 * @param Color 사각형의 색상입니다.
	 * @param Width 사각형의 가로 크기입니다.
	 * @param Height 사각형의 세로 크기입니다.
	 * @param Rotate 사각형의 회전 각도입니다. 기본 값은 0.0입니다.
	 */
	void RenderFillQuad(ID3D11DeviceContext* Context, const Vec3f& Center, const Vec4f& Color, float Width, float Height, float Rotate = 0.0f);


	/**
	 * @brief 백 버퍼에 2D 와이어 프레임 사각형을 그립니다.
	 * 
	 * @param Context 렌더링을 수행할 컨텍스트입니다.
	 * @param Center 사각형의 중심 좌표입니다.
	 * @param Color 사각형의 색상입니다.
	 * @param Width 사각형의 가로 크기입니다.
	 * @param Height 사각형의 세로 크기입니다.
	 * @param Rotate 사각형의 회전 각도입니다. 기본 값은 0.0입니다.
	 */
	void RenderWireframeQuad(ID3D11DeviceContext* Context, const Vec3f& Center, const Vec4f& Color, float Width, float Height, float Rotate = 0.0f);


	/**
	 * @brief 백 버퍼에 채움 원을 그립니다.
	 * 
	 * @param Context 렌더링을 수행할 컨텍스트입니다.
	 * @param Center 원의 중심 좌표입니다.
	 * @param Color 원의 색상입니다.
	 * @param Radius 원의 반지름 길이입니다.
	 */
	void RenderFillCircle(ID3D11DeviceContext* Context, const Vec3f& Center, const Vec4f& Color, float Radius);


	/**
	 * @brief 백 버퍼에 와이어프레임 원을 그립니다.
	 * 
	 * @param Context 렌더링을 수행할 컨텍스트입니다.
	 * @param Center 원의 중심 좌표입니다.
	 * @param Color 원의 색상입니다.
	 * @param Radius 원의 반지름 길이입니다.
	 */
	void RenderWireframeCircle(ID3D11DeviceContext* Context, const Vec3f& Center, const Vec4f& Color, float Radius);


private:
	/**
	 * @brief 내부 렌더링 타입입니다.
	 */
	enum class ERenderType
	{
		POINT    = 0,
		LINE     = 1,
		TRIANGLE = 2
	};


	/**
	 * @brief 매 프레임 변경되는 셰이더 내의 상수 버퍼입니다.
	 */
	struct EveryFramConstantBuffer
	{
		Matrix4x4F Projection;
	};


	/**
	 * @brief 정점 버퍼와 인덱스 버퍼를 구성합니다.
	 * 
	 * @param Device 버퍼 생성 시 사용할 디바이스입니다.
	 * @param Name 정점 버퍼와 인덱스 버퍼이 이름입니다.
	 * @param Vertices 정점 버퍼 구성 시 참조할 정점입니다.
	 * @param Indices 인덱스 버퍼 구성 시 참조할 인덱스입니다.
	 * 
	 * @throws 
	 * 정점 버퍼와 인덱스 버퍼의 이름이 이미 존재하면 C++ 표준 예외를 던집니다.
	 * 버퍼 구성에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void BuildVertexAndIndexBuffer(ID3D11Device* Device, const std::string& Name, const std::vector<Vertex::PositionColor>& Vertices, const std::vector<uint32_t>& Indices);


	/**
	 * @brief 기본 도형을 화면에 그립니다.
	 * 
	 * @param Context 렌더링을 수행할 컨텍스트입니다.
	 * @param PrimitiveSignature 기본 도형의 정점 시그니처입니다.
	 * @param RenderType 렌더링 타입입니다.
	 */
	void RenderPrimitive(ID3D11DeviceContext* Context, const std::string& PrimitiveSignature, const ERenderType& RenderType);


private:
	/**
	 * @brief 매 프레임 변경되는 셰이더 내의 리소스입니다.
	 */
	EveryFramConstantBuffer EveryFrameBufferResource_;


	/**
	 * @brief 매 프레임 변경되는 셰이더 내의 상수 버퍼입니다.
	 */
	ID3D11Buffer* EveryFrameBuffer_ = nullptr;


	/**
	 * @brief 기본 도형의 정점 목록입니다.
	 */
	std::unordered_map<std::string, std::vector<Vertex::PositionColor>> PrimitiveVertex_;


	/**
	 * @brief 기본 도형의 정점 버퍼입니다.
	 */
	std::unordered_map<std::string, ID3D11Buffer*> PrimitiveVertexBuffer_;


	/**
	 * @brief 기본 도형의 인덱스 목록입니다.
	 */
	std::unordered_map<std::string, std::vector<uint32_t>> PrimitiveIndex_;


	/**
	 * @brief 기본 도형의 인덱스 버퍼입니다.
	 */
	std::unordered_map<std::string, ID3D11Buffer*> PrimitiveIndexBuffer_;
};