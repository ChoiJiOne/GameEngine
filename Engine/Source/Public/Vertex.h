#pragma once

#include "Vector.hpp"


/**
 * @brief ��ġ�� ������ ������ �����Դϴ�.
 */
struct VertexPosColor
{
	Vec3f Position;
	Vec4f Color;
};


/**
 * @brief ��ġ�� �ؽ�ó ��ġ�� ������ �����Դϴ�.
 */
struct VertexPosUV
{
	Vec3f Position;
	Vec2f UV;
};