#pragma once

#include "Macro.h"

#include <vector>
#include <d3d11.h>


/**
 * @brief 셰이더 관련 기능을 제공합니다.
 */
class Shader
{
public:
	/**
	 * @brief 셰이더 클래스의 디폴트 생성자입니다.
	 */
	Shader() = default;


	/**
	 * @brief 셰이더 클래스의 가상 소멸자입니다.
	 */
	virtual ~Shader() {}


	/**
	 * @brief 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Shader);


protected:
	/**
	 * @brief 셰이더를 컴파일합니다.
	 * 
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/d3dcompiler/nf-d3dcompiler-d3dcompilefromfile
	 * 
	 * @note https://github.com/walbourn/directx-sdk-samples/blob/main/Direct3D11Tutorials/Tutorial07/Tutorial07.cpp#L177
	 * 
	 * @param SourcePath 셰이더 소스 파일의 경로입니다.
	 * @param EntryPoint 셰이더의 진입점입니다.
	 * @param ShaderModel 셰이더의 기능 집합입니다.
	 * @param Blob[out] 컴파일된 셰이더 리소스입니다.
	 * 
	 * @return 셰이더 컴파일 결과를 반환합니다. 컴파일에 성공했다면 S_OK, 그렇지 않다면 그 이외의 값을 반환합니다.
	 */
	HRESULT CompileShaderFromFile(
		const std::wstring& SourcePath, 
		const std::string& EntryPoint, 
		const std::string& ShaderModel, 
		ID3DBlob** Blob
	);


	/**
	 * @brief 정점 셰이더 소스로부터 정점 셰이더 리소스를 생성합니다.
	 * 
	 * @param Device 셰이더 생성에 필요한 디바이스입니다.
	 * @param SourcePath 정점 셰이더 소스의 경로입니다.
	 * @param VertexShaderSource[out] 컴파일된 정점 셰이더 소스입니다.
	 * @param VertexShader[out] 정점 셰이더 리소스입니다.
	 * 
	 * @return 셰이더 리소스 생성 결과를 반환합니다. 생성에 성공했다면 S_OK, 그렇지 않다면 그 이외의 값을 반환합니다.
	 */
	HRESULT CreateVertexShaderFromFile(
		ID3D11Device* Device, 
		const std::wstring& SourcePath, 
		ID3DBlob** VertexShaderSource, 
		ID3D11VertexShader** VertexShader
	);


	/**
	 * @brief 픽셀 셰이더 소스로부터 정점 셰이더 리소스를 생성합니다.
	 *
	 * @param Device 셰이더 생성에 필요한 디바이스입니다. 
	 * @param SourcePath 픽셀 셰이더 소스의 경로입니다.
	 * @param PixelShaderSource[out] 컴파일된 픽셀 셰이더 소스입니다.
	 * @parma PixelShader[out] 픽셀 셰이더 리소스입니다.
	 *
	 * @return 셰이더 리소스 생성 결과를 반환합니다. 생성에 성공했다면 S_OK, 그렇지 않다면 그 이외의 값을 반환합니다.
	 */
	HRESULT CreatePixelShaderFromFile(
		ID3D11Device* Device, 
		const std::wstring& SourcePath,
		ID3DBlob** PixelShaderSource,
		ID3D11PixelShader** PixelShader
	);


	/**
	 * @brief 정점 셰이더에 전달할 정점 데이터를 생성합니다.
	 *
	 * @note 이 메서드를 호출하기 전에 정점 셰이더가 컴파일 되어야 합니다.
	 *
	 * @param Device 정점 데이터를 생성할 때 사용할 디바이스입니다.
	 * @param VertexShaderSource 정점 데이터를 생성할 때 참고할 컴파일된 정점 셰이더의 소스입니다.
	 * @param InputLayoutElements 정점 셰이더에 전달할 정점 데이터 정보입니다.
	 * @param InputLayout[out] 생성된 정점 데이터 정보 리스소입니다.
	 *
	 * @return 정점 데이터 생성 결과를 반환합니다. 생성에 성공하면 S_OK, 그렇지 않다면 그 이외의 값을 반환합니다.
	 */
	HRESULT CreateInputLayout(
		ID3D11Device* Device,
		ID3DBlob* VertexShaderSource,
		const std::vector<D3D11_INPUT_ELEMENT_DESC>& InputLayoutElements,
		ID3D11InputLayout** InputLayout
	);
	

	/**
	 * @brief 파이프라인에서 사용할 정점 버퍼를 생성합니다.
	 * 
	 * @param Device 버퍼를 생성할 때 사용할 디바이스입니다.
	 * @param Vertices 정점 버퍼를 생성할 때 참조할 정점 목록입니다.
	 * @param VertexBuffer 생성된 정점 버퍼입니다.
	 *
	 * @return 버퍼 생성 결과를 반환합니다. 생성에 성공하면 S_OK, 그렇지 않으면 그 이외의 값을 반환합니다.
	 */
	template<typename Vertex>
	HRESULT CreateDefaultVertexBuffer(ID3D11Device* Device, const std::vector<Vertex>& Vertices, ID3D11Buffer** VertexBuffer)
	{
		D3D11_BUFFER_DESC VertexBufferDesc = {};

		VertexBufferDesc.Usage               = D3D11_USAGE_DEFAULT;
		VertexBufferDesc.ByteWidth           = sizeof(Vertex) * static_cast<uint32_t>(Vertices.size());
		VertexBufferDesc.BindFlags           = D3D11_BIND_VERTEX_BUFFER;
		VertexBufferDesc.CPUAccessFlags      = 0;
		VertexBufferDesc.MiscFlags           = 0;
		VertexBufferDesc.StructureByteStride = 0;

		D3D11_SUBRESOURCE_DATA VertexData;
		VertexData.pSysMem          = reinterpret_cast<const void*>(&Vertices[0]);
		VertexData.SysMemPitch      = 0;
		VertexData.SysMemSlicePitch = 0;

		return Device->CreateBuffer(&VertexBufferDesc, &VertexData, VertexBuffer);
	}


	/**
	 * @brief 파이프라인에서 사용할 다이나믹 정점 버퍼를 생성합니다.
	 * 
	 * @param Device 버퍼를 생성할 때 사용할 디바이스입니다.
	 * @param Vertices 정점 버퍼를 생성할 때 참조할 정점 목록입니다.
	 * @param VertexBuffer 생성된 정점 버퍼입니다.
	 * 
	 * @return 버퍼 생성 결과를 반환합니다. 생성에 성공하면 S_OK, 그렇지 않으면 그 이외의 값을 반환합니다.
	 */
	template<typename Vertex>
	HRESULT CreateDynamicVertexBuffer(ID3D11Device* Device, const std::vector<Vertex>& Vertices, ID3D11Buffer** VertexBuffer)
	{
		D3D11_BUFFER_DESC VertexBufferDesc = {};

		VertexBufferDesc.Usage               = D3D11_USAGE_DYNAMIC;
		VertexBufferDesc.ByteWidth           = sizeof(Vertex) * static_cast<uint32_t>(Vertices.size());
		VertexBufferDesc.BindFlags           = D3D11_BIND_VERTEX_BUFFER;
		VertexBufferDesc.CPUAccessFlags      = D3D11_CPU_ACCESS_WRITE;
		VertexBufferDesc.MiscFlags           = 0;
		VertexBufferDesc.StructureByteStride = 0;

		D3D11_SUBRESOURCE_DATA VertexData;
		VertexData.pSysMem          = reinterpret_cast<const void*>(&Vertices[0]);
		VertexData.SysMemPitch      = 0;
		VertexData.SysMemSlicePitch = 0;

		return Device->CreateBuffer(&VertexBufferDesc, &VertexData, VertexBuffer);
	}


	/**
	 * @brief 파이프라인에서 사용할 변경 가능하지 않은 정점 버퍼를 생성합니다.
	 * 
	 * @param Device 버퍼를 생성할 때 사용할 디바이스입니다.
	 * @param Vertices 정점 버퍼를 생성할 때 참조할 정점 목록입니다.
	 * @param VertexBuffer 생성된 정점 버퍼입니다.
	 *
	 * @return 버퍼 생성 결과를 반환합니다. 생성에 성공하면 S_OK, 그렇지 않으면 그 이외의 값을 반환합니다.
	 */
	template<typename Vertex>
	HRESULT CreateImmutableVertexBuffer(ID3D11Device* Device, const std::vector<Vertex>& Vertices, ID3D11Buffer** VertexBuffer)
	{
		D3D11_BUFFER_DESC VertexBufferDesc = {};

		VertexBufferDesc.Usage               = D3D11_USAGE_IMMUTABLE;
		VertexBufferDesc.ByteWidth           = sizeof(Vertex) * static_cast<uint32_t>(Vertices.size());
		VertexBufferDesc.BindFlags           = D3D11_BIND_VERTEX_BUFFER;
		VertexBufferDesc.CPUAccessFlags      = 0;
		VertexBufferDesc.MiscFlags           = 0;
		VertexBufferDesc.StructureByteStride = 0;

		D3D11_SUBRESOURCE_DATA VertexData;
		VertexData.pSysMem          = reinterpret_cast<const void*>(&Vertices[0]);
		VertexData.SysMemPitch      = 0;
		VertexData.SysMemSlicePitch = 0;

		return Device->CreateBuffer(&VertexBufferDesc, &VertexData, VertexBuffer);
	}


	/**
	 * @brief 파이프라인에서 사용할 인덱스 버퍼를 생성합니다.
	 * 
	 * @note 인덱스 버퍼는 무조건 변경 불가능한 버퍼입니다.
	 * 
	 * @param Device 버퍼를 생성할 때 사용할 디바이스입니다.
	 * @param Vertices 인덱스 버퍼를 생성할 때 참조할 인덱스 목록입니다.
	 * @param IndexBuffer 생성된 인덱스 버퍼입니다.
	 *
	 * @return 버퍼 생성 결과를 반환합니다. 생성에 성공하면 S_OK, 그렇지 않으면 그 이외의 값을 반환합니다.
	 */
	HRESULT CreateIndexBuffer(ID3D11Device* Device, const std::vector<uint32_t>& Indices, ID3D11Buffer** IndexBuffer);


	/**
	 * @brief 디폴트 상수 버퍼를 생성합니다.
	 *
	 * @param Device 버퍼를 생성할 때 사용할 디바이스입니다.
	 * @param ConstantBuffer 생성된 상수 버퍼입니다
	 *
	 * @return 버퍼 생성 결과를 반환합니다. 생성에 성공하면 S_OK, 그렇지 않으면 그 이외의 값을 반환합니다.
	 */
	template <typename T>
	HRESULT CreateDefaultConstantBuffer(ID3D11Device* Device, ID3D11Buffer** ConstantBuffer)
	{
		D3D11_BUFFER_DESC ConstantBufferDesc = {};

		ConstantBufferDesc.Usage               = D3D11_USAGE_DEFAULT;
		ConstantBufferDesc.ByteWidth           = sizeof(T);
		ConstantBufferDesc.BindFlags           = D3D11_BIND_CONSTANT_BUFFER;
		ConstantBufferDesc.CPUAccessFlags      = 0;
		ConstantBufferDesc.MiscFlags           = 0;
		ConstantBufferDesc.StructureByteStride = 0;

		return Device->CreateBuffer(&ConstantBufferDesc, nullptr, ConstantBuffer);
	}


	/**
	 * @brief 다이나믹 상수 버퍼를 생성합니다.
	 *
	 * @param Device 버퍼를 생성할 때 사용할 디바이스입니다.
	 * @param ConstantBuffer 생성된 상수 버퍼입니다
	 *
	 * @return 버퍼 생성 결과를 반환합니다. 생성에 성공하면 S_OK, 그렇지 않으면 그 이외의 값을 반환합니다.
	 */
	template <typename T>
	HRESULT CreateDynamicConstantBuffer(ID3D11Device* Device, ID3D11Buffer** ConstantBuffer)
	{
		D3D11_BUFFER_DESC ConstantBufferDesc = {};

		ConstantBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
		ConstantBufferDesc.ByteWidth = sizeof(T);
		ConstantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		ConstantBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		ConstantBufferDesc.MiscFlags = 0;
		ConstantBufferDesc.StructureByteStride = 0;

		return Device->CreateBuffer(&ConstantBufferDesc, nullptr, ConstantBuffer);
	}


	/**
	 * @brief 선형 텍스처 샘플러를 생성합니다.
	 * 
	 * @param Device 선형 샘플러를 생성할 때 사용할 디바이스입니다.
	 * @param LinearSampler 생성된 선형 샘플러입니다.
	 * 
	 * @return 선형 텍스처 샘플러 생성 결과를 반환합니다. 생성에 성공하면 S_OK, 그렇지 않으면 그 이외의 값을 반환합니다.
	 */
	HRESULT CreateLinearTextureSampler(ID3D11Device* Device, ID3D11SamplerState** LinearTextureSampler);
};