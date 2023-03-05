#pragma once

#include <cmath>
#include <cstdint>
#include <algorithm>


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