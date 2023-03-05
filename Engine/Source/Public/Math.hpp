#pragma once

#include "Macro.h"
#include "Vector.hpp"
#include "Matrix.hpp"


/**
 * @brief float Ÿ���� ����(��) ���Դϴ�.
 */
const float PI_F = 3.1415926535F;


/**
 * @brief double Ÿ���� ����(��) ���Դϴ�.
 */
const double PI_D = 3.1415926535897931;


/**
 * @brief float Ÿ���� Ÿ���� ���Ƿ�(��) ���Դϴ�.
 */
const float EPSILON_F = std::numeric_limits<float>::epsilon();


/**
 * @brief double Ÿ���� ���Ƿ�(��) ���Դϴ�.
 */
const double EPSILON_D = std::numeric_limits<double>::epsilon();


/**
 * @brief float Ÿ���� ���Ѵ� ���Դϴ�.
 */
const float INFINITY_F = std::numeric_limits<float>::infinity();


/**
 * @brief double Ÿ���� ���Ѵ� ���Դϴ�.
 */
const double INFINITY_D = std::numeric_limits<double>::infinity();


/**
 * @brief float Ÿ���� ���� ���Ѵ� ���Դϴ�.
 */
const float NINFINITY_F = -std::numeric_limits<float>::infinity();


/**
 * @brief double Ÿ���� ���� ���Ѵ� ���Դϴ�.
 */
const double NINFINITY_D = -std::numeric_limits<double>::infinity();


/**
 * @brief ���� ���� ���ʺй� ������ ��ȯ�մϴ�.
 *
 * @param Radian ��ȯ�� ���� ���Դϴ�.
 *
 * @return ��ȯ�� ���ʺй� ���Դϴ�.
 */
inline float ToDegree(float Radian)
{
	return (Radian * 180.0f) / PI_F;
}


/**
 * @brief ���� ���� ���ʺй� ������ ��ȯ�մϴ�.
 *
 * @param Radian ��ȯ�� ���� ���Դϴ�.
 *
 * @return ��ȯ�� ���ʺй� ���Դϴ�.
 */
inline double ToDegree(double Radian)
{
	return (Radian * 180.0) / PI_D;
}


/**
 * @brief ���ʺй� ���� ���� ������ ��ȯ�մϴ�.
 *
 * @param Degree ��ȯ�� ���ʺй� ���Դϴ�.
 *
 * @return ��ȯ�� ���� ���Դϴ�.
 */
inline float ToRadian(float Degree)
{
	return (Degree * PI_F) / 180.0f;
}


/**
 * @brief ���ʺй� ���� ���� ������ ��ȯ�մϴ�.
 *
 * @param Degree ��ȯ�� ���ʺй� ���Դϴ�.
 *
 * @return ��ȯ�� ���� ���Դϴ�.
 */
inline double ToRadian(double Degree)
{
	return (Degree * PI_D) / 180.0;
}


/**
 * @brief 0�� �Ѿ��� ����� ������ Ȯ���մϴ�.
 *
 * @param Value 0�� �Ѿ��� ������� Ȯ���� ���Դϴ�.
 * @param Epsilon ���Ƿ� ���Դϴ�.
 * 
 * @return ���Ƿ� ������ �۴ٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
 */
inline bool IsNearZero(const float& Value, const float Epsilon = EPSILON_F)
{
	return (fabs(Value) <= Epsilon);
}


/**
 * @brief ���� ���� ����� ����ϴ�.
 * 
 * @note �޼� ��ǥ�� �����Դϴ�.
 * 
 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/directxmath/nf-directxmath-xmmatrixorthographiclh
 * 
 * @param ViewWidth ����� Ŭ���� ��鿡 �ִ� frustum�� �ʺ��Դϴ�.
 * @param ViewHeight ����� Ŭ���� ��鿡 �ִ� frustum�� �����Դϴ�.
 * @param NearZ ����� Ŭ���� �������� �Ÿ��Դϴ�.
 * @param FarZ ���Ÿ� Ŭ���� �������� �Ÿ��Դϴ�.
 * 
 * @return �޼� ��ǥ�� ������ ���� ���� ����� ��ȯ�մϴ�.
 */
inline Matrix4x4F GetOrthographicMatrix(float ViewWidth, float ViewHeight, float NearZ, float FarZ)
{
	CHECK(!IsNearZero(ViewWidth), "view width is zero");
	CHECK(!IsNearZero(ViewHeight), "view height is zero");
	CHECK(!IsNearZero(FarZ - NearZ), "view height is zero");
	
	float Range = 1.0f / (FarZ - NearZ);

	return Matrix4x4F(
		2.0f / ViewWidth,              0.0f,           0.0f, 0.0f,
		            0.0f, 2.0f / ViewHeight,           0.0f, 0.0f,
		            0.0f,              0.0f,         +Range, 0.0f,
		            0.0f,              0.0f, -Range * NearZ, 1.0f
	);
}


/**
 * @brief 2D ��� ���� ���� �߽� ȸ�� ����� ����ϴ�.
 * 
 * @param Angle ���� ���� ������ ȸ�� ���Դϴ�.
 * 
 * @return ȸ�� ����� ����ϴ�.
 */
inline Matrix4x4F GetRotateMatrix(float Angle)
{
	float Sin = std::sin(Angle);
	float Cos = std::cos(Angle);

	return Matrix4x4F(
		+Cos,   -Sin, 0.0f, 0.0f,
		+Sin,   +Cos, 0.0f, 0.0f,
		 0.0f,  0.0f, 1.0f, 0.0f,
		 0.0f,  0.0f, 0.0f, 1.0f
	);
}