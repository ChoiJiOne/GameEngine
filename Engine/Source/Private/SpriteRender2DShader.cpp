#include "SpriteRender2DShader.h"
#include "Texture2D.h"

SpriteRender2DShader::SpriteRender2DShader(ID3D11Device* Device, const std::wstring& VertexShaderSourcePath, const std::wstring& PixelShaderSourcePath)
{
	std::vector<D3D11_INPUT_ELEMENT_DESC> InputLayoutElements = {
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0,    DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};

	CHECK_HR(CreateVertexShaderFromFile(Device, VertexShaderSourcePath, &VertexShaderSource_, &VertexShader_), "failed to create vertex shader");
	CHECK_HR(CreatePixelShaderFromFile(Device, PixelShaderSourcePath, &PixelShaderSource_, &PixelShader_), "failed to create pixel shader");
	CHECK_HR(CreateInputLayout(Device, VertexShaderSource_, InputLayoutElements, &InputLayout_), "failed to create input layout");
	CHECK_HR(CreateDynamicConstantBuffer<EveryFramConstantBuffer>(Device, &EveryFrameBuffer_), "failed to every frame constant buffer");
	CHECK_HR(CreateLinearTextureSampler(Device, &LinearSampler_), "failed to create texture sampler");

	EveryFrameBufferResource_.Projection.Identify();

	QuadTextureVertex_ = std::vector<Vertex::PositionUV>(4);
	QuadTextureIndex_ = std::vector<uint32_t>{ 0, 1, 2, 0, 2, 3 };

	CHECK_HR(CreateDynamicVertexBuffer<Vertex::PositionUV>(Device, QuadTextureVertex_, &QuadTextureVertexBuffer_), "failed to create vertex buffer");
	CHECK_HR(CreateIndexBuffer(Device, QuadTextureIndex_, &QuadTextureIndexBuffer_), "failed to create index buffer");
}

SpriteRender2DShader::~SpriteRender2DShader()
{
	SAFE_RELEASE(LinearSampler_);
	SAFE_RELEASE(QuadTextureIndexBuffer_);
	SAFE_RELEASE(QuadTextureVertexBuffer_);
	SAFE_RELEASE(EveryFrameBuffer_);
}

void SpriteRender2DShader::RenderSprite2D(ID3D11DeviceContext* Context, Texture2D& Texture, const Vec3f& Center, float Width, float Height, float Rotate)
{
	QuadTextureVertex_[0].Position = Vec3f(-Width / 2.0f, -Height / 2.0f, Center.z);
	QuadTextureVertex_[0].UV       = Vec2f(0.0f, 1.0f);

	QuadTextureVertex_[1].Position = Vec3f(-Width / 2.0f, +Height / 2.0f, Center.z);
	QuadTextureVertex_[1].UV       = Vec2f(0.0f, 0.0f);

	QuadTextureVertex_[2].Position = Vec3f(+Width / 2.0f, +Height / 2.0f, Center.z);
	QuadTextureVertex_[2].UV       = Vec2f(1.0f, 0.0f);
	
	QuadTextureVertex_[3].Position = Vec3f(+Width / 2.0f, -Height / 2.0f, Center.z);
	QuadTextureVertex_[3].UV       = Vec2f(1.0f, 1.0f);

	for (auto& QuadVertex : QuadTextureVertex_)
	{
		Vec3f Position = QuadVertex.Position;

		QuadVertex.Position.x = cos(Rotate) * Position.x - sin(Rotate) * Position.y;
		QuadVertex.Position.y = sin(Rotate) * Position.x + cos(Rotate) * Position.y;

		QuadVertex.Position += Center;
	}

	D3D11_MAPPED_SUBRESOURCE VertexBufferMappedResource;

	if (SUCCEEDED(Context->Map(QuadTextureVertexBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &VertexBufferMappedResource)))
	{
		Vertex::PositionUV* Buffer = reinterpret_cast<Vertex::PositionUV*>(VertexBufferMappedResource.pData);

		std::memcpy(
			Buffer,
			reinterpret_cast<const void*>(&QuadTextureVertex_[0]),
			QuadTextureVertex_.size() * sizeof(Vertex::PositionUV)
		);

		Context->Unmap(QuadTextureVertexBuffer_, 0);
	}

	uint32_t Stride = sizeof(Vertex::PositionUV);
	uint32_t Offset = 0;

	Context->IASetVertexBuffers(0, 1, &QuadTextureVertexBuffer_, &Stride, &Offset);
	Context->IASetIndexBuffer(QuadTextureIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);
	Context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	Context->IASetInputLayout(InputLayout_);

	Context->VSSetShader(VertexShader_, nullptr, 0);
	Context->PSSetShader(PixelShader_, nullptr, 0);

	D3D11_MAPPED_SUBRESOURCE ConstantBufferMappedResource;

	if (SUCCEEDED(Context->Map(EveryFrameBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &ConstantBufferMappedResource)))
	{
		EveryFramConstantBuffer* BufferPtr = reinterpret_cast<EveryFramConstantBuffer*>(ConstantBufferMappedResource.pData);

		BufferPtr->Projection = EveryFrameBufferResource_.Projection;

		Context->Unmap(EveryFrameBuffer_, 0);
	}

	uint32_t BindSlot = 0;
	Context->VSSetConstantBuffers(BindSlot, 1, &EveryFrameBuffer_);

	uint32_t SamplerBindSlot = 0;
	Context->PSSetSamplers(SamplerBindSlot, 1, &LinearSampler_);

	uint32_t TextureBindSlot = 0;
	ID3D11ShaderResourceView* TextureView = Texture.GetTextureView();
	Context->PSSetShaderResources(TextureBindSlot, 1, &TextureView);

	Context->DrawIndexed(static_cast<uint32_t>(QuadTextureIndex_.size()), 0, 0);
}