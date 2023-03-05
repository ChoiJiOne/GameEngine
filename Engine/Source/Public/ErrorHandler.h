#pragma once

#include <windows.h>
#include <dbghelp.h>
#include <string>
#include <minidumpapiset.h>


/**
 * @brief ���� ó���� �����ϴ� �ڵ鷯�Դϴ�.
 *
 * @see https://learn.microsoft.com/ko-kr/windows/win32/debug/about-structured-exception-handling
 */
class ErrorHandler
{
public:
	/**
	 * @brief ���� ������ �����մϴ�.
	 *
	 * @param ErrorFile ������ �߻��� ���� �����Դϴ�.
	 * @param ErrorLine ������ �߻��� ���� ���� �ҽ� �ڵ� �����Դϴ�.
	 * @param ErrorMessage ���� �޽����Դϴ�.
	 */
	static void SetErrorInfo(const std::string& ErrorFile, const int32_t& ErrorLine, const std::string& ErrorMessage)
	{
		ErrorFileName_ = ErrorFile;
		ErrorLine_ = ErrorLine;
		LastErrorMessage_ = ErrorMessage;
	}


	/**
	 * @brief ������ �߻��� ���� �̸��� ����ϴ�.
	 *
	 * @return ������ �߻��� ���� �̸��� ��ȯ�մϴ�.
	 */
	static const std::string& GetErrorFileName() { return ErrorFileName_; }


	/**
	 * @brief ������ �߻��� ������ ���� ���� ����ϴ�.
	 *
	 * @return ������ �߻��� ������ ���� ���� ��ȯ�մϴ�.
	 */
	static int32_t GetErrorLine() { return ErrorLine_; }


	/**
	 * @brief ���� �ֱٿ� �߻��� ������ �޽����� ����ϴ�.
	 *
	 * @return ���� �ֱٿ� �߻��� ������ �޽����� ��ȯ�մϴ�.
	 */
	static const std::string& GetLastErrorMessage() { return LastErrorMessage_; }


	/**
	 * @brief ������ ���� ������ ������� ũ���� ���� ������ �����մϴ�.
	 *
	 * @param ExceptionInfo �߻��� ���� ������ ���� ������ ���Դϴ�.
	 *
	 * @return ���ܿ� ���� �ڵ� ���� ��ȯ�մϴ�.
	 */
	static LONG GenerateCrashDump(EXCEPTION_POINTERS* ExceptionInfo);


	/**
	 * @brief ������ ���� ������ �޽��� �ڽ��� ǥ���մϴ�.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/nf-winuser-messageboxa
	 */
	static void ShowErrorMessageBox();


private:
	/**
	 * @brief ���� �ֱ��� ���� �޽����Դϴ�.
	 */
	static std::string LastErrorMessage_;


	/**
	 * @brief ������ �߻��� ����� ���� �̸��Դϴ�.
	 */
	static std::string ErrorFileName_;


	/**
	 * @brief ������ �߻��� ����� ���� ���Դϴ�.
	 */
	static int32_t ErrorLine_;
};