#pragma once

#include "Macro.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <chrono>
#include <random>


/**
 * @brief float 타입의 파이(π) 값입니다.
 */
const float PI_F = 3.1415926535F;


/**
 * @brief double 타입의 파이(π) 값입니다.
 */
const double PI_D = 3.1415926535897931;


/**
 * @brief float 타입의 타입의 엡실론(ε) 값입니다.
 */
const float EPSILON_F = std::numeric_limits<float>::epsilon();


/**
 * @brief double 타입의 엡실론(ε) 값입니다.
 */
const double EPSILON_D = std::numeric_limits<double>::epsilon();


/**
 * @brief float 타입의 무한대 값입니다.
 */
const float INFINITY_F = std::numeric_limits<float>::infinity();


/**
 * @brief double 타입의 무한대 값입니다.
 */
const double INFINITY_D = std::numeric_limits<double>::infinity();


/**
 * @brief float 타입의 음의 무한대 값입니다.
 */
const float NINFINITY_F = -std::numeric_limits<float>::infinity();


/**
 * @brief double 타입의 음의 무한대 값입니다.
 */
const double NINFINITY_D = -std::numeric_limits<double>::infinity();


/**
 * @brief 라디안 각을 육십분법 각으로 변환합니다.
 *
 * @param Radian 변환할 라디안 각입니다.
 *
 * @return 변환된 육십분법 각입니다.
 */
inline float ToDegree(float Radian)
{
	return (Radian * 180.0f) / PI_F;
}


/**
 * @brief 라디안 각을 육십분법 각으로 변환합니다.
 *
 * @param Radian 변환할 라디안 각입니다.
 *
 * @return 변환된 육십분법 각입니다.
 */
inline double ToDegree(double Radian)
{
	return (Radian * 180.0) / PI_D;
}


/**
 * @brief 육십분법 각을 라디안 각으로 변환합니다.
 *
 * @param Degree 변환할 육십분법 각입니다.
 *
 * @return 변환된 라디안 각입니다.
 */
inline float ToRadian(float Degree)
{
	return (Degree * PI_F) / 180.0f;
}


/**
 * @brief 육십분법 각을 라디안 각으로 변환합니다.
 *
 * @param Degree 변환할 육십분법 각입니다.
 *
 * @return 변환된 라디안 각입니다.
 */
inline double ToRadian(double Degree)
{
	return (Degree * PI_D) / 180.0;
}


/**
 * @brief 0에 한없이 가까운 값인지 확인합니다.
 *
 * @param Value 0에 한없이 가까운지 확인할 값입니다.
 * @param Epsilon 엡실론 값입니다.
 * 
 * @return 엡실론 값보다 작다면 true, 그렇지 않다면 false를 반환합니다.
 */
inline bool IsNearZero(const float& Value, const float Epsilon = EPSILON_F)
{
	return (fabs(Value) <= Epsilon);
}


/**
 * @brief 템플릿 기반의 2차원 벡터입니다.
 */
template <typename T>
struct Vector2
{
	/**
	 * @brief 벡터의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Vector2() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
	}


	/**
	 * @brief 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 */
	Vector2(T&& xx, T&& yy)
	{
		x = xx;
		y = yy;
	}


	/**
	 * @brief 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 */
	Vector2(const T& xx, const T& yy)
	{
		x = xx;
		y = yy;
	}


	/**
	 * @brief 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param Element 모든 원소를 초기화 할 값입니다.
	 */
	Vector2(T&& Element) noexcept
	{
		x = Element;
		y = Element;
	}


	/**
	 * @brief 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param Element 모든 원소를 초기화 할 값입니다.
	 */
	Vector2(const T& Element) noexcept
	{
		x = Element;
		y = Element;
	}


	/**
	 * @brief 벡터의 복사 생성자입니다.
	 *
	 * @param Instance 원소를 복사할 벡터의 인스턴스입니다.
	 */
	Vector2(const Vector2<T>& Instance) noexcept
	{
		x = Instance.x;
		y = Instance.y;
	}


	/**
	 * @brief 벡터의 복사 생성자입니다.
	 *
	 * @param Instance 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	Vector2(Vector2<T>&& Instance) noexcept
	{
		x = Instance.x;
		y = Instance.y;
	}


	/**
	 * @brief 벡터의 대입 연산자 입니다.
	 *
	 * @param Instance 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector2<T>& operator=(const Vector2<T>& Instance) noexcept
	{
		if (this == &Instance) return *this;

		x = Instance.x;
		y = Instance.y;

		return *this;
	}


	/**
	 * @brief 벡터의 대입 연산자 입니다.
	 *
	 * @param Instance 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector2<T>& operator=(Vector2<T>&& Instance) noexcept
	{
		if (this == &Instance) return *this;

		x = Instance.x;
		y = Instance.y;

		return *this;
	}


	/**
	 * @brief 벡터의 원소에 -부호를 취합니다.
	 *
	 * @return 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Vector2<T> operator-() const
	{
		return Vector2<T>(-x, -y);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector2<T> operator+(const Vector2<T>& Instance) const
	{
		return Vector2<T>(x + Instance.x, y + Instance.y);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector2<T> operator+(Vector2<T>&& Instance) const
	{
		return Vector2<T>(x + Instance.x, y + Instance.y);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector2<T> operator-(const Vector2<T>& Instance) const
	{
		return Vector2<T>(x - Instance.x, y - Instance.y);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector2<T> operator-(Vector2<T>&& Instance) const
	{
		return Vector2<T>(x - Instance.x, y - Instance.y);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @param Instance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector2<T> operator*(const Vector2<T>& Instance) const
	{
		return Vector2<T>(x * Instance.x, y * Instance.y);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @param Instance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector2<T> operator*(Vector2<T>&& Instance) const
	{
		return Vector2<T>(x * Instance.x, y * Instance.y);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector2<T>& operator+=(const Vector2<T>& Instance) noexcept
	{
		x += Instance.x;
		y += Instance.y;

		return *this;
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector2<T>& operator+=(Vector2<T>&& Instance) noexcept
	{
		x += Instance.x;
		y += Instance.y;

		return *this;
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector2<T>& operator-=(const Vector2<T>& Instance) noexcept
	{
		x -= Instance.x;
		y -= Instance.y;

		return *this;
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector2<T>& operator-=(Vector2<T>&& Instance) noexcept
	{
		x -= Instance.x;
		y -= Instance.y;

		return *this;
	}


	/**
	 * @brief 두 벡터가 일치하는지 확인합니다.
	 *
	 * @param Instance 일치하는지 확인할 피연산자입니다.
	 *
	 * @return 두 벡터의 원소가 모두 일치하면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(const Vector2<T>& Instance) noexcept
	{
		return (x == Instance.x) && (y == Instance.y);
	}


	/**
	 * @brief 두 벡터가 일치하는지 확인합니다.
	 *
	 * @param Instance 일치하는지 확인할 피연산자입니다.
	 *
	 * @return 두 벡터의 원소가 모두 일치하면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(Vector2<T>&& Instance) noexcept
	{
		return (x == Instance.x) && (y == Instance.y);
	}


	/**
	 * @brief 두 벡터가 일치하지 않는지 확인합니다.
	 *
	 * @param Instance 일치하지 않는지 확인할 피연산자입니다.
	 *
	 * @return 두 벡터의 원소 중 하나라도 일치하지 않으면 true, 모두 일치하면 false를 반환합니다.
	 */
	bool operator!=(const Vector2<T>& Instance) noexcept
	{
		return (x != Instance.x) || (y != Instance.y);
	}


	/**
	 * @brief 두 벡터가 일치하지 않는지 확인합니다.
	 *
	 * @param Instance 일치하지 않는지 확인할 피연산자입니다.
	 *
	 * @return 두 벡터의 원소 중 하나라도 일치하지 않으면 true, 모두 일치하면 false를 반환합니다.
	 */
	bool operator!=(Vector2<T>&& Instance) noexcept
	{
		return (x != Instance.x) || (y != Instance.y);
	}


	/**
	 * @brief 벡터의 첫 번째 원소입니다.
	 */
	T x;


	/**
	 * @brief 벡터의 두 번째 원소입니다.
	 */
	T y;
};


/**
 * @brief 템플릿 기반의 3차원 벡터입니다.
 */
template <typename T>
struct Vector3
{
	/**
	 * @brief 벡터의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Vector3() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
		z = static_cast<T>(0);
	}


	/**
	 * @brief 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 */
	Vector3(T&& xx, T&& yy, T&& zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}


	/**
	 * @brief 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 */
	Vector3(const T& xx, const T& yy, const T& zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}


	/**
	 * @brief 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param Element 모든 원소를 초기화 할 값입니다.
	 */
	Vector3(T&& Element) noexcept
	{
		x = Element;
		y = Element;
		z = Element;
	}


	/**
	 * @brief 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param Element 모든 원소를 초기화 할 값입니다.
	 */
	Vector3(const T& Element) noexcept
	{
		x = Element;
		y = Element;
		z = Element;
	}


	/**
	 * @brief 벡터의 복사 생성자입니다.
	 *
	 * @param Instance 원소를 복사할 벡터의 인스턴스입니다.
	 */
	Vector3(const Vector3<T>& Instance) noexcept
	{
		x = Instance.x;
		y = Instance.y;
		z = Instance.z;
	}


	/**
	 * @brief 벡터의 복사 생성자입니다.
	 *
	 * @param Instance 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	Vector3(Vector3<T>&& Instance) noexcept
	{
		x = Instance.x;
		y = Instance.y;
		z = Instance.z;
	}


	/**
	 * @brief 벡터의 대입 연산자 입니다.
	 *
	 * @param Instance 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
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
	 * @brief 벡터의 대입 연산자 입니다.
	 *
	 * @param Instance 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
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
	 * @brief 벡터의 원소에 -부호를 취합니다.
	 *
	 * @return 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Vector3<T> operator-() const
	{
		return Vector3<T>(-x, -y, -z);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector3<T> operator+(const Vector3<T>& Instance) const
	{
		return Vector3<T>(x + Instance.x, y + Instance.y, z + Instance.z);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector3<T> operator+(Vector3<T>&& Instance) const
	{
		return Vector3<T>(x + Instance.x, y + Instance.y, z + Instance.z);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector3<T> operator-(const Vector3<T>& Instance) const
	{
		return Vector3<T>(x - Instance.x, y - Instance.y, z - Instance.z);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector3<T> operator-(Vector3<T>&& Instance) const
	{
		return Vector3<T>(x - Instance.x, y - Instance.y, z - Instance.z);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @param Instance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector3<T> operator*(const Vector3<T>& Instance) const
	{
		return Vector3<T>(x * Instance.x, y * Instance.y, z * Instance.z);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @param Instance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector3<T> operator*(Vector3<T>&& Instance) const
	{
		return Vector3<T>(x * Instance.x, y * Instance.y, z * Instance.z);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector3<T>& operator+=(const Vector3<T>& Instance) noexcept
	{
		x += Instance.x;
		y += Instance.y;
		z += Instance.z;

		return *this;
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector3<T>& operator+=(Vector3<T>&& Instance) noexcept
	{
		x += Instance.x;
		y += Instance.y;
		z += Instance.z;

		return *this;
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector3<T>& operator-=(const Vector3<T>& Instance) noexcept
	{
		x -= Instance.x;
		y -= Instance.y;
		z -= Instance.z;

		return *this;
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector3<T>& operator-=(Vector3<T>&& Instance) noexcept
	{
		x -= Instance.x;
		y -= Instance.y;
		z -= Instance.z;

		return *this;
	}


	/**
	 * @brief 두 벡터가 일치하는지 확인합니다.
	 *
	 * @param Instance 일치하는지 확인할 피연산자입니다.
	 *
	 * @return 두 벡터의 원소가 모두 일치하면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(const Vector3<T>& Instance) noexcept
	{
		return (x == Instance.x) && (y == Instance.y) && (z == Instance.z);
	}


	/**
	 * @brief 두 벡터가 일치하는지 확인합니다.
	 *
	 * @param Instance 일치하는지 확인할 피연산자입니다.
	 *
	 * @return 두 벡터의 원소가 모두 일치하면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(Vector3<T>&& Instance) noexcept
	{
		return (x == Instance.x) && (y == Instance.y) && (z == Instance.z);
	}


	/**
	 * @brief 두 벡터가 일치하지 않는지 확인합니다.
	 *
	 * @param Instance 일치하지 않는지 확인할 피연산자입니다.
	 *
	 * @return 두 벡터의 원소 중 하나라도 일치하지 않으면 true, 모두 일치하면 false를 반환합니다.
	 */
	bool operator!=(const Vector3<T>& Instance) noexcept
	{
		return (x != Instance.x) || (y != Instance.y) || (z != Instance.z);
	}


	/**
	 * @brief 두 벡터가 일치하지 않는지 확인합니다.
	 *
	 * @param Instance 일치하지 않는지 확인할 피연산자입니다.
	 *
	 * @return 두 벡터의 원소 중 하나라도 일치하지 않으면 true, 모두 일치하면 false를 반환합니다.
	 */
	bool operator!=(Vector3<T>&& Instance) noexcept
	{
		return (x != Instance.x) || (y != Instance.y) || (z != Instance.z);
	}


	/**
	 * @brief 벡터의 첫 번째 원소입니다.
	 */
	T x;


	/**
	 * @brief 벡터의 두 번째 원소입니다.
	 */
	T y;


	/**
	 * @brief 벡터의 세 번째 원소입니다.
	 */
	T z;
};


/**
 * @brief 템플릿 기반의 4차원 벡터입니다.
 */
template <typename T>
struct Vector4
{
	/**
	 * @brief 벡터의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Vector4() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
		z = static_cast<T>(0);
		w = static_cast<T>(0);
	}


	/**
	 * @brief 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 * @param ww 벡터의 w 성분입니다.
	 */
	Vector4(T&& xx, T&& yy, T&& zz, T&& ww)
	{
		x = xx;
		y = yy;
		z = zz;
		w = ww;
	}


	/**
	 * @brief 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 * @param ww 벡터의 w 성분입니다.
	 */
	Vector4(const T& xx, const T& yy, const T& zz, const T& ww)
	{
		x = xx;
		y = yy;
		z = zz;
		w = ww;
	}


	/**
	 * @brief 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param Element 모든 원소를 초기화 할 값입니다.
	 */
	Vector4(T&& Element) noexcept
	{
		x = Element;
		y = Element;
		z = Element;
		w = Element;
	}


	/**
	 * @brief 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param Element 모든 원소를 초기화 할 값입니다.
	 */
	Vector4(const T& Element) noexcept
	{
		x = Element;
		y = Element;
		z = Element;
		w = Element;
	}


	/**
	 * @brief 벡터의 복사 생성자입니다.
	 *
	 * @param Instance 원소를 복사할 벡터의 인스턴스입니다.
	 */
	Vector4(const Vector4<T>& Instance) noexcept
	{
		x = Instance.x;
		y = Instance.y;
		z = Instance.z;
		w = Instance.w;
	}


	/**
	 * @brief 벡터의 복사 생성자입니다.
	 *
	 * @param Instance 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	Vector4(Vector4<T>&& Instance) noexcept
	{
		x = Instance.x;
		y = Instance.y;
		z = Instance.z;
		w = Instance.w;
	}


	/**
	 * @brief 벡터의 대입 연산자 입니다.
	 *
	 * @param Instance 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
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
	 * @brief 벡터의 대입 연산자 입니다.
	 *
	 * @param Instance 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
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
	 * @brief 벡터의 원소에 -부호를 취합니다.
	 *
	 * @return 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Vector4<T> operator-() const
	{
		return Vector4<T>(-x, -y, -z, -w);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector4<T> operator+(const Vector4<T>& Instance) const
	{
		return Vector4<T>(x + Instance.x, y + Instance.y, z + Instance.z, w + Instance.w);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector4<T> operator+(Vector4<T>&& Instance) const
	{
		return Vector4<T>(x + Instance.x, y + Instance.y, z + Instance.z, w + Instance.w);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector4<T> operator-(const Vector4<T>& Instance) const
	{
		return Vector4<T>(x - Instance.x, y - Instance.y, z - Instance.z, w - Instance.w);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector4<T> operator-(Vector4<T>&& Instance) const
	{
		return Vector4<T>(x - Instance.x, y - Instance.y, z - Instance.z, w - Instance.w);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @param Instance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector4<T> operator*(const Vector4<T>& Instance) const
	{
		return Vector4<T>(x * Instance.x, y * Instance.y, z * Instance.z, w * Instance.w);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @param Instance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector4<T> operator*(Vector4<T>&& Instance) const
	{
		return Vector4<T>(x * Instance.x, y * Instance.y, z * Instance.z, w * Instance.w);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
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
	 * @brief 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
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
	 * @brief 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
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
	 * @brief 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
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
	 * @brief 두 벡터가 일치하는지 확인합니다.
	 *
	 * @param Instance 일치하는지 확인할 피연산자입니다.
	 *
	 * @return 두 벡터의 원소가 모두 일치하면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(const Vector4<T>& Instance) noexcept
	{
		return (x == Instance.x) && (y == Instance.y) && (z == Instance.z) && (w == Instance.w);
	}


	/**
	 * @brief 두 벡터가 일치하는지 확인합니다.
	 *
	 * @param Instance 일치하는지 확인할 피연산자입니다.
	 *
	 * @return 두 벡터의 원소가 모두 일치하면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(Vector4<T>&& Instance) noexcept
	{
		return (x == Instance.x) && (y == Instance.y) && (z == Instance.z) && (w == Instance.w);
	}


	/**
	 * @brief 두 벡터가 일치하지 않는지 확인합니다.
	 *
	 * @param Instance 일치하지 않는지 확인할 피연산자입니다.
	 *
	 * @return 두 벡터의 원소 중 하나라도 일치하지 않으면 true, 모두 일치하면 false를 반환합니다.
	 */
	bool operator!=(const Vector4<T>& Instance) noexcept
	{
		return (x != Instance.x) || (y != Instance.y) || (z != Instance.z) || (w != Instance.w);
	}


	/**
	 * @brief 두 벡터가 일치하지 않는지 확인합니다.
	 *
	 * @param Instance 일치하지 않는지 확인할 피연산자입니다.
	 *
	 * @return 두 벡터의 원소 중 하나라도 일치하지 않으면 true, 모두 일치하면 false를 반환합니다.
	 */
	bool operator!=(Vector4<T>&& Instance) noexcept
	{
		return (x != Instance.x) || (y != Instance.y) || (z != Instance.z) || (w != Instance.w);
	}


	/**
	 * @brief 벡터의 첫 번째 원소입니다.
	 */
	T x;


	/**
	 * @brief 벡터의 두 번째 원소입니다.
	 */
	T y;


	/**
	 * @brief 벡터의 세 번째 원소입니다.
	 */
	T z;


	/**
	 * @brief 벡터의 네 번째 원소입니다.
	 */
	T w;
};


/**
 * @brief 템플릿 기반의 2x2 행렬입니다.
 */
template <typename T>
struct Matrix2x2
{
	/**
	 * @brief 행렬의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Matrix2x2() noexcept
	{
		m[0][0] = static_cast<T>(0); m[0][1] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(0);
	}


	/**
	 * @brief 행렬의 생성자입니다.
	 *
	 * @param m00 행렬의 (0, 0) 성분입니다.
	 * @param m01 행렬의 (0, 1) 성분입니다.
	 * @param m10 행렬의 (1, 0) 성분입니다.
	 * @param m11 행렬의 (1, 1) 성분입니다.
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
	 * @brief 행렬의 생성자입니다.
	 *
	 * @param m00 행렬의 (0, 0) 성분입니다.
	 * @param m01 행렬의 (0, 1) 성분입니다.
	 * @param m10 행렬의 (1, 0) 성분입니다.
	 * @param m11 행렬의 (1, 1) 성분입니다.
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
	 * @brief 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param Element 모든 원소를 초기화 할 값입니다.
	 */
	Matrix2x2(T&& Element) noexcept
	{
		m[0][0] = Element; m[0][1] = Element;
		m[1][0] = Element; m[1][1] = Element;
	}


	/**
	 * @brief 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param Element 모든 원소를 초기화 할 값입니다.
	 */
	Matrix2x2(const T& Element) noexcept
	{
		m[0][0] = Element; m[0][1] = Element;
		m[1][0] = Element; m[1][1] = Element;
	}


	/**
	 * @brief 행렬의 복사 생성자입니다.
	 *
	 * @param Instance 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Matrix2x2(Matrix2x2<T>&& Instance) noexcept
	{
		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1];
	}


	/**
	 * @brief 행렬의 복사 생성자입니다.
	 *
	 * @param Instance 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Matrix2x2(const Matrix2x2<T>& Instance) noexcept
	{
		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1];
	}


	/**
	 * @brief 행렬의 대입 연산자입니다.
	 *
	 * @param Instance 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
	 */
	Matrix2x2<T>& operator=(Matrix2x2<T>&& Instance) noexcept
	{
		if (this == &Instance) return *this;

		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1];

		return *this;
	}


	/**
	 * @brief 행렬의 대입 연산자입니다.
	 *
	 * @param Instance 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
	 */
	Matrix2x2<T>& operator=(const Matrix2x2<T>& Instance) noexcept
	{
		if (this == &Instance) return *this;

		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1];

		return *this;
	}


	/**
	 * @brief 행렬의 모든 원소에 - 부호를 취합니다.
	 *
	 * @return 모든 원소에 - 부호를 취한 새로운 행렬을 반환합니다.
	 */
	Matrix2x2<T> operator-() const
	{
		return Matrix2x2<T>(
			-m[0][0], -m[0][1],
			-m[1][0], -m[1][1]
			);
	}


	/**
	 * @brief 두 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param Instance 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Matrix2x2<T> operator+(Matrix2x2<T>&& Instance)
	{
		return Matrix2x2<T>(
			m[0][0] + Instance.m[0][0], m[0][1] + Instance.m[0][1],
			m[1][0] + Instance.m[1][0], m[1][1] + Instance.m[1][1]
			);
	}


	/**
	 * @brief 두 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param Instance 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Matrix2x2<T> operator+(const Matrix2x2<T>& Instance)
	{
		return Matrix2x2<T>(
			m[0][0] + Instance.m[0][0], m[0][1] + Instance.m[0][1],
			m[1][0] + Instance.m[1][0], m[1][1] + Instance.m[1][1]
			);
	}


	/**
	 * @brief 두 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Matrix2x2<T> operator-(Matrix2x2<T>&& Instance)
	{
		return Matrix2x2<T>(
			m[0][0] - Instance.m[0][0], m[0][1] - Instance.m[0][1],
			m[1][0] - Instance.m[1][0], m[1][1] - Instance.m[1][1]
			);
	}


	/**
	 * @brief 두 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Matrix2x2<T> operator-(const Matrix2x2<T>& Instance)
	{
		return Matrix2x2<T>(
			m[0][0] - Instance.m[0][0], m[0][1] - Instance.m[0][1],
			m[1][0] - Instance.m[1][0], m[1][1] - Instance.m[1][1]
			);
	}


	/**
	 * @brief 두 행렬을 곱합니다.
	 *
	 * @param Instance 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
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
	 * @brief 두 행렬을 곱합니다.
	 *
	 * @param Instance 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
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
	 * @brief 두 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix2x2<T>& operator+=(Matrix2x2<T>&& Instance) noexcept
	{
		m[0][0] += Instance.m[0][0]; m[0][1] += Instance.m[0][1];
		m[1][0] += Instance.m[1][0]; m[1][1] += Instance.m[1][1];

		return *this;
	}


	/**
	 * @brief 두 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix2x2<T>& operator+=(const Matrix2x2<T>& Instance) noexcept
	{
		m[0][0] += Instance.m[0][0]; m[0][1] += Instance.m[0][1];
		m[1][0] += Instance.m[1][0]; m[1][1] += Instance.m[1][1];

		return *this;
	}


	/**
	 * @brief 두 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix2x2<T>& operator-=(Matrix2x2<T>&& Instance) noexcept
	{
		m[0][0] -= Instance.m[0][0]; m[0][1] -= Instance.m[0][1];
		m[1][0] -= Instance.m[1][0]; m[1][1] -= Instance.m[1][1];

		return *this;
	}


	/**
	 * @brief 두 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix2x2<T>& operator-=(const Matrix2x2<T>& Instance) noexcept
	{
		m[0][0] -= Instance.m[0][0]; m[0][1] -= Instance.m[0][1];
		m[1][0] -= Instance.m[1][0]; m[1][1] -= Instance.m[1][1];

		return *this;
	}


	/**
	 * @brief 두 행렬의 원소가 일치하는지 확인합니다.
	 *
	 * @param Instance 일치하는지 확인할 행렬입니다.
	 *
	 * @return 두 행렬의 원소가 모두 일치하면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(Matrix2x2<T>&& Instance) noexcept
	{
		return (m[0][0] == Instance.m[0][0])
			&& (m[0][1] == Instance.m[0][1])
			&& (m[1][0] == Instance.m[1][0])
			&& (m[1][1] == Instance.m[1][1]);
	}


	/**
	 * @brief 두 행렬의 원소가 일치하는지 확인합니다.
	 *
	 * @param Instance 일치하는지 확인할 행렬입니다.
	 *
	 * @return 두 행렬의 원소가 모두 일치하면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(const Matrix2x2<T>& Instance) noexcept
	{
		return (m[0][0] == Instance.m[0][0])
			&& (m[0][1] == Instance.m[0][1])
			&& (m[1][0] == Instance.m[1][0])
			&& (m[1][1] == Instance.m[1][1]);
	}


	/**
	 * @brief 두 행렬의 원소가 일치하지 않는지 확인합니다.
	 *
	 * @param 일치하지 않는지 확인할 피 연산자입니다.
	 *
	 * @return 두 행렬의 원소가 일치하지 않으면 true, 일치하면 false를 반환합니다.
	 */
	bool operator!=(Matrix2x2<T>&& Instance) noexcept
	{
		return (m[0][0] != Instance.m[0][0])
			|| (m[0][1] != Instance.m[0][1])
			|| (m[1][0] != Instance.m[1][0])
			|| (m[1][1] != Instance.m[1][1]);
	}


	/**
	 * @brief 두 행렬의 원소가 일치하지 않는지 확인합니다.
	 *
	 * @param 일치하지 않는지 확인할 피 연산자입니다.
	 *
	 * @return 두 행렬의 원소가 일치하지 않으면 true, 일치하면 false를 반환합니다.
	 */
	bool operator!=(const Matrix2x2<T>& Instance) noexcept
	{
		return (m[0][0] != Instance.m[0][0])
			|| (m[0][1] != Instance.m[0][1])
			|| (m[1][0] != Instance.m[1][0])
			|| (m[1][1] != Instance.m[1][1]);
	}


	/**
	 * @brief 행렬을 단위 행렬로 설정합니다.
	 */
	void Identify()
	{
		m[0][0] = static_cast<T>(1); m[0][1] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(1);
	}


	/**
	 * @brief 행렬의 원소입니다.
	 */
	T m[2][2];
};


/**
 * @brief 템플릿 기반의 3x3 행렬입니다.
 */
template <typename T>
struct Matrix3x3
{
	/**
	 * @brief 행렬의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Matrix3x3() noexcept
	{
		m[0][0] = static_cast<T>(0); m[0][1] = static_cast<T>(0); m[0][2] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(0); m[1][2] = static_cast<T>(0);
		m[2][0] = static_cast<T>(0); m[2][1] = static_cast<T>(0); m[2][2] = static_cast<T>(0);
	}


	/**
	 * @brief 행렬의 생성자입니다.
	 *
	 * @param m00 행렬의 (0, 0) 성분입니다.
	 * @param m01 행렬의 (0, 1) 성분입니다.
	 * @param m02 행렬의 (0, 2) 성분입니다.
	 * @param m10 행렬의 (1, 0) 성분입니다.
	 * @param m11 행렬의 (1, 1) 성분입니다.
	 * @param m12 행렬의 (1, 2) 성분입니다.
	 * @param m20 행렬의 (2, 0) 성분입니다.
	 * @param m21 행렬의 (2, 1) 성분입니다.
	 * @param m22 행렬의 (2, 2) 성분입니다.
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
	 * @brief 행렬의 생성자입니다.
	 *
	 * @param m00 행렬의 (0, 0) 성분입니다.
	 * @param m01 행렬의 (0, 1) 성분입니다.
	 * @param m02 행렬의 (0, 2) 성분입니다.
	 * @param m10 행렬의 (1, 0) 성분입니다.
	 * @param m11 행렬의 (1, 1) 성분입니다.
	 * @param m12 행렬의 (1, 2) 성분입니다.
	 * @param m20 행렬의 (2, 0) 성분입니다.
	 * @param m21 행렬의 (2, 1) 성분입니다.
	 * @param m22 행렬의 (2, 2) 성분입니다.
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
	 * @brief 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param Element 모든 원소를 초기화 할 값입니다.
	 */
	Matrix3x3(T&& Element) noexcept
	{
		m[0][0] = Element; m[0][1] = Element; m[0][2] = Element;
		m[1][0] = Element; m[1][1] = Element; m[1][2] = Element;
		m[2][0] = Element; m[2][1] = Element; m[2][2] = Element;
	}


	/**
	 * @brief 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param Element 모든 원소를 초기화 할 값입니다.
	 */
	Matrix3x3(const T& Element) noexcept
	{
		m[0][0] = Element; m[0][1] = Element; m[0][2] = Element;
		m[1][0] = Element; m[1][1] = Element; m[1][2] = Element;
		m[2][0] = Element; m[2][1] = Element; m[2][2] = Element;
	}


	/**
	 * @brief 행렬의 복사 생성자입니다.
	 *
	 * @param Instance 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Matrix3x3(Matrix3x3<T>&& Instance) noexcept
	{
		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1]; m[0][2] = Instance.m[0][2];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1]; m[1][2] = Instance.m[1][2];
		m[2][0] = Instance.m[2][0]; m[2][1] = Instance.m[2][1]; m[2][2] = Instance.m[2][2];
	}


	/**
	 * @brief 행렬의 복사 생성자입니다.
	 *
	 * @param Instance 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Matrix3x3(const Matrix3x3<T>& Instance) noexcept
	{
		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1]; m[0][2] = Instance.m[0][2];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1]; m[1][2] = Instance.m[1][2];
		m[2][0] = Instance.m[2][0]; m[2][1] = Instance.m[2][1]; m[2][2] = Instance.m[2][2];
	}


	/**
	 * @brief 행렬의 대입 연산자입니다.
	 *
	 * @param Instance 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
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
	 * @brief 행렬의 대입 연산자입니다.
	 *
	 * @param Instance 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
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
	 * @brief 행렬의 모든 원소에 - 부호를 취합니다.
	 *
	 * @return 모든 원소에 - 부호를 취한 새로운 행렬을 반환합니다.
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
	 * @brief 두 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param Instance 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
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
	 * @brief 두 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param Instance 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
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
	 * @brief 두 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
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
	 * @brief 두 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
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
	 * @brief 두 행렬을 곱합니다.
	 *
	 * @param Instance 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
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
	 * @brief 두 행렬을 곱합니다.
	 *
	 * @param Instance 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
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
	 * @brief 두 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix3x3<T>& operator+=(Matrix3x3<T>&& Instance) noexcept
	{
		m[0][0] += Instance.m[0][0]; m[0][1] += Instance.m[0][1]; m[0][2] += Instance.m[0][2];
		m[1][0] += Instance.m[1][0]; m[1][1] += Instance.m[1][1]; m[1][2] += Instance.m[1][2];
		m[2][0] += Instance.m[2][0]; m[2][1] += Instance.m[2][1]; m[2][2] += Instance.m[2][2];

		return *this;
	}


	/**
	 * @brief 두 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix3x3<T>& operator+=(const Matrix3x3<T>& Instance) noexcept
	{
		m[0][0] += Instance.m[0][0]; m[0][1] += Instance.m[0][1]; m[0][2] += Instance.m[0][2];
		m[1][0] += Instance.m[1][0]; m[1][1] += Instance.m[1][1]; m[1][2] += Instance.m[1][2];
		m[2][0] += Instance.m[2][0]; m[2][1] += Instance.m[2][1]; m[2][2] += Instance.m[2][2];

		return *this;
	}


	/**
	 * @brief 두 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix3x3<T>& operator-=(Matrix3x3<T>&& Instance) noexcept
	{
		m[0][0] -= Instance.m[0][0]; m[0][1] -= Instance.m[0][1]; m[0][2] -= Instance.m[0][2];
		m[1][0] -= Instance.m[1][0]; m[1][1] -= Instance.m[1][1]; m[1][2] -= Instance.m[1][2];
		m[2][0] -= Instance.m[2][0]; m[2][1] -= Instance.m[2][1]; m[2][2] -= Instance.m[2][2];

		return *this;
	}


	/**
	 * @brief 두 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix3x3<T>& operator-=(const Matrix3x3<T>& Instance) noexcept
	{
		m[0][0] -= Instance.m[0][0]; m[0][1] -= Instance.m[0][1]; m[0][2] -= Instance.m[0][2];
		m[1][0] -= Instance.m[1][0]; m[1][1] -= Instance.m[1][1]; m[1][2] -= Instance.m[1][2];
		m[2][0] -= Instance.m[2][0]; m[2][1] -= Instance.m[2][1]; m[2][2] -= Instance.m[2][2];

		return *this;
	}


	/**
	 * @brief 두 행렬의 원소가 일치하는지 확인합니다.
	 *
	 * @param Instance 일치하는지 확인할 행렬입니다.
	 *
	 * @return 두 행렬의 원소가 모두 일치하면 true, 그렇지 않으면 false를 반환합니다.
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
	 * @brief 두 행렬의 원소가 일치하는지 확인합니다.
	 *
	 * @param Instance 일치하는지 확인할 행렬입니다.
	 *
	 * @return 두 행렬의 원소가 모두 일치하면 true, 그렇지 않으면 false를 반환합니다.
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
	 * @brief 두 행렬의 원소가 일치하지 않는지 확인합니다.
	 *
	 * @param 일치하지 않는지 확인할 피 연산자입니다.
	 *
	 * @return 두 행렬의 원소가 일치하지 않으면 true, 일치하면 false를 반환합니다.
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
	 * @brief 두 행렬의 원소가 일치하지 않는지 확인합니다.
	 *
	 * @param 일치하지 않는지 확인할 피 연산자입니다.
	 *
	 * @return 두 행렬의 원소가 일치하지 않으면 true, 일치하면 false를 반환합니다.
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
	 * @brief 행렬을 단위 행렬로 설정합니다.
	 */
	void Identify()
	{
		m[0][0] = static_cast<T>(1); m[0][1] = static_cast<T>(0); m[0][2] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(1); m[1][2] = static_cast<T>(0);
		m[2][0] = static_cast<T>(0); m[2][1] = static_cast<T>(0); m[2][2] = static_cast<T>(1);
	}


	/**
	 * @brief 행렬의 원소입니다.
	 */
	T m[3][3];
};


/**
 * @brief 템플릿 기반의 4x4 행렬입니다.
 */
template <typename T>
struct Matrix4x4
{
	/**
	 * @brief 행렬의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Matrix4x4() noexcept
	{
		m[0][0] = static_cast<T>(0); m[0][1] = static_cast<T>(0); m[0][2] = static_cast<T>(0); m[0][3] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(0); m[1][2] = static_cast<T>(0); m[1][3] = static_cast<T>(0);
		m[2][0] = static_cast<T>(0); m[2][1] = static_cast<T>(0); m[2][2] = static_cast<T>(0); m[2][3] = static_cast<T>(0);
		m[3][0] = static_cast<T>(0); m[3][1] = static_cast<T>(0); m[3][2] = static_cast<T>(0); m[3][3] = static_cast<T>(0);
	}


	/**
	 * @brief 행렬의 생성자입니다.
	 *
	 * @param m00 행렬의 (0, 0) 성분입니다.
	 * @param m01 행렬의 (0, 1) 성분입니다.
	 * @param m02 행렬의 (0, 2) 성분입니다.
	 * @param m03 행렬의 (0, 3) 성분입니다.
	 * @param m10 행렬의 (1, 0) 성분입니다.
	 * @param m11 행렬의 (1, 1) 성분입니다.
	 * @param m12 행렬의 (1, 2) 성분입니다.
	 * @param m13 행렬의 (1, 3) 성분입니다.
	 * @param m20 행렬의 (2, 0) 성분입니다.
	 * @param m21 행렬의 (2, 1) 성분입니다.
	 * @param m22 행렬의 (2, 2) 성분입니다.
	 * @param m23 행렬의 (2, 3) 성분입니다.
	 * @param m30 행렬의 (3, 0) 성분입니다.
	 * @param m31 행렬의 (3, 1) 성분입니다.
	 * @param m32 행렬의 (3, 2) 성분입니다.
	 * @param m33 행렬의 (3, 3) 성분입니다.
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
	 * @brief 행렬의 생성자입니다.
	 *
	 * @param m00 행렬의 (0, 0) 성분입니다.
	 * @param m01 행렬의 (0, 1) 성분입니다.
	 * @param m02 행렬의 (0, 2) 성분입니다.
	 * @param m03 행렬의 (0, 3) 성분입니다.
	 * @param m10 행렬의 (1, 0) 성분입니다.
	 * @param m11 행렬의 (1, 1) 성분입니다.
	 * @param m12 행렬의 (1, 2) 성분입니다.
	 * @param m13 행렬의 (1, 3) 성분입니다.
	 * @param m20 행렬의 (2, 0) 성분입니다.
	 * @param m21 행렬의 (2, 1) 성분입니다.
	 * @param m22 행렬의 (2, 2) 성분입니다.
	 * @param m23 행렬의 (2, 3) 성분입니다.
	 * @param m30 행렬의 (3, 0) 성분입니다.
	 * @param m31 행렬의 (3, 1) 성분입니다.
	 * @param m32 행렬의 (3, 2) 성분입니다.
	 * @param m33 행렬의 (3, 3) 성분입니다.
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
	 * @brief 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param Element 모든 원소를 초기화 할 값입니다.
	 */
	Matrix4x4(T&& Element) noexcept
	{
		m[0][0] = Element; m[0][1] = Element; m[0][2] = Element; m[0][3] = Element;
		m[1][0] = Element; m[1][1] = Element; m[1][2] = Element; m[1][3] = Element;
		m[2][0] = Element; m[2][1] = Element; m[2][2] = Element; m[2][3] = Element;
		m[3][0] = Element; m[3][1] = Element; m[3][2] = Element; m[3][3] = Element;
	}


	/**
	 * @brief 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param Element 모든 원소를 초기화 할 값입니다.
	 */
	Matrix4x4(const T& Element) noexcept
	{
		m[0][0] = Element; m[0][1] = Element; m[0][2] = Element; m[0][3] = Element;
		m[1][0] = Element; m[1][1] = Element; m[1][2] = Element; m[1][3] = Element;
		m[2][0] = Element; m[2][1] = Element; m[2][2] = Element; m[2][3] = Element;
		m[3][0] = Element; m[3][1] = Element; m[3][2] = Element; m[3][3] = Element;
	}


	/**
	 * @brief 행렬의 복사 생성자입니다.
	 *
	 * @param Instance 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Matrix4x4(Matrix4x4<T>&& Instance) noexcept
	{
		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1]; m[0][2] = Instance.m[0][2]; m[0][3] = Instance.m[0][3];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1]; m[1][2] = Instance.m[1][2]; m[1][3] = Instance.m[1][3];
		m[2][0] = Instance.m[2][0]; m[2][1] = Instance.m[2][1]; m[2][2] = Instance.m[2][2]; m[2][3] = Instance.m[2][3];
		m[3][0] = Instance.m[3][0]; m[3][1] = Instance.m[3][1]; m[3][2] = Instance.m[3][2]; m[3][3] = Instance.m[3][3];
	}


	/**
	 * @brief 행렬의 복사 생성자입니다.
	 *
	 * @param Instance 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Matrix4x4(const Matrix4x4<T>& Instance) noexcept
	{
		m[0][0] = Instance.m[0][0]; m[0][1] = Instance.m[0][1]; m[0][2] = Instance.m[0][2]; m[0][3] = Instance.m[0][3];
		m[1][0] = Instance.m[1][0]; m[1][1] = Instance.m[1][1]; m[1][2] = Instance.m[1][2]; m[1][3] = Instance.m[1][3];
		m[2][0] = Instance.m[2][0]; m[2][1] = Instance.m[2][1]; m[2][2] = Instance.m[2][2]; m[2][3] = Instance.m[2][3];
		m[3][0] = Instance.m[3][0]; m[3][1] = Instance.m[3][1]; m[3][2] = Instance.m[3][2]; m[3][3] = Instance.m[3][3];
	}


	/**
	 * @brief 행렬의 대입 연산자입니다.
	 *
	 * @param Instance 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
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
	 * @brief 행렬의 대입 연산자입니다.
	 *
	 * @param Instance 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
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
	 * @brief 행렬의 모든 원소에 - 부호를 취합니다.
	 *
	 * @return 모든 원소에 - 부호를 취한 새로운 행렬을 반환합니다.
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
	 * @brief 두 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param Instance 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
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
	 * @brief 두 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param Instance 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
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
	 * @brief 두 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
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
	 * @brief 두 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
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
	 * @brief 두 행렬을 곱합니다.
	 *
	 * @param Instance 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
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
	 * @brief 두 행렬을 곱합니다.
	 *
	 * @param Instance 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
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
	 * @brief 두 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
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
	 * @brief 두 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
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
	 * @brief 두 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
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
	 * @brief 두 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param Instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
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
	 * @brief 두 행렬의 원소가 일치하는지 확인합니다.
	 *
	 * @param Instance 일치하는지 확인할 행렬입니다.
	 *
	 * @return 두 행렬의 원소가 모두 일치하면 true, 그렇지 않으면 false를 반환합니다.
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
	 * @brief 두 행렬의 원소가 일치하는지 확인합니다.
	 *
	 * @param Instance 일치하는지 확인할 행렬입니다.
	 *
	 * @return 두 행렬의 원소가 모두 일치하면 true, 그렇지 않으면 false를 반환합니다.
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
	 * @brief 두 행렬의 원소가 일치하지 않는지 확인합니다.
	 *
	 * @param 일치하지 않는지 확인할 피 연산자입니다.
	 *
	 * @return 두 행렬의 원소가 일치하지 않으면 true, 일치하면 false를 반환합니다.
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
	 * @brief 두 행렬의 원소가 일치하지 않는지 확인합니다.
	 *
	 * @param 일치하지 않는지 확인할 피 연산자입니다.
	 *
	 * @return 두 행렬의 원소가 일치하지 않으면 true, 일치하면 false를 반환합니다.
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
	 * @brief 행렬을 단위 행렬로 설정합니다.
	 */
	void Identify()
	{
		m[0][0] = static_cast<T>(1); m[0][1] = static_cast<T>(0); m[0][2] = static_cast<T>(0); m[0][3] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(1); m[1][2] = static_cast<T>(0); m[1][3] = static_cast<T>(0);
		m[2][0] = static_cast<T>(0); m[2][1] = static_cast<T>(0); m[2][2] = static_cast<T>(1); m[2][3] = static_cast<T>(0);
		m[3][0] = static_cast<T>(0); m[3][1] = static_cast<T>(0); m[3][2] = static_cast<T>(0); m[3][3] = static_cast<T>(1);
	}


	/**
	 * @brief 행렬의 원소입니다.
	 */
	T m[4][4];
};


/**
 * @brief int 타입의 2차원 벡터입니다.
 */
using Vec2i = Vector2<int32_t>;


/**
 * @brief float 타입의 2차원 벡터입니다.
 */
using Vec2f = Vector2<float>;


/**
 * @brief int 타입의 3차원 벡터입니다.
 */
using Vec3i = Vector3<int32_t>;


/**
 * @brief float 타입의 3차원 벡터입니다.
 */
using Vec3f = Vector3<float>;


/**
 * @brief int 타입의 4차원 벡터입니다.
 */
using Vec4i = Vector4<int32_t>;


/**
 * @brief float 타입의 4차원 벡터입니다.
 */
using Vec4f = Vector4<float>;


/**
 * @brief int 타입의 2x2 행렬입니다.
 */
using Matrix2x2I = Matrix2x2<int32_t>;


/**
 * @brief float 타입의 2x2 행렬입니다.
 */
using Matrix2x2F = Matrix2x2<float>;


/**
 * @brief int 타입의 3x3 행렬입니다.
 */
using Matrix3x3I = Matrix3x3<int32_t>;


/**
 * @brief float 타입의 3x3 행렬입니다.
 */
using Matrix3x3F = Matrix3x3<float>;


/**
 * @brief int 타입의 4x4 행렬입니다.
 */
using Matrix4x4I = Matrix4x4<int32_t>;


/**
 * @brief float 타입의 4x4 행렬입니다.
 */
using Matrix4x4F = Matrix4x4<float>;


/**
 * @brief 선형 색상을 정의합니다.
 */
using LinearColor = Vec4f;


/**
 * @brief 기본 색상을 정의합니다.
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
 * @brief 기하 도형의 정점을 정의합니다.
 */
namespace Vertex
{
	/**
	 * @brief 위치와 색상을 포함한 정점입니다.
	 */
	struct PositionColor
	{
		Vec3f Position;
		Vec4f Color;
	};


	/**
	 * @brief 위치와 텍스처 위치를 포함한 정점입니다.
	 */
	struct PositionUV
	{
		Vec3f Position;
		Vec2f UV;
	};
}


/**
 * @brief 직교 투영 행렬을 얻습니다.
 * 
 * @note 왼손 좌표계 기준입니다.
 * 
 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/directxmath/nf-directxmath-xmmatrixorthographiclh
 * 
 * @param ViewWidth 가까운 클리핑 평면에 있는 frustum의 너비입니다.
 * @param ViewHeight 가까운 클리핑 평면에 있는 frustum의 높이입니다.
 * @param NearZ 가까운 클리핑 평면까지의 거리입니다.
 * @param FarZ 원거리 클리핑 평면까지의 거리입니다.
 * 
 * @return 왼손 좌표계 기준의 직교 투영 행렬을 반환합니다.
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
 * @brief 2D 평면 상의 원점 중심 회전 행렬을 얻습니다.
 * 
 * @param Angle 라디안 각도 기준의 회전 각입니다.
 * 
 * @return 회전 행렬을 얻습니다.
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
 * @brief 임의의 정수를 생성합니다.
 *
 * @param MinValue 생성할 난수 범위의 최솟값입니다.
 * @param MaxValue 생성할 난수 범위의 최댓값입니다.
 *
 * @return 생성된 임의의 정수를 반환합니다.
 */
inline int32_t GenerateRandomInt(int32_t MinValue, int32_t MaxValue)
{
	std::random_device RandomDevice;
	std::mt19937 Generator(RandomDevice());
	std::uniform_int_distribution<int32_t> Distribution(std::min<int32_t>(MinValue, MaxValue), std::max<int32_t>(MinValue, MaxValue));

	return Distribution(Generator);
}


/**
 * @brief 임의의 실수를 생성합니다.
 *
 * @param MinValue 생성할 난수 범위의 최솟값입니다.
 * @param MaxValue 생성할 난수 범위의 최댓값입니다.
 *
 * @return 생성된 임의의 실수를 반환합니다.
 */
inline float GenerateRandomFloat(float MinValue, float MaxValue)
{
	std::random_device RandomDevice;
	std::mt19937 Generator(RandomDevice());
	std::uniform_real_distribution<float> Distribution(std::min<float>(MinValue, MaxValue), std::max<float>(MinValue, MaxValue));

	return Distribution(Generator);
}
