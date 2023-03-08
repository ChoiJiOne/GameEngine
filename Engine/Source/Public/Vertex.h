#pragma once

#include "Vector.hpp"


/**
 * @brief 위치와 색상을 포함한 정점입니다.
 */
struct VertexPosColor
{
	Vec3f Position;
	Vec4f Color;
};


/**
 * @brief 위치와 텍스처 위치를 포함한 정점입니다.
 */
struct VertexPosUV
{
	Vec3f Position;
	Vec2f UV;
};