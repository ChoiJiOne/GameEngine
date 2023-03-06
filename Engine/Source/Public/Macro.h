#pragma once

#include "CrashHandler.h"


/**
 * @brief Ŭ������ ���� ������ �� ���� �����ڸ� ������� ���ϵ��� �����մϴ�.
 *
 * @note �� ��ũ�θ� ������� �ʴ� Ŭ������ �ݵ�� ��������� ���� �����ڿ� ���� �����ڸ� �����ؾ� �մϴ�.
 *
 * @param CLASS - ���� ������ �� ���� �����ڸ� ������ Ŭ�����Դϴ�.
 */
#ifndef DISALLOW_COPY_AND_ASSIGN
#define DISALLOW_COPY_AND_ASSIGN(CLASS)\
CLASS(CLASS&&) = delete;\
CLASS(const CLASS&) = delete;\
CLASS& operator=(CLASS&&) = delete;\
CLASS& operator=(const CLASS&) = delete;
#endif


/**
 * @brief COM ���ҽ��� �Ҵ� �����մϴ�.
 *
 * @param X �Ҵ� ������ COM ���ҽ��Դϴ�.
 */
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(X)\
{\
	if(X)\
	{\
		X->Release();\
		X = nullptr;\
	}\
}
#endif


/**
 * @brief �򰡽��� �˻��ϰ� �������� �򰡵Ǹ� C++ ǥ�� ���ܸ� �����ϴ�.
 *
 * @param EXPRESSION �˻��� �򰡽��Դϴ�.
 * @param MESSAGE �򰡽��� �������� �򰡵� ����� �޽����Դϴ�.
 *
 * @throws �򰡽��� �������� �򰡵� ���, C++ ǥ�� ���ܸ� ������ ũ���� ������ �����մϴ�.
 */
#ifndef CHECK
#define CHECK(EXPRESSION, MESSAGE)\
{\
	if(!EXPRESSION)\
	{\
		CrashHandler::RecordCrashInfo(__FILE__, __LINE__, MESSAGE);\
		throw std::exception();\
	}\
}
#endif


/**
 * @brief HRESULT ���� �˻��ϰ� �������� ���ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
 *
 * @param EXPRESSION �˻��� HRESULT ���Դϴ�.
 * @param MESSAGE �򰡽��� �������� �򰡵� ����� �޽����Դϴ�.
 *
 * @throws HRESULT ���� �������� �򰡵��� ���ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
 */
#ifndef CHECK_HR
#define CHECK_HR(EXPRESSION, MESSAGE)\
{\
	if(((HRESULT)(EXPRESSION)) < 0)\
	{\
		CrashHandler::RecordCrashInfo(__FILE__, __LINE__, MESSAGE);\
		throw std::exception();\
	}\
}
#endif


/**
 * @brief ������ C++ ǥ�� ���ܸ� �����ϴ�.
 * 
 * @param MESSAGE ���ܰ� �߻����� ���� �޽����Դϴ�.
 *
 * @throws C++ ǥ�� ���ܸ� �����ϴ�.
 */
#ifndef ENFORCE_THROW_EXCEPTION
#define ENFORCE_THROW_EXCEPTION(MESSAGE)\
{\
	CrashHandler::RecordCrashInfo(__FILE__, __LINE__, MESSAGE);\
	throw std::exception();\
}
#endif