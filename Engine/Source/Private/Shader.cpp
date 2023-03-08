#include "Shader.h"

#include <d3dcompiler.h>

HRESULT Shader::CompileShaderFromFile(const std::wstring& SourcePath, const std::string& EntryPoint, const std::string& ShaderModel, ID3DBlob** Blob)
{
	HRESULT HR = S_OK;

	DWORD ShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;

#if defined(DEBUG) || defined(_DEBUG)
	ShaderFlags |= D3DCOMPILE_DEBUG;
	ShaderFlags |= D3DCOMPILE_SKIP_OPTIMIZATION;
#endif

	HR = D3DCompileFromFile(
		SourcePath.c_str(),
		nullptr, 
		nullptr, 
		EntryPoint.c_str(),
		ShaderModel.c_str(),
		ShaderFlags,
		0, 
		Blob, 
		nullptr
	);

	return HR;
}

HRESULT Shader::CreateVertexShaderFromFile(
	ID3D11Device* Device, 
	const std::wstring& SourcePath,
	ID3DBlob** VertexShaderSource,
	ID3D11VertexShader** VertexShader
)
{
	HRESULT HR = S_OK;

	HR = CompileShaderFromFile(SourcePath, "main", "vs_4_0_level_9_3", VertexShaderSource);

	if (SUCCEEDED(HR))
	{
		HR = Device->CreateVertexShader(
			(*VertexShaderSource)->GetBufferPointer(),
			(*VertexShaderSource)->GetBufferSize(),
			nullptr, 
			VertexShader
		);
	}
	
	return HR;
}

HRESULT Shader::CreatePixelShaderFromFile(
	ID3D11Device* Device, 
	const std::wstring& SourcePath,
	ID3DBlob** PixelShaderSource,
	ID3D11PixelShader** PixelShader
)
{
	HRESULT HR = S_OK;

	HR = CompileShaderFromFile(SourcePath, "main", "ps_4_0_level_9_3", PixelShaderSource);

	if (SUCCEEDED(HR))
	{
		HR = Device->CreatePixelShader(
			(*PixelShaderSource)->GetBufferPointer(),
			(*PixelShaderSource)->GetBufferSize(),
			nullptr, 
			PixelShader
		);
	}

	return HR;
}

HRESULT Shader::CreateInputLayout(
	ID3D11Device* Device,
	ID3DBlob* VertexShaderSource,
	const std::vector<D3D11_INPUT_ELEMENT_DESC>& InputLayoutElements,
	ID3D11InputLayout** InputLayout
)
{
	return Device->CreateInputLayout(
		&InputLayoutElements[0],
		static_cast<uint32_t>(InputLayoutElements.size()),
		VertexShaderSource->GetBufferPointer(),
		VertexShaderSource->GetBufferSize(),
		InputLayout
	);
}

HRESULT Shader::CreateIndexBuffer(ID3D11Device* Device, const std::vector<uint32_t>& Indices, ID3D11Buffer** IndexBuffer)
{
	D3D11_BUFFER_DESC IndexBufferDesc;

	IndexBufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
	IndexBufferDesc.ByteWidth = sizeof(uint32_t) * static_cast<uint32_t>(Indices.size());
	IndexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	IndexBufferDesc.CPUAccessFlags = 0;
	IndexBufferDesc.MiscFlags = 0;
	IndexBufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA IndexData;
	IndexData.pSysMem = reinterpret_cast<const void*>(&Indices[0]);
	IndexData.SysMemPitch = 0;
	IndexData.SysMemSlicePitch = 0;

	return Device->CreateBuffer(&IndexBufferDesc, &IndexData, IndexBuffer);
}

HRESULT Shader::CreateLinearTextureSampler(ID3D11Device* Device, ID3D11SamplerState** LinearTextureSampler)
{
	D3D11_SAMPLER_DESC TextureSamplerDesc = { };

	TextureSamplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	TextureSamplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	TextureSamplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	TextureSamplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	TextureSamplerDesc.MipLODBias = 0.0f;
	TextureSamplerDesc.MaxAnisotropy = 1;
	TextureSamplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	TextureSamplerDesc.BorderColor[0] = 0;
	TextureSamplerDesc.BorderColor[1] = 0;
	TextureSamplerDesc.BorderColor[2] = 0;
	TextureSamplerDesc.BorderColor[3] = 0;
	TextureSamplerDesc.MinLOD = 0;
	TextureSamplerDesc.MaxLOD = D3D11_FLOAT32_MAX;

	return Device->CreateSamplerState(&TextureSamplerDesc, LinearTextureSampler);
}
