#pragma once

#include "Shader.h"


/**
 * @brief 2D 렌더링을 수행하는 셰이더의 인터페이스입니다.
 */
class Shader2D : public Shader
{
public:
	/**
	 * @brief 2D 렌더링을 수행하는 셰이더의 디폴트 생성자입니다.
	 */
	Shader2D() = default;


	/**
	 * @brief 2D 렌더링을 수행하는 셰이더의 가상 소멸자입니다.
	 */
	virtual ~Shader2D();


	/**
	 * @brief 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Shader2D);


protected:
	/**
	 * @brief 정점 셰이더 소스 리소스입니다.
	 */
	ID3DBlob* VertexShaderSource_ = nullptr;


	/**
	 * @brief 정점 셰이더 리소스입니다.
	 */
	ID3D11VertexShader* VertexShader_ = nullptr;


	/**
	 * @brief 픽셀 셰이더 소스 리소스입니다.
	 */
	ID3DBlob* PixelShaderSource_ = nullptr;


	/**
	 * @brief 픽셀 셰이더 리소스입니다.
	 */
	ID3D11PixelShader* PixelShader_ = nullptr;


	/**
	 * @brief 렌더링 파이프라인의 정점 데이터를 정의합니다.
	 *
	 * @note https://learn.microsoft.com/en-us/windows/win32/api/d3d11/nn-d3d11-id3d11inputlayout
	 */
	ID3D11InputLayout* InputLayout_ = nullptr;
};