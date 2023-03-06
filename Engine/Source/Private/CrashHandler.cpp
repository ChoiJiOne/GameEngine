#include "CrashHandler.h"
#include "GameTimer.h"
#include "TextHelper.hpp"

std::string              CrashHandler::DumpFilePath_;
std::vector<std::string> CrashHandler::CallStack_;
std::string              CrashHandler::LastErrorMessage_;
std::string              CrashHandler::ErrorFileName_;
int32_t                  CrashHandler::ErrorLine_;

LONG CrashHandler::DetectApplicationCrash(EXCEPTION_POINTERS* ExceptionPointer)
{
	GenerateCrashDumpFile(ExceptionPointer);
	RecordCallStackFromCrash(ExceptionPointer);

	return EXCEPTION_EXECUTE_HANDLER;
}

void CrashHandler::ShowCrashMessageBox()
{
#if defined(SHIPPING) // SHIPPING 활성화 시 소스 코드에 대한 정보 표시 비활성화
	std::string ShowCrashMessage = Format(
		"MESSAGE: %s",
		LastErrorMessage_.c_str()
	);
#else
	std::string ShowCrashMessage = TextHelper::Format("FILE: %s\nLINE: %d\nMESSAGE: %s\nCALLSTACK:\n", ErrorFileName_.c_str(), ErrorLine_, LastErrorMessage_.c_str());

	for (const auto& CallStackElement : CallStack_)
	{
		ShowCrashMessage += CallStackElement + "\n";
	}
#endif

	int32_t Successed = MessageBoxA(nullptr, ShowCrashMessage.c_str(), "Crash Application", MB_OK);
	if (!Successed)
	{
#if defined(DEBUG) || defined(_DEBUG)
		OutputDebugStringA("failed to show message box");
#endif
	}
}

void CrashHandler::GenerateCrashDumpFile(EXCEPTION_POINTERS* ExceptionPointer)
{
	SystemTime CurrentSystemTime = GameTimer::GetCurrentSystemTime();

	std::string CrashDumpFilePath = TextHelper::Format(
		"%sWindows-%d-%d-%d-%d-%d-%d.dmp",
		DumpFilePath_.c_str(),
		CurrentSystemTime.Year,
		CurrentSystemTime.Month,
		CurrentSystemTime.Day,
		CurrentSystemTime.Hour,
		CurrentSystemTime.Minute,
		CurrentSystemTime.Second
	);

	HANDLE  FileHandle = CreateFileA(
		CrashDumpFilePath.c_str(),
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		nullptr,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		nullptr
	);

	if (FileHandle != INVALID_HANDLE_VALUE)
	{
		BOOL Successed = TRUE;

		_MINIDUMP_EXCEPTION_INFORMATION Exception;
		Exception.ThreadId = GetCurrentThreadId();
		Exception.ExceptionPointers = ExceptionPointer;
		Exception.ClientPointers = FALSE;

		Successed = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), FileHandle, MiniDumpNormal, &Exception, nullptr, nullptr);
		if (!Successed)
		{
#if defined(DEBUG) || defined(_DEBUG)
			OutputDebugStringA("failed to generate crash dump file");
#endif
		}

		Successed = CloseHandle(FileHandle);
		if (!Successed)
		{
#if defined(DEBUG) || defined(_DEBUG)
			OutputDebugStringA("failed to close crash dump file");
#endif
		}
	}
	else
	{
#if defined(DEBUG) || defined(_DEBUG)
		OutputDebugStringA("failed to generate crash dump file");
#endif
	}
}

void CrashHandler::RecordCallStackFromCrash(EXCEPTION_POINTERS* ExceptionPointer)
{
	HANDLE CurrentProcess = GetCurrentProcess();
	HANDLE CurrentThread = GetCurrentThread();

	if (SymInitialize(CurrentProcess, nullptr, TRUE))
	{
		CONTEXT* CurrentCrashContext = ExceptionPointer->ContextRecord;

		STACKFRAME64 StackFrame = { };
		StackFrame.AddrPC.Offset = CurrentCrashContext->Rip;
		StackFrame.AddrPC.Mode = AddrModeFlat;
		StackFrame.AddrFrame.Offset = CurrentCrashContext->Rbp;
		StackFrame.AddrFrame.Mode = AddrModeFlat;
		StackFrame.AddrStack.Offset = CurrentCrashContext->Rsp;
		StackFrame.AddrStack.Mode = AddrModeFlat;

		std::vector<DWORD64> Addresses;
		DWORD MachineType = GetMachineType();

		while (StackWalk64(MachineType, CurrentProcess, CurrentThread, &StackFrame, CurrentCrashContext, nullptr, SymFunctionTableAccess64, SymGetModuleBase64, nullptr))
		{
			if (StackFrame.AddrFrame.Offset == 0)
			{
				break;
			}
			else
			{
				Addresses.push_back(StackFrame.AddrPC.Offset);
			}
		}

		std::vector<uint8_t> SymbolBuffer(sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR));
		PSYMBOL_INFO Symbol = reinterpret_cast<PSYMBOL_INFO>(&SymbolBuffer[0]);
		Symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
		Symbol->MaxNameLen = MAX_SYM_NAME;

		for (auto& Address : Addresses)
		{
			if (SymFromAddr(CurrentProcess, Address, nullptr, Symbol))
			{
				std::string StackElement = TextHelper::Format("%s-0x%0X", Symbol->Name, Symbol->Address);
				CallStack_.push_back(StackElement);
			}
		}
	}
	else
	{
#if defined(DEBUG) || defined(_DEBUG)
		OutputDebugStringA("failed to initialize current process");
#endif
	}
}

DWORD CrashHandler::GetMachineType()
{
	HMODULE CurrentModule = GetModuleHandle(nullptr);

	PIMAGE_DOS_HEADER DosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(CurrentModule);
	PIMAGE_NT_HEADERS NtHeaders = reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<BYTE*>(CurrentModule) + DosHeader->e_lfanew);

	return static_cast<DWORD>(NtHeaders->FileHeader.Machine);
}