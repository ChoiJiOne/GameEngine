#pragma once

#include <cmath>
#include <cstdint>
#include <algorithm>


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