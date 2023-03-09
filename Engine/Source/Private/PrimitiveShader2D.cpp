#include "PrimitiveShader2D.h"
#include "Utils.hpp"

PrimitiveShader2D::PrimitiveShader2D(ID3D11Device* Device, const std::wstring& VertexShaderSourcePath, const std::wstring& PixelShaderSourcePath)
{
	std::vector<D3D11_INPUT_ELEMENT_DESC> InputLayoutElements = {
		{ "POSITION", 0,    DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{    "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};

	CHECK_HR(CreateVertexShaderFromFile(Device, VertexShaderSourcePath, &VertexShaderSource_, &VertexShader_), "failed to create vertex shader");
	CHECK_HR(CreatePixelShaderFromFile(Device, PixelShaderSourcePath, &PixelShaderSource_, &PixelShader_), "failed to create pixel shader");
	CHECK_HR(CreateInputLayout(Device, VertexShaderSource_, InputLayoutElements, &InputLayout_), "failed to create input layout");
	CHECK_HR(CreateDynamicConstantBuffer<EveryFramConstantBuffer>(Device, &EveryFrameBuffer_), "failed to every frame constant buffer");

	EveryFrameBufferResource_.Projection.Identify();

	std::vector<Vertex::PositionColor> Vertices;
	std::vector<uint32_t> Indices;

	Vertices.resize(1);
	Indices = { 0 };
	BuildVertexAndIndexBuffer(Device, "Point", Vertices, Indices);
	
	Vertices.resize(2);
	Indices = { 0, 1 };
	BuildVertexAndIndexBuffer(Device, "Line", Vertices, Indices);

	Vertices.resize(3);
	Indices = { 0, 1, 2 };
	BuildVertexAndIndexBuffer(Device, "Triangle", Vertices, Indices);

	Vertices.resize(3);
	Indices = { 0, 1, 1, 2, 2, 0 };
	BuildVertexAndIndexBuffer(Device, "WireframeTriangle", Vertices, Indices);

	Vertices.resize(4);
	Indices = { 0, 1, 2, 0, 2, 3};
	BuildVertexAndIndexBuffer(Device, "Quad", Vertices, Indices);

	Vertices.resize(4);
	Indices = {0, 1, 1, 2, 2, 3, 3, 0};
	BuildVertexAndIndexBuffer(Device, "WireframeQuad", Vertices, Indices);

	Vertices.resize(41);
	Indices = {};
	for (std::size_t Index = 0; Index < Vertices.size() - 1; ++Index)
	{
		Indices.push_back(Vertices.size() - 1);
		Indices.push_back((Index + 0) % (Vertices.size() - 1));
		Indices.push_back((Index + 1) % (Vertices.size() - 1));
	}
	BuildVertexAndIndexBuffer(Device, "Circle", Vertices, Indices);

	Vertices.resize(40);
	Indices = {};
	for (std::size_t Index = 0; Index < Vertices.size(); ++Index)
	{
		Indices.push_back((Index + 0) % Vertices.size());
		Indices.push_back((Index + 1) % Vertices.size());
	}
	BuildVertexAndIndexBuffer(Device, "WireframeCircle", Vertices, Indices);
}

PrimitiveShader2D::~PrimitiveShader2D()
{
	for (auto& VertexBuffer : PrimitiveVertexBuffer_)
	{
		SAFE_RELEASE(VertexBuffer.second);
	}

	for (auto& IndexBuffer : PrimitiveIndexBuffer_)
	{
		SAFE_RELEASE(IndexBuffer.second);
	}

	SAFE_RELEASE(EveryFrameBuffer_);
}

void PrimitiveShader2D::RenderPoint(ID3D11DeviceContext* Context, const Vec3f& Position, const Vec4f& Color)
{
	PrimitiveVertex_["Point"][0].Position = Position;
	PrimitiveVertex_["Point"][0].Color = Color;

	RenderPrimitive(Context, "Point", ERenderType::POINT);
}

void PrimitiveShader2D::RenderLine(
	ID3D11DeviceContext* Context, 
	const Vec3f& PositionFrom, const Vec4f& ColorFrom, 
	const Vec3f& PositionTo, const Vec4f& ColorTo
)
{
	PrimitiveVertex_["Line"][0].Position = PositionFrom;
	PrimitiveVertex_["Line"][0].Color = ColorFrom;

	PrimitiveVertex_["Line"][1].Position = PositionTo;
	PrimitiveVertex_["Line"][1].Color = ColorTo;

	RenderPrimitive(Context, "Line", ERenderType::LINE);
}

void PrimitiveShader2D::RenderFillTriangle(
	ID3D11DeviceContext* Context, 
	const Vec3f& PositionFrom, const Vec4f& ColorFrom, 
	const Vec3f& PositionBy, const Vec4f& ColorBy, 
	const Vec3f& PositionTo, const Vec4f& ColorTo
)
{
	PrimitiveVertex_["Triangle"][0].Position = PositionFrom;
	PrimitiveVertex_["Triangle"][0].Color = ColorFrom;

	PrimitiveVertex_["Triangle"][1].Position = PositionBy;
	PrimitiveVertex_["Triangle"][1].Color = ColorBy;

	PrimitiveVertex_["Triangle"][2].Position = PositionTo;
	PrimitiveVertex_["Triangle"][2].Color = ColorTo;

	RenderPrimitive(Context, "Triangle", ERenderType::TRIANGLE);
}

void PrimitiveShader2D::RenderWireframeTriangle(
	ID3D11DeviceContext* Context, 
	const Vec3f& PositionFrom, const Vec4f& ColorFrom, 
	const Vec3f& PositionBy, const Vec4f& ColorBy, 
	const Vec3f& PositionTo, const Vec4f& ColorTo
)
{
	PrimitiveVertex_["WireframeTriangle"][0].Position = PositionFrom;
	PrimitiveVertex_["WireframeTriangle"][0].Color = ColorFrom;

	PrimitiveVertex_["WireframeTriangle"][1].Position = PositionBy;
	PrimitiveVertex_["WireframeTriangle"][1].Color = ColorBy;

	PrimitiveVertex_["WireframeTriangle"][2].Position = PositionTo;
	PrimitiveVertex_["WireframeTriangle"][2].Color = ColorTo;

	RenderPrimitive(Context, "WireframeTriangle", ERenderType::LINE);
}

void PrimitiveShader2D::RenderFillQuad(ID3D11DeviceContext* Context, const Vec3f& Center, const Vec4f& Color, float Width, float Height, float Rotate)
{
	PrimitiveVertex_["Quad"][0].Position = Vec3f(-Width / 2.0f, -Height / 2.0f, Center.z);
	PrimitiveVertex_["Quad"][0].Color = Color;

	PrimitiveVertex_["Quad"][1].Position = Vec3f(-Width / 2.0f, +Height / 2.0f, Center.z);
	PrimitiveVertex_["Quad"][1].Color = Color;

	PrimitiveVertex_["Quad"][2].Position = Vec3f(+Width / 2.0f, +Height / 2.0f, Center.z);
	PrimitiveVertex_["Quad"][2].Color = Color;

	PrimitiveVertex_["Quad"][3].Position = Vec3f(+Width / 2.0f, -Height / 2.0f, Center.z);
	PrimitiveVertex_["Quad"][3].Color = Color;

	for (auto& PrimitiveVertex : PrimitiveVertex_["Quad"])
	{
		Vec3f Position = PrimitiveVertex.Position;

		PrimitiveVertex.Position.x = cos(Rotate) * Position.x - sin(Rotate) * Position.y;
		PrimitiveVertex.Position.y = sin(Rotate) * Position.x + cos(Rotate) * Position.y;

		PrimitiveVertex.Position += Center;
	}

	RenderPrimitive(Context, "Quad", ERenderType::TRIANGLE);
}

void PrimitiveShader2D::RenderWireframeQuad(ID3D11DeviceContext* Context, const Vec3f& Center, const Vec4f& Color, float Width, float Height, float Rotate)
{
	PrimitiveVertex_["WireframeQuad"][0].Position = Vec3f(-Width / 2.0f, -Height / 2.0f, Center.z);
	PrimitiveVertex_["WireframeQuad"][0].Color = Color;

	PrimitiveVertex_["WireframeQuad"][1].Position = Vec3f(-Width / 2.0f, +Height / 2.0f, Center.z);
	PrimitiveVertex_["WireframeQuad"][1].Color = Color;

	PrimitiveVertex_["WireframeQuad"][2].Position = Vec3f(+Width / 2.0f, +Height / 2.0f, Center.z);
	PrimitiveVertex_["WireframeQuad"][2].Color = Color;

	PrimitiveVertex_["WireframeQuad"][3].Position = Vec3f(+Width / 2.0f, -Height / 2.0f, Center.z);
	PrimitiveVertex_["WireframeQuad"][3].Color = Color;

	for (auto& PrimitiveVertex : PrimitiveVertex_["WireframeQuad"])
	{
		Vec3f Position = PrimitiveVertex.Position;

		PrimitiveVertex.Position.x = cos(Rotate) * Position.x - sin(Rotate) * Position.y;
		PrimitiveVertex.Position.y = sin(Rotate) * Position.x + cos(Rotate) * Position.y;

		PrimitiveVertex.Position += Center;
	}

	RenderPrimitive(Context, "WireframeQuad", ERenderType::LINE);
}

void PrimitiveShader2D::RenderFillCircle(ID3D11DeviceContext* Context, const Vec3f& Center, const Vec4f& Color, float Radius)
{
	for (std::size_t Index = 0; PrimitiveVertex_["Circle"].size() - 1; ++Index)
	{

	}

	std::size_t VertexSize = PrimitiveVertex_["Circle"].size();
	PrimitiveVertex_["Circle"][VertexSize - 1].Position = Center;
	PrimitiveVertex_["Circle"][VertexSize - 1].Color = Color;

	RenderPrimitive(Context, "Circle", ERenderType::TRIANGLE);
}

void PrimitiveShader2D::RenderWireframeCircle(ID3D11DeviceContext* Context, const Vec3f& Center, const Vec4f& Color, float Radius)
{
	for (std::size_t Index = 0; PrimitiveVertex_["WireframeCircle"].size(); ++Index)
	{

	}

	RenderPrimitive(Context, "WireframeCircle", ERenderType::LINE);
}

void PrimitiveShader2D::BuildVertexAndIndexBuffer(ID3D11Device* Device, const std::string& Name, const std::vector<Vertex::PositionColor>& Vertices, const std::vector<uint32_t>& Indices)
{
	//CHECK(IsExistKey<std::string, std::vector<Vertex::PositionColor>>(Name, PrimitiveVertex_) == false, "already exist vertex buffer name");
	//CHECK(IsExistKey<std::string, std::vector<uint32_t>>(Name, PrimitiveIndex_), "already exist index buffer name");

	PrimitiveVertex_[Name] = Vertices;
	PrimitiveIndex_[Name] = Indices;

	CHECK_HR(CreateDynamicVertexBuffer(Device, PrimitiveVertex_[Name], &PrimitiveVertexBuffer_[Name]), "failed to create vertex buffer");
	CHECK_HR(CreateIndexBuffer(Device, PrimitiveIndex_[Name], &PrimitiveIndexBuffer_[Name]), "failed to create index buffer");
}

void PrimitiveShader2D::RenderPrimitive(ID3D11DeviceContext* Context, const std::string& PrimitiveSignature, const ERenderType& RenderType)
{
	D3D_PRIMITIVE_TOPOLOGY Topology;

	switch (RenderType)
	{
	case ERenderType::POINT:
		Topology = D3D11_PRIMITIVE_TOPOLOGY_POINTLIST;
		break;

	case ERenderType::LINE:
		Topology = D3D11_PRIMITIVE_TOPOLOGY_LINELIST;
		break;

	case ERenderType::TRIANGLE:
		Topology = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
		break;

	default:
		ENFORCE_THROW_EXCEPTION("undefined render type");
	}

	D3D11_MAPPED_SUBRESOURCE VertexBufferMappedResource;

	if (SUCCEEDED(Context->Map(PrimitiveVertexBuffer_[PrimitiveSignature], 0, D3D11_MAP_WRITE_DISCARD, 0, &VertexBufferMappedResource)))
	{
		Vertex::PositionColor* Buffer = reinterpret_cast<Vertex::PositionColor*>(VertexBufferMappedResource.pData);

		std::memcpy(
			Buffer,
			reinterpret_cast<const void*>(&PrimitiveVertex_[PrimitiveSignature][0]),
			PrimitiveVertex_[PrimitiveSignature].size() * sizeof(Vertex::PositionColor)
		);

		Context->Unmap(PrimitiveVertexBuffer_[PrimitiveSignature], 0);
	}

	uint32_t Stride = sizeof(Vertex::PositionColor);
	uint32_t Offset = 0;

	Context->IASetVertexBuffers(0, 1, &PrimitiveVertexBuffer_[PrimitiveSignature], &Stride, &Offset);
	Context->IASetIndexBuffer(PrimitiveIndexBuffer_[PrimitiveSignature], DXGI_FORMAT_R32_UINT, 0);
	Context->IASetPrimitiveTopology(Topology);

	Context->IASetInputLayout(InputLayout_);

	Context->VSSetShader(VertexShader_, nullptr, 0);
	Context->PSSetShader(PixelShader_, nullptr, 0);

	D3D11_MAPPED_SUBRESOURCE ConstantBufferMappedResource;

	if (SUCCEEDED(Context->Map(EveryFrameBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &ConstantBufferMappedResource)))
	{
		EveryFramConstantBuffer* Buffer = reinterpret_cast<EveryFramConstantBuffer*>(ConstantBufferMappedResource.pData);
		
		Buffer->Projection = EveryFrameBufferResource_.Projection;

		Context->Unmap(EveryFrameBuffer_, 0);
	}

	uint32_t BindSlot = 0;
	Context->VSSetConstantBuffers(BindSlot, 1, &EveryFrameBuffer_);

	Context->DrawIndexed(static_cast<uint32_t>(PrimitiveIndex_[PrimitiveSignature].size()), 0, 0);
}
