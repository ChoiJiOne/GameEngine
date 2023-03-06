#pragma once

#include <windows.h>
#include <dbghelp.h>
#include <vector>
#include <string>


/**
 * @brief 프로그램 실행 중 발생한 치명적인 오류를 처리하는 클래스입니다.
 *
 * @note 이 클래스는 모든 멤버 함수와 변수가 정적인 정적 클래스입니다.
 *
 * @see https://learn.microsoft.com/ko-kr/windows/win32/debug/about-structured-exception-handling
 */
class CrashHandler
{
public:
	/**
	 * @brief 크래시 덤프 파일 경로를 설정합니다.
	 *
	 * @param DumpFilePath 설정할 크래시 덤프 파일의 경로입니다.
	 */
	static void SetDumpFilePath(const std::string& DumpFilePath)
	{
		DumpFilePath_ = DumpFilePath;
	}


	/**
	 * @brief 에러 정보를 설정합니다.
	 *
	 * @param ErrorFile 에러가 발생한 파일 정보입니다.
	 * @param ErrorLine 에러가 발생한 파일 내의 소스 코드 라인입니다.
	 * @param ErrorMessage 에러 메시지입니다.
	 */
	static void RecordCrashInfo(const std::string& ErrorFile, const int32_t& ErrorLine, const std::string& ErrorMessage)
	{
		ErrorFileName_ = ErrorFile;
		ErrorLine_ = ErrorLine;
		LastErrorMessage_ = ErrorMessage;
	}


	/**
	 * @brief 애플리케이션의 크래시를 감지하면 크래시 덤프를 생성하고 콜스택을 기록합니다.
	 *
	 * @param ExceptionPointer 예외 정보에 대한 포인터 값입니다.
	 */
	static LONG DetectApplicationCrash(EXCEPTION_POINTERS* ExceptionPointer);


	/**
	 * @brief 현재의 크래시 정보를 메시지 박스에 표시합니다.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/nf-winuser-messageboxa
	 */
	static void ShowCrashMessageBox();


private:
	/**
	 * @brief 크래시 정보를 기반으로 크래시 덤프 파일을 생성합니다.
	 *
	 * @param ExceptionPointer 예외 정보에 대한 포인터 값입니다.
	 */
	static void GenerateCrashDumpFile(EXCEPTION_POINTERS* ExceptionPointer);


	/**
	 * @brief 크래시 정보를 기반으로 콜스택을 기록합니다.
	 *
	 * @param ExceptionPointer 예외 정보에 대한 포인터 값입니다.
	 */
	static void RecordCallStackFromCrash(EXCEPTION_POINTERS* ExceptionPointer);


	/**
	 * @brief 현재의 머신 타입을 얻습니다.
	 *
	 * @see https://learn.microsoft.com/en-us/previous-versions/mt804320(v=vs.85)
	 *
	 * @return 머신 타입을 나타내는 정수 값을 반환합니다.
	 */
	static DWORD GetMachineType();


private:
	/**
	 * @brief 크래쉬 덤프 파일의 경로입니다.
	 */
	static std::string DumpFilePath_;


	/**
	 * @brief 크래시가 발생한 상황의 콜스택 정보입니다.
	 */
	static std::vector<std::string> CallStack_;


	/**
	 * @brief 가장 최근에 등록된 에러 메시지입니다.
	 */
	static std::string LastErrorMessage_;


	/**
	 * @brief 에러가 발생한 경로의 파일 이름입니다.
	 */
	static std::string ErrorFileName_;


	/**
	 * @brief 에러가 발생한 경로의 라인 수입니다.
	 */
	static int32_t ErrorLine_;
};