#include "Shader2D.h"

Shader2D::~Shader2D()
{
	SAFE_RELEASE(InputLayout_);
	SAFE_RELEASE(VertexShaderSource_);
	SAFE_RELEASE(VertexShader_);
	SAFE_RELEASE(PixelShaderSource_);
	SAFE_RELEASE(PixelShader_);
}