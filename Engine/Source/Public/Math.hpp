#pragma once

#include "Macro.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <chrono>
#include <random>


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
 * @brief ���ø� ����� 2���� �����Դϴ�.
 */
template <typename T>
struct Vector2
{
	/**
	 * @brief ������ �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Vector2() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
	}


	/**
	 * @brief ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 */
	Vector2(T&& xx, T&& yy)
	{
		x = xx;
		y = yy;
	}


	/**
	 * @brief ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 */
	Vector2(const T& xx, const T& yy)
	{
		x = xx;
		y = yy;
	}


	/**
	 * @brief ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param Element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector2(T&& Element) noexcept
	{
		x = Element;
		y = Element;
	}


	/**
	 * @brief ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param Element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector2(const T& Element) noexcept
	{
		x = Element;
		y = Element;
	}


	/**
	 * @brief ������ ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	Vector2(const Vector2<T>& Instance) noexcept
	{
		x = Instance.x;
		y = Instance.y;
	}


	/**
	 * @brief ������ ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Vector2(Vector2<T>&& Instance) noexcept
	{
		x = Instance.x;
		y = Instance.y;
	}


	/**
	 * @brief ������ ���� ������ �Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator=(const Vector2<T>& Instance) noexcept
	{
		if (this == &Instance) return *this;

		x = Instance.x;
		y = Instance.y;

		return *this;
	}


	/**
	 * @brief ������ ���� ������ �Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator=(Vector2<T>&& Instance) noexcept
	{
		if (this == &Instance) return *this;

		x = Instance.x;
		y = Instance.y;

		return *this;
	}


	/**
	 * @brief ������ ���ҿ� -��ȣ�� ���մϴ�.
	 *
	 * @return ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Vector2<T> operator-() const
	{
		return Vector2<T>(-x, -y);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator+(const Vector2<T>& Instance) const
	{
		return Vector2<T>(x + Instance.x, y + Instance.y);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator+(Vector2<T>&& Instance) const
	{
		return Vector2<T>(x + Instance.x, y + Instance.y);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator-(const Vector2<T>& Instance) const
	{
		return Vector2<T>(x - Instance.x, y - Instance.y);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator-(Vector2<T>&& Instance) const
	{
		return Vector2<T>(x - Instance.x, y - Instance.y);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator*(const Vector2<T>& Instance) const
	{
		return Vector2<T>(x * Instance.x, y * Instance.y);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator*(Vector2<T>&& Instance) const
	{
		return Vector2<T>(x * Instance.x, y * Instance.y);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator+=(const Vector2<T>& Instance) noexcept
	{
		x += Instance.x;
		y += Instance.y;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator+=(Vector2<T>&& Instance) noexcept
	{
		x += Instance.x;
		y += Instance.y;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator-=(const Vector2<T>& Instance) noexcept
	{
		x -= Instance.x;
		y -= Instance.y;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator-=(Vector2<T>&& Instance) noexcept
	{
		x -= Instance.x;
		y -= Instance.y;

		return *this;
	}


	/**
	 * @brief �� ���Ͱ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ�ϴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Vector2<T>& Instance) noexcept
	{
		return (x == Instance.x) && (y == Instance.y);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ�ϴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Vector2<T>&& Instance) noexcept
	{
		return (x == Instance.x) && (y == Instance.y);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ���� �ʴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� �� �ϳ��� ��ġ���� ������ true, ��� ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Vector2<T>& Instance) noexcept
	{
		return (x != Instance.x) || (y != Instance.y);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ���� �ʴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� �� �ϳ��� ��ġ���� ������ true, ��� ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Vector2<T>&& Instance) noexcept
	{
		return (x != Instance.x) || (y != Instance.y);
	}


	/**
	 * @brief ������ ù ��° �����Դϴ�.
	 */
	T x;


	/**
	 * @brief ������ �� ��° �����Դϴ�.
	 */
	T y;
};


/**
 * @brief ���ø� ����� 3���� �����Դϴ�.
 */
template <typename T>
struct Vector3
{
	/**
	 * @brief ������ �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Vector3() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
		z = static_cast<T>(0);
	}


	/**
	 * @brief ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 */
	Vector3(T&& xx, T&& yy, T&& zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}


	/**
	 * @brief ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 */
	Vector3(const T& xx, const T& yy, const T& zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}


	/**
	 * @brief ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param Element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector3(T&& Element) noexcept
	{
		x = Element;
		y = Element;
		z = Element;
	}


	/**
	 * @brief ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param Element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector3(const T& Element) noexcept
	{
		x = Element;
		y = Element;
		z = Element;
	}


	/**
	 * @brief ������ ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	Vector3(const Vector3<T>& Instance) noexcept
	{
		x = Instance.x;
		y = Instance.y;
		z = Instance.z;
	}


	/**
	 * @brief ������ ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Vector3(Vector3<T>&& Instance) noexcept
	{
		x = Instance.x;
		y = Instance.y;
		z = Instance.z;
	}


	/**
	 * @brief ������ ���� ������ �Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector3<T>& operator=(const Vector3<T>& Instance) noexcept
	{
		if (this == &Instance) return *this;

		x = Instance.x;
		y = Instance.y;
		z = Instance.z;

		return *this;
	}


	/**
	 * @brief ������ ���� ������ �Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector3<T>& operator=(Vector3<T>&& Instance) noexcept
	{
		if (this == &Instance) return *this;

		x = Instance.x;
		y = Instance.y;
		z = Instance.z;

		return *this;
	}


	/**
	 * @brief ������ ���ҿ� -��ȣ�� ���մϴ�.
	 *
	 * @return ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Vector3<T> operator-() const
	{
		return Vector3<T>(-x, -y, -z);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator+(const Vector3<T>& Instance) const
	{
		return Vector3<T>(x + Instance.x, y + Instance.y, z + Instance.z);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator+(Vector3<T>&& Instance) const
	{
		return Vector3<T>(x + Instance.x, y + Instance.y, z + Instance.z);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator-(const Vector3<T>& Instance) const
	{
		return Vector3<T>(x - Instance.x, y - Instance.y, z - Instance.z);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator-(Vector3<T>&& Instance) const
	{
		return Vector3<T>(x - Instance.x, y - Instance.y, z - Instance.z);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator*(const Vector3<T>& Instance) const
	{
		return Vector3<T>(x * Instance.x, y * Instance.y, z * Instance.z);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator*(Vector3<T>&& Instance) const
	{
		return Vector3<T>(x * Instance.x, y * Instance.y, z * Instance.z);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector3<T>& operator+=(const Vector3<T>& Instance) noexcept
	{
		x += Instance.x;
		y += Instance.y;
		z += Instance.z;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector3<T>& operator+=(Vector3<T>&& Instance) noexcept
	{
		x += Instance.x;
		y += Instance.y;
		z += Instance.z;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector3<T>& operator-=(const Vector3<T>& Instance) noexcept
	{
		x -= Instance.x;
		y -= Instance.y;
		z -= Instance.z;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector3<T>& operator-=(Vector3<T>&& Instance) noexcept
	{
		x -= Instance.x;
		y -= Instance.y;
		z -= Instance.z;

		return *this;
	}


	/**
	 * @brief �� ���Ͱ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ�ϴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Vector3<T>& Instance) noexcept
	{
		return (x == Instance.x) && (y == Instance.y) && (z == Instance.z);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ�ϴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Vector3<T>&& Instance) noexcept
	{
		return (x == Instance.x) && (y == Instance.y) && (z == Instance.z);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ���� �ʴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� �� �ϳ��� ��ġ���� ������ true, ��� ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Vector3<T>& Instance) noexcept
	{
		return (x != Instance.x) || (y != Instance.y) || (z != Instance.z);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ���� �ʴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� �� �ϳ��� ��ġ���� ������ true, ��� ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Vector3<T>&& Instance) noexcept
	{
		return (x != Instance.x) || (y != Instance.y) || (z != Instance.z);
	}


	/**
	 * @brief ������ ù ��° �����Դϴ�.
	 */
	T x;


	/**
	 * @brief ������ �� ��° �����Դϴ�.
	 */
	T y;


	/**
	 * @brief ������ �� ��° �����Դϴ�.
	 */
	T z;
};


/**
 * @brief ���ø� ����� 4���� �����Դϴ�.
 */
template <typename T>
struct Vector4
{
	/**
	 * @brief ������ �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Vector4() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
		z = static_cast<T>(0);
		w = static_cast<T>(0);
	}


	/**
	 * @brief ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 * @param ww ������ w �����Դϴ�.
	 */
	Vector4(T&& xx, T&& yy, T&& zz, T&& ww)
	{
		x = xx;
		y = yy;
		z = zz;
		w = ww;
	}


	/**
	 * @brief ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 * @param ww ������ w �����Դϴ�.
	 */
	Vector4(const T& xx, const T& yy, const T& zz, const T& ww)
	{
		x = xx;
		y = yy;
		z = zz;
		w = ww;
	}


	/**
	 * @brief ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param Element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector4(T&& Element) noexcept
	{
		x = Element;
		y = Element;
		z = Element;
		w = Element;
	}


	/**
	 * @brief ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param Element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector4(const T& Element) noexcept
	{
		x = Element;
		y = Element;
		z = Element;
		w = Element;
	}


	/**
	 * @brief ������ ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	Vector4(const Vector4<T>& Instance) noexcept
	{
		x = Instance.x;
		y = Instance.y;
		z = Instance.z;
		w = Instance.w;
	}


	/**
	 * @brief ������ ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Vector4(Vector4<T>&& Instance) noexcept
	{
		x = Instance.x;
		y = Instance.y;
		z = Instance.z;
		w = Instance.w;
	}


	/**
	 * @brief ������ ���� ������ �Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector4<T>& operator=(const Vector4<T>& Instance) noexcept
	{
		if (this == &Instance) return *this;

		x = Instance.x;
		y = Instance.y;
		z = Instance.z;
		w = Instance.w;

		return *this;
	}


	/**
	 * @brief ������ ���� ������ �Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector4<T>& operator=(Vector4<T>&& Instance) noexcept
	{
		if (this == &Instance) return *this;

		x = Instance.x;
		y = Instance.y;
		z = Instance.z;
		w = Instance.w;

		return *this;
	}


	/**
	 * @brief ������ ���ҿ� -��ȣ�� ���մϴ�.
	 *
	 * @return ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Vector4<T> operator-() const
	{
		return Vector4<T>(-x, -y, -z, -w);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator+(const Vector4<T>& Instance) const
	{
		return Vector4<T>(x + Instance.x, y + Instance.y, z + Instance.z, w + Instance.w);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator+(Vector4<T>&& Instance) const
	{
		return Vector4<T>(x + Instance.x, y + Instance.y, z + Instance.z, w + Instance.w);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator-(const Vector4<T>& Instance) const
	{
		return Vector4<T>(x - Instance.x, y - Instance.y, z - Instance.z, w - Instance.w);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator-(Vector4<T>&& Instance) const
	{
		return Vector4<T>(x - Instance.x, y - Instance.y, z - Instance.z, w - Instance.w);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator*(const Vector4<T>& Instance) const
	{
		return Vector4<T>(x * Instance.x, y * Instance.y, z * Instance.z, w * Instance.w);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @param Instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator*(Vector4<T>&& Instance) const
	{
		return Vector4<T>(x * Instance.x, y * Instance.y, z * Instance.z, w * Instance.w);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector4<T>& operator+=(const Vector4<T>& Instance) noexcept
	{
		x += Instance.x;
		y += Instance.y;
		z += Instance.z;
		w += Instance.w;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector4<T>& operator+=(Vector4<T>&& Instance) noexcept
	{
		x += Instance.x;
		y += Instance.y;
		z += Instance.z;
		w += Instance.w;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector4<T>& operator-=(const Vector4<T>& Instance) noexcept
	{
		x -= Instance.x;
		y -= Instance.y;
		z -= Instance.z;
		w -= Instance.w;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector4<T>& operator-=(Vector4<T>&& Instance) noexcept
	{
		x -= Instance.x;
		y -= Instance.y;
		z -= Instance.z;
		w -= Instance.w;

		return *this;
	}


	/**
	 * @brief �� ���Ͱ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ�ϴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Vector4<T>& Instance) noexcept
	{
		return (x == Instance.x) && (y == Instance.y) && (z == Instance.z) && (w == Instance.w);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ�ϴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Vector4<T>&& Instance) noexcept
	{
		return (x == Instance.x) && (y == Instance.y) && (z == Instance.z) && (w == Instance.w);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ���� �ʴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� �� �ϳ��� ��ġ���� ������ true, ��� ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Vector4<T>& Instance) noexcept
	{
		return (x != Instance.x) || (y != Instance.y) || (z != Instance.z) || (w != Instance.w);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ���� �ʴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� �� �ϳ��� ��ġ���� ������ true, ��� ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Vector4<T>&& Instance) noexcept
	{
		return (x != Instance.x) || (y != Instance.y) || (z != Instance.z) || (w != Instance.w);
	}


	/**
	 * @brief ������ ù ��° �����Դϴ�.
	 */
	T x;


	/**
	 * @brief ������ �� ��° �����Դϴ�.
	 */
	T y;


	/**
	 * @brief ������ �� ��° �����Դϴ�.
	 */
	T z;


	/**
	 * @brief ������ �� ��° �����Դϴ�.
	 */
	T w;
};


/**
 * @brief ���ø� ����� 2x2 ����Դϴ�.
 */
template <typename T>
struct Matrix2x2
{
	/**
	 * @brief ����� �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Matrix2x2() noexcept
	{
		m[0][0] = static_cast<T>(0); m[0][1] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(0);
	}


	/**
	 * @brief ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
	 */
	Matrix2x2(
		T&& m00, T&& m01,
		T&& m10, T&& m11
	)
	{
		m[0][0] = m00; m[0][1] = m01;
		m[1][0] = m10; m[1][1] = m11;
	}


	/**
	 * @brief ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
	 */
	Matrix2x2(
		const T& m00, const T& m01,
		const T& m10, const T& m11
	)
	{
		m[0][0] = m00; m[0][1] = m01;
		m[1][0] = m10; m[1][1] = m11;
	}


	/**
	 * @brief ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param Element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix2x2(T&& Element) noexcept
	{
		m[0][0] = Element; m[0][1] = Element;
		m[1][0] = Element; m[1][1] = Element;
	}


	/**
	 * @brief ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param Element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix2x2(const T& Element) noexcept
	{
		m[0][0] = Element; m[0][1] = Element;
		m[1][0] = Element; m[1][1] = Element;
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix2x2(Matrix2x2<T>&& Instance) noexcept
	{
		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1];
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix2x2(const Matrix2x2<T>& Instance) noexcept
	{
		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1];
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator=(Matrix2x2<T>&& Instance) noexcept
	{
		if (this == &Instance) return *this;

		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1];

		return *this;
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator=(const Matrix2x2<T>& Instance) noexcept
	{
		if (this == &Instance) return *this;

		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1];

		return *this;
	}


	/**
	 * @brief ����� ��� ���ҿ� - ��ȣ�� ���մϴ�.
	 *
	 * @return ��� ���ҿ� - ��ȣ�� ���� ���ο� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator-() const
	{
		return Matrix2x2<T>(
			-m[0][0], -m[0][1],
			-m[1][0], -m[1][1]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator+(Matrix2x2<T>&& Instance)
	{
		return Matrix2x2<T>(
			m[0][0] + Instance.m[0][0], m[0][1] + Instance.m[0][1],
			m[1][0] + Instance.m[1][0], m[1][1] + Instance.m[1][1]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator+(const Matrix2x2<T>& Instance)
	{
		return Matrix2x2<T>(
			m[0][0] + Instance.m[0][0], m[0][1] + Instance.m[0][1],
			m[1][0] + Instance.m[1][0], m[1][1] + Instance.m[1][1]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator-(Matrix2x2<T>&& Instance)
	{
		return Matrix2x2<T>(
			m[0][0] - Instance.m[0][0], m[0][1] - Instance.m[0][1],
			m[1][0] - Instance.m[1][0], m[1][1] - Instance.m[1][1]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator-(const Matrix2x2<T>& Instance)
	{
		return Matrix2x2<T>(
			m[0][0] - Instance.m[0][0], m[0][1] - Instance.m[0][1],
			m[1][0] - Instance.m[1][0], m[1][1] - Instance.m[1][1]
			);
	}


	/**
	 * @brief �� ����� ���մϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator*(Matrix2x2<T>&& Instance)
	{
		return Matrix2x2(
			m[0][0] * Instance.m[0][0] + m[0][1] * Instance.m[1][0],
			m[0][0] * Instance.m[0][1] + m[0][1] * Instance.m[1][1],
			m[1][0] * Instance.m[0][0] + m[1][1] * Instance.m[1][0],
			m[1][0] * Instance.m[0][1] + m[1][1] * Instance.m[1][1]
		);
	}


	/**
	 * @brief �� ����� ���մϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator*(const Matrix2x2<T>& Instance)
	{
		return Matrix2x2(
			m[0][0] * Instance.m[0][0] + m[0][1] * Instance.m[1][0],
			m[0][0] * Instance.m[0][1] + m[0][1] * Instance.m[1][1],
			m[1][0] * Instance.m[0][0] + m[1][1] * Instance.m[1][0],
			m[1][0] * Instance.m[0][1] + m[1][1] * Instance.m[1][1]
		);
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator+=(Matrix2x2<T>&& Instance) noexcept
	{
		m[0][0] += Instance.m[0][0]; m[0][1] += Instance.m[0][1];
		m[1][0] += Instance.m[1][0]; m[1][1] += Instance.m[1][1];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator+=(const Matrix2x2<T>& Instance) noexcept
	{
		m[0][0] += Instance.m[0][0]; m[0][1] += Instance.m[0][1];
		m[1][0] += Instance.m[1][0]; m[1][1] += Instance.m[1][1];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator-=(Matrix2x2<T>&& Instance) noexcept
	{
		m[0][0] -= Instance.m[0][0]; m[0][1] -= Instance.m[0][1];
		m[1][0] -= Instance.m[1][0]; m[1][1] -= Instance.m[1][1];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator-=(const Matrix2x2<T>& Instance) noexcept
	{
		m[0][0] -= Instance.m[0][0]; m[0][1] -= Instance.m[0][1];
		m[1][0] -= Instance.m[1][0]; m[1][1] -= Instance.m[1][1];

		return *this;
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ�ϴ��� Ȯ���� ����Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Matrix2x2<T>&& Instance) noexcept
	{
		return (m[0][0] == Instance.m[0][0])
			&& (m[0][1] == Instance.m[0][1])
			&& (m[1][0] == Instance.m[1][0])
			&& (m[1][1] == Instance.m[1][1]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ�ϴ��� Ȯ���� ����Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Matrix2x2<T>& Instance) noexcept
	{
		return (m[0][0] == Instance.m[0][0])
			&& (m[0][1] == Instance.m[0][1])
			&& (m[1][0] == Instance.m[1][0])
			&& (m[1][1] == Instance.m[1][1]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param ��ġ���� �ʴ��� Ȯ���� �� �������Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��ġ���� ������ true, ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Matrix2x2<T>&& Instance) noexcept
	{
		return (m[0][0] != Instance.m[0][0])
			|| (m[0][1] != Instance.m[0][1])
			|| (m[1][0] != Instance.m[1][0])
			|| (m[1][1] != Instance.m[1][1]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param ��ġ���� �ʴ��� Ȯ���� �� �������Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��ġ���� ������ true, ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Matrix2x2<T>& Instance) noexcept
	{
		return (m[0][0] != Instance.m[0][0])
			|| (m[0][1] != Instance.m[0][1])
			|| (m[1][0] != Instance.m[1][0])
			|| (m[1][1] != Instance.m[1][1]);
	}


	/**
	 * @brief ����� ���� ��ķ� �����մϴ�.
	 */
	void Identify()
	{
		m[0][0] = static_cast<T>(1); m[0][1] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(1);
	}


	/**
	 * @brief ����� �����Դϴ�.
	 */
	T m[2][2];
};


/**
 * @brief ���ø� ����� 3x3 ����Դϴ�.
 */
template <typename T>
struct Matrix3x3
{
	/**
	 * @brief ����� �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Matrix3x3() noexcept
	{
		m[0][0] = static_cast<T>(0); m[0][1] = static_cast<T>(0); m[0][2] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(0); m[1][2] = static_cast<T>(0);
		m[2][0] = static_cast<T>(0); m[2][1] = static_cast<T>(0); m[2][2] = static_cast<T>(0);
	}


	/**
	 * @brief ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m02 ����� (0, 2) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
	 * @param m12 ����� (1, 2) �����Դϴ�.
	 * @param m20 ����� (2, 0) �����Դϴ�.
	 * @param m21 ����� (2, 1) �����Դϴ�.
	 * @param m22 ����� (2, 2) �����Դϴ�.
	 */
	Matrix3x3(
		T&& m00, T&& m01, T&& m02,
		T&& m10, T&& m11, T&& m12,
		T&& m20, T&& m21, T&& m22
	)
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
	}


	/**
	 * @brief ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m02 ����� (0, 2) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
	 * @param m12 ����� (1, 2) �����Դϴ�.
	 * @param m20 ����� (2, 0) �����Դϴ�.
	 * @param m21 ����� (2, 1) �����Դϴ�.
	 * @param m22 ����� (2, 2) �����Դϴ�.
	 */
	Matrix3x3(
		const T& m00, const T& m01, const T& m02,
		const T& m10, const T& m11, const T& m12,
		const T& m20, const T& m21, const T& m22
	)
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
	}


	/**
	 * @brief ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param Element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix3x3(T&& Element) noexcept
	{
		m[0][0] = Element; m[0][1] = Element; m[0][2] = Element;
		m[1][0] = Element; m[1][1] = Element; m[1][2] = Element;
		m[2][0] = Element; m[2][1] = Element; m[2][2] = Element;
	}


	/**
	 * @brief ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param Element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix3x3(const T& Element) noexcept
	{
		m[0][0] = Element; m[0][1] = Element; m[0][2] = Element;
		m[1][0] = Element; m[1][1] = Element; m[1][2] = Element;
		m[2][0] = Element; m[2][1] = Element; m[2][2] = Element;
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix3x3(Matrix3x3<T>&& Instance) noexcept
	{
		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1]; m[0][2] = Instance.m[0][2];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1]; m[1][2] = Instance.m[1][2];
		m[2][0] = Instance.m[2][0]; m[2][1] = Instance.m[2][1]; m[2][2] = Instance.m[2][2];
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix3x3(const Matrix3x3<T>& Instance) noexcept
	{
		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1]; m[0][2] = Instance.m[0][2];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1]; m[1][2] = Instance.m[1][2];
		m[2][0] = Instance.m[2][0]; m[2][1] = Instance.m[2][1]; m[2][2] = Instance.m[2][2];
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix3x3<T>& operator=(Matrix3x3<T>&& Instance) noexcept
	{
		if (this == &Instance) return *this;

		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1]; m[0][2] = Instance.m[0][2];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1]; m[1][2] = Instance.m[1][2];
		m[2][0] = Instance.m[2][0]; m[2][1] = Instance.m[2][1]; m[2][2] = Instance.m[2][2];

		return *this;
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix3x3<T>& operator=(const Matrix3x3<T>& Instance) noexcept
	{
		if (this == &Instance) return *this;

		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1]; m[0][2] = Instance.m[0][2];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1]; m[1][2] = Instance.m[1][2];
		m[2][0] = Instance.m[2][0]; m[2][1] = Instance.m[2][1]; m[2][2] = Instance.m[2][2];

		return *this;
	}


	/**
	 * @brief ����� ��� ���ҿ� - ��ȣ�� ���մϴ�.
	 *
	 * @return ��� ���ҿ� - ��ȣ�� ���� ���ο� ����� ��ȯ�մϴ�.
	 */
	Matrix3x3<T> operator-() const
	{
		return Matrix3x3<T>(
			-m[0][0], -m[0][1], -m[0][2],
			-m[1][0], -m[1][1], -m[1][2],
			-m[2][0], -m[2][1], -m[2][2]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix3x3<T> operator+(Matrix3x3<T>&& Instance)
	{
		return Matrix3x3<T>(
			m[0][0] + Instance.m[0][0], m[0][1] + Instance.m[0][1], m[0][2] + Instance.m[0][2],
			m[1][0] + Instance.m[1][0], m[1][1] + Instance.m[1][1], m[1][2] + Instance.m[1][2],
			m[2][0] + Instance.m[2][0], m[2][1] + Instance.m[2][1], m[2][2] + Instance.m[2][2]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix3x3<T> operator+(const Matrix3x3<T>& Instance)
	{
		return Matrix3x3<T>(
			m[0][0] + Instance.m[0][0], m[0][1] + Instance.m[0][1], m[0][2] + Instance.m[0][2],
			m[1][0] + Instance.m[1][0], m[1][1] + Instance.m[1][1], m[1][2] + Instance.m[1][2],
			m[2][0] + Instance.m[2][0], m[2][1] + Instance.m[2][1], m[2][2] + Instance.m[2][2]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Matrix3x3<T> operator-(Matrix3x3<T>&& Instance)
	{
		return Matrix3x3<T>(
			m[0][0] - Instance.m[0][0], m[0][1] - Instance.m[0][1], m[0][2] - Instance.m[0][2],
			m[1][0] - Instance.m[1][0], m[1][1] - Instance.m[1][1], m[1][2] - Instance.m[1][2],
			m[2][0] - Instance.m[2][0], m[2][1] - Instance.m[2][1], m[2][2] - Instance.m[2][2]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Matrix3x3<T> operator-(const Matrix3x3<T>& Instance)
	{
		return Matrix3x3<T>(
			m[0][0] - Instance.m[0][0], m[0][1] - Instance.m[0][1], m[0][2] - Instance.m[0][2],
			m[1][0] - Instance.m[1][0], m[1][1] - Instance.m[1][1], m[1][2] - Instance.m[1][2],
			m[2][0] - Instance.m[2][0], m[2][1] - Instance.m[2][1], m[2][2] - Instance.m[2][2]
			);
	}


	/**
	 * @brief �� ����� ���մϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix3x3<T> operator*(Matrix3x3<T>&& Instance)
	{
		return Matrix3x3(
			m[0][0] * Instance.m[0][0] + m[0][1] * Instance.m[1][0] + m[0][2] * Instance.m[2][0],
			m[0][0] * Instance.m[0][1] + m[0][1] * Instance.m[1][1] + m[0][2] * Instance.m[2][1],
			m[0][0] * Instance.m[0][2] + m[0][1] * Instance.m[1][2] + m[0][2] * Instance.m[2][2],
			m[1][0] * Instance.m[0][0] + m[1][1] * Instance.m[1][0] + m[1][2] * Instance.m[2][0],
			m[1][0] * Instance.m[0][1] + m[1][1] * Instance.m[1][1] + m[1][2] * Instance.m[2][1],
			m[1][0] * Instance.m[0][2] + m[1][1] * Instance.m[1][2] + m[1][2] * Instance.m[2][2],
			m[2][0] * Instance.m[0][0] + m[2][1] * Instance.m[1][0] + m[2][2] * Instance.m[2][0],
			m[2][0] * Instance.m[0][1] + m[2][1] * Instance.m[1][1] + m[2][2] * Instance.m[2][1],
			m[2][0] * Instance.m[0][2] + m[2][1] * Instance.m[1][2] + m[2][2] * Instance.m[2][2],
			);
	}


	/**
	 * @brief �� ����� ���մϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix3x3<T> operator*(const Matrix3x3<T>& Instance)
	{
		return Matrix3x3(
			m[0][0] * Instance.m[0][0] + m[0][1] * Instance.m[1][0] + m[0][2] * Instance.m[2][0],
			m[0][0] * Instance.m[0][1] + m[0][1] * Instance.m[1][1] + m[0][2] * Instance.m[2][1],
			m[0][0] * Instance.m[0][2] + m[0][1] * Instance.m[1][2] + m[0][2] * Instance.m[2][2],
			m[1][0] * Instance.m[0][0] + m[1][1] * Instance.m[1][0] + m[1][2] * Instance.m[2][0],
			m[1][0] * Instance.m[0][1] + m[1][1] * Instance.m[1][1] + m[1][2] * Instance.m[2][1],
			m[1][0] * Instance.m[0][2] + m[1][1] * Instance.m[1][2] + m[1][2] * Instance.m[2][2],
			m[2][0] * Instance.m[0][0] + m[2][1] * Instance.m[1][0] + m[2][2] * Instance.m[2][0],
			m[2][0] * Instance.m[0][1] + m[2][1] * Instance.m[1][1] + m[2][2] * Instance.m[2][1],
			m[2][0] * Instance.m[0][2] + m[2][1] * Instance.m[1][2] + m[2][2] * Instance.m[2][2],
			);
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix3x3<T>& operator+=(Matrix3x3<T>&& Instance) noexcept
	{
		m[0][0] += Instance.m[0][0]; m[0][1] += Instance.m[0][1]; m[0][2] += Instance.m[0][2];
		m[1][0] += Instance.m[1][0]; m[1][1] += Instance.m[1][1]; m[1][2] += Instance.m[1][2];
		m[2][0] += Instance.m[2][0]; m[2][1] += Instance.m[2][1]; m[2][2] += Instance.m[2][2];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix3x3<T>& operator+=(const Matrix3x3<T>& Instance) noexcept
	{
		m[0][0] += Instance.m[0][0]; m[0][1] += Instance.m[0][1]; m[0][2] += Instance.m[0][2];
		m[1][0] += Instance.m[1][0]; m[1][1] += Instance.m[1][1]; m[1][2] += Instance.m[1][2];
		m[2][0] += Instance.m[2][0]; m[2][1] += Instance.m[2][1]; m[2][2] += Instance.m[2][2];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix3x3<T>& operator-=(Matrix3x3<T>&& Instance) noexcept
	{
		m[0][0] -= Instance.m[0][0]; m[0][1] -= Instance.m[0][1]; m[0][2] -= Instance.m[0][2];
		m[1][0] -= Instance.m[1][0]; m[1][1] -= Instance.m[1][1]; m[1][2] -= Instance.m[1][2];
		m[2][0] -= Instance.m[2][0]; m[2][1] -= Instance.m[2][1]; m[2][2] -= Instance.m[2][2];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix3x3<T>& operator-=(const Matrix3x3<T>& Instance) noexcept
	{
		m[0][0] -= Instance.m[0][0]; m[0][1] -= Instance.m[0][1]; m[0][2] -= Instance.m[0][2];
		m[1][0] -= Instance.m[1][0]; m[1][1] -= Instance.m[1][1]; m[1][2] -= Instance.m[1][2];
		m[2][0] -= Instance.m[2][0]; m[2][1] -= Instance.m[2][1]; m[2][2] -= Instance.m[2][2];

		return *this;
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ�ϴ��� Ȯ���� ����Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Matrix3x3<T>&& Instance) noexcept
	{
		return (m[0][0] == Instance.m[0][0])
			&& (m[0][1] == Instance.m[0][1])
			&& (m[0][2] == Instance.m[0][2])
			&& (m[1][0] == Instance.m[1][0])
			&& (m[1][1] == Instance.m[1][1])
			&& (m[1][2] == Instance.m[1][2])
			&& (m[2][0] == Instance.m[2][0])
			&& (m[2][1] == Instance.m[2][1])
			&& (m[2][2] == Instance.m[2][2]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ�ϴ��� Ȯ���� ����Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Matrix3x3<T>& Instance) noexcept
	{
		return (m[0][0] == Instance.m[0][0])
			&& (m[0][1] == Instance.m[0][1])
			&& (m[0][2] == Instance.m[0][2])
			&& (m[1][0] == Instance.m[1][0])
			&& (m[1][1] == Instance.m[1][1])
			&& (m[1][2] == Instance.m[1][2])
			&& (m[2][0] == Instance.m[2][0])
			&& (m[2][1] == Instance.m[2][1])
			&& (m[2][2] == Instance.m[2][2]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param ��ġ���� �ʴ��� Ȯ���� �� �������Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��ġ���� ������ true, ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Matrix3x3<T>&& Instance) noexcept
	{
		return (m[0][0] != Instance.m[0][0])
			|| (m[0][1] != Instance.m[0][1])
			|| (m[0][2] != Instance.m[0][2])
			|| (m[1][0] != Instance.m[1][0])
			|| (m[1][1] != Instance.m[1][1])
			|| (m[1][2] != Instance.m[1][2])
			|| (m[2][0] != Instance.m[2][0])
			|| (m[2][1] != Instance.m[2][1])
			|| (m[2][2] != Instance.m[2][2]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param ��ġ���� �ʴ��� Ȯ���� �� �������Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��ġ���� ������ true, ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Matrix3x3<T>& Instance) noexcept
	{
		return (m[0][0] != Instance.m[0][0])
			|| (m[0][1] != Instance.m[0][1])
			|| (m[0][2] != Instance.m[0][2])
			|| (m[1][0] != Instance.m[1][0])
			|| (m[1][1] != Instance.m[1][1])
			|| (m[1][2] != Instance.m[1][2])
			|| (m[2][0] != Instance.m[2][0])
			|| (m[2][1] != Instance.m[2][1])
			|| (m[2][2] != Instance.m[2][2]);
	}


	/**
	 * @brief ����� ���� ��ķ� �����մϴ�.
	 */
	void Identify()
	{
		m[0][0] = static_cast<T>(1); m[0][1] = static_cast<T>(0); m[0][2] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(1); m[1][2] = static_cast<T>(0);
		m[2][0] = static_cast<T>(0); m[2][1] = static_cast<T>(0); m[2][2] = static_cast<T>(1);
	}


	/**
	 * @brief ����� �����Դϴ�.
	 */
	T m[3][3];
};


/**
 * @brief ���ø� ����� 4x4 ����Դϴ�.
 */
template <typename T>
struct Matrix4x4
{
	/**
	 * @brief ����� �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Matrix4x4() noexcept
	{
		m[0][0] = static_cast<T>(0); m[0][1] = static_cast<T>(0); m[0][2] = static_cast<T>(0); m[0][3] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(0); m[1][2] = static_cast<T>(0); m[1][3] = static_cast<T>(0);
		m[2][0] = static_cast<T>(0); m[2][1] = static_cast<T>(0); m[2][2] = static_cast<T>(0); m[2][3] = static_cast<T>(0);
		m[3][0] = static_cast<T>(0); m[3][1] = static_cast<T>(0); m[3][2] = static_cast<T>(0); m[3][3] = static_cast<T>(0);
	}


	/**
	 * @brief ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m02 ����� (0, 2) �����Դϴ�.
	 * @param m03 ����� (0, 3) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
	 * @param m12 ����� (1, 2) �����Դϴ�.
	 * @param m13 ����� (1, 3) �����Դϴ�.
	 * @param m20 ����� (2, 0) �����Դϴ�.
	 * @param m21 ����� (2, 1) �����Դϴ�.
	 * @param m22 ����� (2, 2) �����Դϴ�.
	 * @param m23 ����� (2, 3) �����Դϴ�.
	 * @param m30 ����� (3, 0) �����Դϴ�.
	 * @param m31 ����� (3, 1) �����Դϴ�.
	 * @param m32 ����� (3, 2) �����Դϴ�.
	 * @param m33 ����� (3, 3) �����Դϴ�.
	 */
	Matrix4x4(
		T&& m00, T&& m01, T&& m02, T&& m03,
		T&& m10, T&& m11, T&& m12, T&& m13,
		T&& m20, T&& m21, T&& m22, T&& m23,
		T&& m30, T&& m31, T&& m32, T&& m33
	)
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
		m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
	}


	/**
	 * @brief ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m02 ����� (0, 2) �����Դϴ�.
	 * @param m03 ����� (0, 3) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
	 * @param m12 ����� (1, 2) �����Դϴ�.
	 * @param m13 ����� (1, 3) �����Դϴ�.
	 * @param m20 ����� (2, 0) �����Դϴ�.
	 * @param m21 ����� (2, 1) �����Դϴ�.
	 * @param m22 ����� (2, 2) �����Դϴ�.
	 * @param m23 ����� (2, 3) �����Դϴ�.
	 * @param m30 ����� (3, 0) �����Դϴ�.
	 * @param m31 ����� (3, 1) �����Դϴ�.
	 * @param m32 ����� (3, 2) �����Դϴ�.
	 * @param m33 ����� (3, 3) �����Դϴ�.
	 */
	Matrix4x4(
		const T& m00, const T& m01, const T& m02, const T& m03,
		const T& m10, const T& m11, const T& m12, const T& m13,
		const T& m20, const T& m21, const T& m22, const T& m23,
		const T& m30, const T& m31, const T& m32, const T& m33
	)
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
		m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
	}


	/**
	 * @brief ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param Element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix4x4(T&& Element) noexcept
	{
		m[0][0] = Element; m[0][1] = Element; m[0][2] = Element; m[0][3] = Element;
		m[1][0] = Element; m[1][1] = Element; m[1][2] = Element; m[1][3] = Element;
		m[2][0] = Element; m[2][1] = Element; m[2][2] = Element; m[2][3] = Element;
		m[3][0] = Element; m[3][1] = Element; m[3][2] = Element; m[3][3] = Element;
	}


	/**
	 * @brief ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param Element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix4x4(const T& Element) noexcept
	{
		m[0][0] = Element; m[0][1] = Element; m[0][2] = Element; m[0][3] = Element;
		m[1][0] = Element; m[1][1] = Element; m[1][2] = Element; m[1][3] = Element;
		m[2][0] = Element; m[2][1] = Element; m[2][2] = Element; m[2][3] = Element;
		m[3][0] = Element; m[3][1] = Element; m[3][2] = Element; m[3][3] = Element;
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix4x4(Matrix4x4<T>&& Instance) noexcept
	{
		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1]; m[0][2] = Instance.m[0][2]; m[0][3] = Instance.m[0][3];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1]; m[1][2] = Instance.m[1][2]; m[1][3] = Instance.m[1][3];
		m[2][0] = Instance.m[2][0]; m[2][1] = Instance.m[2][1]; m[2][2] = Instance.m[2][2]; m[2][3] = Instance.m[2][3];
		m[3][0] = Instance.m[3][0]; m[3][1] = Instance.m[3][1]; m[3][2] = Instance.m[3][2]; m[3][3] = Instance.m[3][3];
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix4x4(const Matrix4x4<T>& Instance) noexcept
	{
		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1]; m[0][2] = Instance.m[0][2]; m[0][3] = Instance.m[0][3];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1]; m[1][2] = Instance.m[1][2]; m[1][3] = Instance.m[1][3];
		m[2][0] = Instance.m[2][0]; m[2][1] = Instance.m[2][1]; m[2][2] = Instance.m[2][2]; m[2][3] = Instance.m[2][3];
		m[3][0] = Instance.m[3][0]; m[3][1] = Instance.m[3][1]; m[3][2] = Instance.m[3][2]; m[3][3] = Instance.m[3][3];
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix4x4<T>& operator=(Matrix4x4<T>&& Instance) noexcept
	{
		if (this == &Instance) return *this;

		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1]; m[0][2] = Instance.m[0][2]; m[0][3] = Instance.m[0][3];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1]; m[1][2] = Instance.m[1][2]; m[1][3] = Instance.m[1][3];
		m[2][0] = Instance.m[2][0]; m[2][1] = Instance.m[2][1]; m[2][2] = Instance.m[2][2]; m[2][3] = Instance.m[2][3];
		m[3][0] = Instance.m[3][0]; m[3][1] = Instance.m[3][1]; m[3][2] = Instance.m[3][2]; m[3][3] = Instance.m[3][3];

		return *this;
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param Instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix4x4<T>& operator=(const Matrix4x4<T>& Instance) noexcept
	{
		if (this == &Instance) return *this;

		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1]; m[0][2] = Instance.m[0][2]; m[0][3] = Instance.m[0][3];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1]; m[1][2] = Instance.m[1][2]; m[1][3] = Instance.m[1][3];
		m[2][0] = Instance.m[2][0]; m[2][1] = Instance.m[2][1]; m[2][2] = Instance.m[2][2]; m[2][3] = Instance.m[2][3];
		m[3][0] = Instance.m[3][0]; m[3][1] = Instance.m[3][1]; m[3][2] = Instance.m[3][2]; m[3][3] = Instance.m[3][3];

		return *this;
	}


	/**
	 * @brief ����� ��� ���ҿ� - ��ȣ�� ���մϴ�.
	 *
	 * @return ��� ���ҿ� - ��ȣ�� ���� ���ο� ����� ��ȯ�մϴ�.
	 */
	Matrix4x4<T> operator-() const
	{
		return Matrix4x4<T>(
			-m[0][0], -m[0][1], -m[0][2], -m[0][3],
			-m[1][0], -m[1][1], -m[1][2], -m[1][3],
			-m[2][0], -m[2][1], -m[2][2], -m[2][3],
			-m[3][0], -m[3][1], -m[3][2], -m[3][3]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix4x4<T> operator+(Matrix4x4<T>&& Instance)
	{
		return Matrix4x4<T>(
			m[0][0] + Instance.m[0][0], m[0][1] + Instance.m[0][1], m[0][2] + Instance.m[0][2], m[0][3] + Instance.m[0][3],
			m[1][0] + Instance.m[1][0], m[1][1] + Instance.m[1][1], m[1][2] + Instance.m[1][2], m[1][3] + Instance.m[1][3],
			m[2][0] + Instance.m[2][0], m[2][1] + Instance.m[2][1], m[2][2] + Instance.m[2][2], m[2][3] + Instance.m[2][3],
			m[3][0] + Instance.m[3][0], m[3][1] + Instance.m[3][1], m[3][2] + Instance.m[3][2], m[3][3] + Instance.m[3][3]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix4x4<T> operator+(const Matrix4x4<T>& Instance)
	{
		return Matrix4x4<T>(
			m[0][0] + Instance.m[0][0], m[0][1] + Instance.m[0][1], m[0][2] + Instance.m[0][2], m[0][3] + Instance.m[0][3],
			m[1][0] + Instance.m[1][0], m[1][1] + Instance.m[1][1], m[1][2] + Instance.m[1][2], m[1][3] + Instance.m[1][3],
			m[2][0] + Instance.m[2][0], m[2][1] + Instance.m[2][1], m[2][2] + Instance.m[2][2], m[2][3] + Instance.m[2][3],
			m[3][0] + Instance.m[3][0], m[3][1] + Instance.m[3][1], m[3][2] + Instance.m[3][2], m[3][3] + Instance.m[3][3]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Matrix4x4<T> operator-(Matrix4x4<T>&& Instance)
	{
		return Matrix4x4<T>(
			m[0][0] - Instance.m[0][0], m[0][1] - Instance.m[0][1], m[0][2] - Instance.m[0][2], m[0][3] - Instance.m[0][3],
			m[1][0] - Instance.m[1][0], m[1][1] - Instance.m[1][1], m[1][2] - Instance.m[1][2], m[1][3] - Instance.m[1][3],
			m[2][0] - Instance.m[2][0], m[2][1] - Instance.m[2][1], m[2][2] - Instance.m[2][2], m[2][3] - Instance.m[2][3],
			m[3][0] - Instance.m[3][0], m[3][1] - Instance.m[3][1], m[3][2] - Instance.m[3][2], m[3][3] - Instance.m[3][3]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Matrix4x4<T> operator-(const Matrix4x4<T>& Instance)
	{
		return Matrix4x4<T>(
			m[0][0] - Instance.m[0][0], m[0][1] - Instance.m[0][1], m[0][2] - Instance.m[0][2], m[0][3] - Instance.m[0][3],
			m[1][0] - Instance.m[1][0], m[1][1] - Instance.m[1][1], m[1][2] - Instance.m[1][2], m[1][3] - Instance.m[1][3],
			m[2][0] - Instance.m[2][0], m[2][1] - Instance.m[2][1], m[2][2] - Instance.m[2][2], m[2][3] - Instance.m[2][3],
			m[3][0] - Instance.m[3][0], m[3][1] - Instance.m[3][1], m[3][2] - Instance.m[3][2], m[3][3] - Instance.m[3][3]
			);
	}


	/**
	 * @brief �� ����� ���մϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix4x4<T> operator*(Matrix4x4<T>&& Instance)
	{
		return Matrix4x4(
			m[0][0] * Instance.m[0][0] + m[0][1] * Instance.m[1][0] + m[0][2] * Instance.m[2][0] + m[0][3] * Instance.m[3][0],
			m[0][0] * Instance.m[0][1] + m[0][1] * Instance.m[1][1] + m[0][2] * Instance.m[2][1] + m[0][3] * Instance.m[3][1],
			m[0][0] * Instance.m[0][2] + m[0][1] * Instance.m[1][2] + m[0][2] * Instance.m[2][2] + m[0][3] * Instance.m[3][2],
			m[0][0] * Instance.m[0][3] + m[0][1] * Instance.m[1][3] + m[0][2] * Instance.m[2][3] + m[0][3] * Instance.m[3][3],
			m[1][0] * Instance.m[0][0] + m[1][1] * Instance.m[1][0] + m[1][2] * Instance.m[2][0] + m[1][3] * Instance.m[3][0],
			m[1][0] * Instance.m[0][1] + m[1][1] * Instance.m[1][1] + m[1][2] * Instance.m[2][1] + m[1][3] * Instance.m[3][1],
			m[1][0] * Instance.m[0][2] + m[1][1] * Instance.m[1][2] + m[1][2] * Instance.m[2][2] + m[1][3] * Instance.m[3][2],
			m[1][0] * Instance.m[0][3] + m[1][1] * Instance.m[1][3] + m[1][2] * Instance.m[2][3] + m[1][3] * Instance.m[3][3],
			m[2][0] * Instance.m[0][0] + m[2][1] * Instance.m[1][0] + m[2][2] * Instance.m[2][0] + m[2][3] * Instance.m[3][0],
			m[2][0] * Instance.m[0][1] + m[2][1] * Instance.m[1][1] + m[2][2] * Instance.m[2][1] + m[2][3] * Instance.m[3][1],
			m[2][0] * Instance.m[0][2] + m[2][1] * Instance.m[1][2] + m[2][2] * Instance.m[2][2] + m[2][3] * Instance.m[3][2],
			m[2][0] * Instance.m[0][3] + m[2][1] * Instance.m[1][3] + m[2][2] * Instance.m[2][3] + m[2][3] * Instance.m[3][3],
			m[3][0] * Instance.m[0][0] + m[3][1] * Instance.m[1][0] + m[3][2] * Instance.m[2][0] + m[3][3] * Instance.m[3][0],
			m[3][0] * Instance.m[0][1] + m[3][1] * Instance.m[1][1] + m[3][2] * Instance.m[2][1] + m[3][3] * Instance.m[3][1],
			m[3][0] * Instance.m[0][2] + m[3][1] * Instance.m[1][2] + m[3][2] * Instance.m[2][2] + m[3][3] * Instance.m[3][2],
			m[3][0] * Instance.m[0][3] + m[3][1] * Instance.m[1][3] + m[3][2] * Instance.m[2][3] + m[3][3] * Instance.m[3][3],
			);
	}


	/**
	 * @brief �� ����� ���մϴ�.
	 *
	 * @param Instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix4x4<T> operator*(const Matrix4x4<T>& Instance)
	{
		return Matrix4x4(
			m[0][0] * Instance.m[0][0] + m[0][1] * Instance.m[1][0] + m[0][2] * Instance.m[2][0] + m[0][3] * Instance.m[3][0],
			m[0][0] * Instance.m[0][1] + m[0][1] * Instance.m[1][1] + m[0][2] * Instance.m[2][1] + m[0][3] * Instance.m[3][1],
			m[0][0] * Instance.m[0][2] + m[0][1] * Instance.m[1][2] + m[0][2] * Instance.m[2][2] + m[0][3] * Instance.m[3][2],
			m[0][0] * Instance.m[0][3] + m[0][1] * Instance.m[1][3] + m[0][2] * Instance.m[2][3] + m[0][3] * Instance.m[3][3],
			m[1][0] * Instance.m[0][0] + m[1][1] * Instance.m[1][0] + m[1][2] * Instance.m[2][0] + m[1][3] * Instance.m[3][0],
			m[1][0] * Instance.m[0][1] + m[1][1] * Instance.m[1][1] + m[1][2] * Instance.m[2][1] + m[1][3] * Instance.m[3][1],
			m[1][0] * Instance.m[0][2] + m[1][1] * Instance.m[1][2] + m[1][2] * Instance.m[2][2] + m[1][3] * Instance.m[3][2],
			m[1][0] * Instance.m[0][3] + m[1][1] * Instance.m[1][3] + m[1][2] * Instance.m[2][3] + m[1][3] * Instance.m[3][3],
			m[2][0] * Instance.m[0][0] + m[2][1] * Instance.m[1][0] + m[2][2] * Instance.m[2][0] + m[2][3] * Instance.m[3][0],
			m[2][0] * Instance.m[0][1] + m[2][1] * Instance.m[1][1] + m[2][2] * Instance.m[2][1] + m[2][3] * Instance.m[3][1],
			m[2][0] * Instance.m[0][2] + m[2][1] * Instance.m[1][2] + m[2][2] * Instance.m[2][2] + m[2][3] * Instance.m[3][2],
			m[2][0] * Instance.m[0][3] + m[2][1] * Instance.m[1][3] + m[2][2] * Instance.m[2][3] + m[2][3] * Instance.m[3][3],
			m[3][0] * Instance.m[0][0] + m[3][1] * Instance.m[1][0] + m[3][2] * Instance.m[2][0] + m[3][3] * Instance.m[3][0],
			m[3][0] * Instance.m[0][1] + m[3][1] * Instance.m[1][1] + m[3][2] * Instance.m[2][1] + m[3][3] * Instance.m[3][1],
			m[3][0] * Instance.m[0][2] + m[3][1] * Instance.m[1][2] + m[3][2] * Instance.m[2][2] + m[3][3] * Instance.m[3][2],
			m[3][0] * Instance.m[0][3] + m[3][1] * Instance.m[1][3] + m[3][2] * Instance.m[2][3] + m[3][3] * Instance.m[3][3],
			);
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix4x4<T>& operator+=(Matrix4x4<T>&& Instance) noexcept
	{
		m[0][0] += Instance.m[0][0]; m[0][1] += Instance.m[0][1]; m[0][2] += Instance.m[0][2]; m[0][3] += Instance.m[0][3];
		m[1][0] += Instance.m[1][0]; m[1][1] += Instance.m[1][1]; m[1][2] += Instance.m[1][2]; m[1][3] += Instance.m[1][3];
		m[2][0] += Instance.m[2][0]; m[2][1] += Instance.m[2][1]; m[2][2] += Instance.m[2][2]; m[2][3] += Instance.m[2][3];
		m[3][0] += Instance.m[3][0]; m[3][1] += Instance.m[3][1]; m[3][2] += Instance.m[3][2]; m[3][3] += Instance.m[3][3];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix4x4<T>& operator+=(const Matrix4x4<T>& Instance) noexcept
	{
		m[0][0] += Instance.m[0][0]; m[0][1] += Instance.m[0][1]; m[0][2] += Instance.m[0][2]; m[0][3] += Instance.m[0][3];
		m[1][0] += Instance.m[1][0]; m[1][1] += Instance.m[1][1]; m[1][2] += Instance.m[1][2]; m[1][3] += Instance.m[1][3];
		m[2][0] += Instance.m[2][0]; m[2][1] += Instance.m[2][1]; m[2][2] += Instance.m[2][2]; m[2][3] += Instance.m[2][3];
		m[3][0] += Instance.m[3][0]; m[3][1] += Instance.m[3][1]; m[3][2] += Instance.m[3][2]; m[3][3] += Instance.m[3][3];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix4x4<T>& operator-=(Matrix4x4<T>&& Instance) noexcept
	{
		m[0][0] -= Instance.m[0][0]; m[0][1] -= Instance.m[0][1]; m[0][2] -= Instance.m[0][2]; m[0][3] -= Instance.m[0][3];
		m[1][0] -= Instance.m[1][0]; m[1][1] -= Instance.m[1][1]; m[1][2] -= Instance.m[1][2]; m[1][3] -= Instance.m[1][3];
		m[2][0] -= Instance.m[2][0]; m[2][1] -= Instance.m[2][1]; m[2][2] -= Instance.m[2][2]; m[2][3] -= Instance.m[2][3];
		m[3][0] -= Instance.m[3][0]; m[3][1] -= Instance.m[3][1]; m[3][2] -= Instance.m[3][2]; m[3][3] -= Instance.m[3][3];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param Instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix4x4<T>& operator-=(const Matrix4x4<T>& Instance) noexcept
	{
		m[0][0] -= Instance.m[0][0]; m[0][1] -= Instance.m[0][1]; m[0][2] -= Instance.m[0][2]; m[0][3] -= Instance.m[0][3];
		m[1][0] -= Instance.m[1][0]; m[1][1] -= Instance.m[1][1]; m[1][2] -= Instance.m[1][2]; m[1][3] -= Instance.m[1][3];
		m[2][0] -= Instance.m[2][0]; m[2][1] -= Instance.m[2][1]; m[2][2] -= Instance.m[2][2]; m[2][3] -= Instance.m[2][3];
		m[3][0] -= Instance.m[3][0]; m[3][1] -= Instance.m[3][1]; m[3][2] -= Instance.m[3][2]; m[3][3] -= Instance.m[3][3];

		return *this;
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ�ϴ��� Ȯ���� ����Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Matrix4x4<T>&& Instance) noexcept
	{
		return (m[0][0] == Instance.m[0][0])
			&& (m[0][1] == Instance.m[0][1])
			&& (m[0][2] == Instance.m[0][2])
			&& (m[0][3] == Instance.m[0][3])
			&& (m[1][0] == Instance.m[1][0])
			&& (m[1][1] == Instance.m[1][1])
			&& (m[1][2] == Instance.m[1][2])
			&& (m[1][3] == Instance.m[1][3])
			&& (m[2][0] == Instance.m[2][0])
			&& (m[2][1] == Instance.m[2][1])
			&& (m[2][2] == Instance.m[2][2])
			&& (m[2][3] == Instance.m[2][3])
			&& (m[3][0] == Instance.m[3][0])
			&& (m[3][1] == Instance.m[3][1])
			&& (m[3][2] == Instance.m[3][2])
			&& (m[3][3] == Instance.m[3][3]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param Instance ��ġ�ϴ��� Ȯ���� ����Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Matrix4x4<T>& Instance) noexcept
	{
		return (m[0][0] == Instance.m[0][0])
			&& (m[0][1] == Instance.m[0][1])
			&& (m[0][2] == Instance.m[0][2])
			&& (m[0][3] == Instance.m[0][3])
			&& (m[1][0] == Instance.m[1][0])
			&& (m[1][1] == Instance.m[1][1])
			&& (m[1][2] == Instance.m[1][2])
			&& (m[1][3] == Instance.m[1][3])
			&& (m[2][0] == Instance.m[2][0])
			&& (m[2][1] == Instance.m[2][1])
			&& (m[2][2] == Instance.m[2][2])
			&& (m[2][3] == Instance.m[2][3])
			&& (m[3][0] == Instance.m[3][0])
			&& (m[3][1] == Instance.m[3][1])
			&& (m[3][2] == Instance.m[3][2])
			&& (m[3][3] == Instance.m[3][3]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param ��ġ���� �ʴ��� Ȯ���� �� �������Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��ġ���� ������ true, ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Matrix4x4<T>&& Instance) noexcept
	{
		return (m[0][0] != Instance.m[0][0])
			|| (m[0][1] != Instance.m[0][1])
			|| (m[0][2] != Instance.m[0][2])
			|| (m[0][3] != Instance.m[0][3])
			|| (m[1][0] != Instance.m[1][0])
			|| (m[1][1] != Instance.m[1][1])
			|| (m[1][2] != Instance.m[1][2])
			|| (m[1][3] != Instance.m[1][3])
			|| (m[2][0] != Instance.m[2][0])
			|| (m[2][1] != Instance.m[2][1])
			|| (m[2][2] != Instance.m[2][2])
			|| (m[2][3] != Instance.m[2][3])
			|| (m[3][0] != Instance.m[3][0])
			|| (m[3][1] != Instance.m[3][1])
			|| (m[3][2] != Instance.m[3][2])
			|| (m[3][3] != Instance.m[3][3]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param ��ġ���� �ʴ��� Ȯ���� �� �������Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��ġ���� ������ true, ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Matrix4x4<T>& Instance) noexcept
	{
		return (m[0][0] != Instance.m[0][0])
			|| (m[0][1] != Instance.m[0][1])
			|| (m[0][2] != Instance.m[0][2])
			|| (m[0][3] != Instance.m[0][3])
			|| (m[1][0] != Instance.m[1][0])
			|| (m[1][1] != Instance.m[1][1])
			|| (m[1][2] != Instance.m[1][2])
			|| (m[1][3] != Instance.m[1][3])
			|| (m[2][0] != Instance.m[2][0])
			|| (m[2][1] != Instance.m[2][1])
			|| (m[2][2] != Instance.m[2][2])
			|| (m[2][3] != Instance.m[2][3])
			|| (m[3][0] != Instance.m[3][0])
			|| (m[3][1] != Instance.m[3][1])
			|| (m[3][2] != Instance.m[3][2])
			|| (m[3][3] != Instance.m[3][3]);
	}


	/**
	 * @brief ����� ���� ��ķ� �����մϴ�.
	 */
	void Identify()
	{
		m[0][0] = static_cast<T>(1); m[0][1] = static_cast<T>(0); m[0][2] = static_cast<T>(0); m[0][3] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(1); m[1][2] = static_cast<T>(0); m[1][3] = static_cast<T>(0);
		m[2][0] = static_cast<T>(0); m[2][1] = static_cast<T>(0); m[2][2] = static_cast<T>(1); m[2][3] = static_cast<T>(0);
		m[3][0] = static_cast<T>(0); m[3][1] = static_cast<T>(0); m[3][2] = static_cast<T>(0); m[3][3] = static_cast<T>(1);
	}


	/**
	 * @brief ����� �����Դϴ�.
	 */
	T m[4][4];
};


/**
 * @brief int Ÿ���� 2���� �����Դϴ�.
 */
using Vec2i = Vector2<int32_t>;


/**
 * @brief float Ÿ���� 2���� �����Դϴ�.
 */
using Vec2f = Vector2<float>;


/**
 * @brief int Ÿ���� 3���� �����Դϴ�.
 */
using Vec3i = Vector3<int32_t>;


/**
 * @brief float Ÿ���� 3���� �����Դϴ�.
 */
using Vec3f = Vector3<float>;


/**
 * @brief int Ÿ���� 4���� �����Դϴ�.
 */
using Vec4i = Vector4<int32_t>;


/**
 * @brief float Ÿ���� 4���� �����Դϴ�.
 */
using Vec4f = Vector4<float>;


/**
 * @brief int Ÿ���� 2x2 ����Դϴ�.
 */
using Matrix2x2I = Matrix2x2<int32_t>;


/**
 * @brief float Ÿ���� 2x2 ����Դϴ�.
 */
using Matrix2x2F = Matrix2x2<float>;


/**
 * @brief int Ÿ���� 3x3 ����Դϴ�.
 */
using Matrix3x3I = Matrix3x3<int32_t>;


/**
 * @brief float Ÿ���� 3x3 ����Դϴ�.
 */
using Matrix3x3F = Matrix3x3<float>;


/**
 * @brief int Ÿ���� 4x4 ����Դϴ�.
 */
using Matrix4x4I = Matrix4x4<int32_t>;


/**
 * @brief float Ÿ���� 4x4 ����Դϴ�.
 */
using Matrix4x4F = Matrix4x4<float>;


/**
 * @brief ���� ������ �����մϴ�.
 */
using LinearColor = Vec4f;


/**
 * @brief �⺻ ������ �����մϴ�.
 */
namespace Color
{
	const LinearColor BLACK   = LinearColor(0.0f, 0.0f, 0.0f, 1.0f);
	const LinearColor RED     = LinearColor(1.0f, 0.0f, 0.0f, 1.0f);
	const LinearColor GREEN   = LinearColor(0.0f, 1.0f, 0.0f, 1.0f);
	const LinearColor BLUE    = LinearColor(0.0f, 0.0f, 1.0f, 1.0f);
	const LinearColor YELLOW  = LinearColor(1.0f, 1.0f, 0.0f, 1.0f);
	const LinearColor MAGENTA = LinearColor(1.0f, 0.0f, 1.0f, 1.0f);
	const LinearColor CYAN    = LinearColor(0.0f, 1.0f, 1.0f, 1.0f);
	const LinearColor WHITE   = LinearColor(1.0f, 1.0f, 1.0f, 1.0f);
	const LinearColor GRAY    = LinearColor(0.5f, 0.5f, 0.5f, 1.0f);
}


/**
 * @brief ���� ������ ������ �����մϴ�.
 */
namespace Vertex
{
	/**
	 * @brief ��ġ�� ������ ������ �����Դϴ�.
	 */
	struct PositionColor
	{
		Vec3f Position;
		Vec4f Color;
	};


	/**
	 * @brief ��ġ�� �ؽ�ó ��ġ�� ������ �����Դϴ�.
	 */
	struct PositionUV
	{
		Vec3f Position;
		Vec2f UV;
	};
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


/**
 * @brief ������ ������ �����մϴ�.
 *
 * @param MinValue ������ ���� ������ �ּڰ��Դϴ�.
 * @param MaxValue ������ ���� ������ �ִ��Դϴ�.
 *
 * @return ������ ������ ������ ��ȯ�մϴ�.
 */
inline int32_t GenerateRandomInt(int32_t MinValue, int32_t MaxValue)
{
	std::random_device RandomDevice;
	std::mt19937 Generator(RandomDevice());
	std::uniform_int_distribution<int32_t> Distribution(std::min<int32_t>(MinValue, MaxValue), std::max<int32_t>(MinValue, MaxValue));

	return Distribution(Generator);
}


/**
 * @brief ������ �Ǽ��� �����մϴ�.
 *
 * @param MinValue ������ ���� ������ �ּڰ��Դϴ�.
 * @param MaxValue ������ ���� ������ �ִ��Դϴ�.
 *
 * @return ������ ������ �Ǽ��� ��ȯ�մϴ�.
 */
inline float GenerateRandomFloat(float MinValue, float MaxValue)
{
	std::random_device RandomDevice;
	std::mt19937 Generator(RandomDevice());
	std::uniform_real_distribution<float> Distribution(std::min<float>(MinValue, MaxValue), std::max<float>(MinValue, MaxValue));

	return Distribution(Generator);
}
