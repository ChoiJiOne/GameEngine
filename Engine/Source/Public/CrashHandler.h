#pragma once

#include <windows.h>
#include <dbghelp.h>
#include <vector>
#include <string>


/**
 * @brief ���α׷� ���� �� �߻��� ġ������ ������ ó���ϴ� Ŭ�����Դϴ�.
 *
 * @note �� Ŭ������ ��� ��� �Լ��� ������ ������ ���� Ŭ�����Դϴ�.
 *
 * @see https://learn.microsoft.com/ko-kr/windows/win32/debug/about-structured-exception-handling
 */
class CrashHandler
{
public:
	/**
	 * @brief ũ���� ���� ���� ��θ� �����մϴ�.
	 *
	 * @param DumpFilePath ������ ũ���� ���� ������ ����Դϴ�.
	 */
	static void SetDumpFilePath(const std::string& DumpFilePath)
	{
		DumpFilePath_ = DumpFilePath;
	}


	/**
	 * @brief ���� ������ �����մϴ�.
	 *
	 * @param ErrorFile ������ �߻��� ���� �����Դϴ�.
	 * @param ErrorLine ������ �߻��� ���� ���� �ҽ� �ڵ� �����Դϴ�.
	 * @param ErrorMessage ���� �޽����Դϴ�.
	 */
	static void RecordCrashInfo(const std::string& ErrorFile, const int32_t& ErrorLine, const std::string& ErrorMessage)
	{
		ErrorFileName_ = ErrorFile;
		ErrorLine_ = ErrorLine;
		LastErrorMessage_ = ErrorMessage;
	}


	/**
	 * @brief ���ø����̼��� ũ���ø� �����ϸ� ũ���� ������ �����ϰ� �ݽ����� ����մϴ�.
	 *
	 * @param ExceptionPointer ���� ������ ���� ������ ���Դϴ�.
	 */
	static LONG DetectApplicationCrash(EXCEPTION_POINTERS* ExceptionPointer);


	/**
	 * @brief ������ ũ���� ������ �޽��� �ڽ��� ǥ���մϴ�.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/nf-winuser-messageboxa
	 */
	static void ShowCrashMessageBox();


private:
	/**
	 * @brief ũ���� ������ ������� ũ���� ���� ������ �����մϴ�.
	 *
	 * @param ExceptionPointer ���� ������ ���� ������ ���Դϴ�.
	 */
	static void GenerateCrashDumpFile(EXCEPTION_POINTERS* ExceptionPointer);


	/**
	 * @brief ũ���� ������ ������� �ݽ����� ����մϴ�.
	 *
	 * @param ExceptionPointer ���� ������ ���� ������ ���Դϴ�.
	 */
	static void RecordCallStackFromCrash(EXCEPTION_POINTERS* ExceptionPointer);


	/**
	 * @brief ������ �ӽ� Ÿ���� ����ϴ�.
	 *
	 * @see https://learn.microsoft.com/en-us/previous-versions/mt804320(v=vs.85)
	 *
	 * @return �ӽ� Ÿ���� ��Ÿ���� ���� ���� ��ȯ�մϴ�.
	 */
	static DWORD GetMachineType();


private:
	/**
	 * @brief ũ���� ���� ������ ����Դϴ�.
	 */
	static std::string DumpFilePath_;


	/**
	 * @brief ũ���ð� �߻��� ��Ȳ�� �ݽ��� �����Դϴ�.
	 */
	static std::vector<std::string> CallStack_;


	/**
	 * @brief ���� �ֱٿ� ��ϵ� ���� �޽����Դϴ�.
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