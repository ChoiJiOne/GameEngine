#pragma once

#include "Macro.h"

#include <unordered_map>


/**
 * @brief 키 값에 대응하는 값이 존재하는지 확인합니다.
 *
 * @param Key 충돌하는지 확인할 키 값입니다.
 * @param KeyValueResource 키-값 쌍의 자료구조입니다.
 *
 * @return 이미 키 값에 대응하는 값이 존재하면 true, 그렇지 않으면 false를 반환합니다.
 */
template<typename TKey, typename TValue>
bool IsExistKey(const TKey& Key, const std::unordered_map<TKey, TValue>& KeyValueResource)
{
	return KeyValueResource.find(Key) != KeyValueResource.end();
}


/**
 * @brief 키 값에 대응하는 값을 삭제합니다.
 *
 * @note 키 값에 대응하는 값이 존재하지 않는다면 아무 동작도 수행하지 않습니다.
 *
 * @param Key 삭제할 데이터의 키 값입니다.
 * @param KeyValueResource 삭제할 키-값 쌍의 자료구조입니다.
 */
template <typename TKey, typename TValue>
void RemoveValue(const TKey& Key, std::unordered_map<TKey, TValue>& KeyValueResource)
{
	if (IsExistKey<TKey, TValue>(Key, KeyValueResource))
	{
		KeyValueResource.erase(Key);
	}
}


/**
 * @brief 파일을 읽고 버퍼에 저장합니다.
 * 
 * @note 파일 경로의 문자열은 UTF-8 입니다.
 * 
 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilea
 * 
 * @param Path 파일의 경로입니다.
 * @param Buffer[out] 읽은 파일을 저장할 버퍼입니다.
 * 
 * @throws
 * 파일 생성에 실패하면 C++ 표준 예외를 던집니다.
 * 파일 읽기에 실패하면 C++ 표준 예외를 던집니다.
 */
inline void ReadBufferFromFile(const std::string& Path, std::vector<uint8_t>& Buffer)
{
	HANDLE FileHandle = CreateFileA(Path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
	CHECK((FileHandle != INVALID_HANDLE_VALUE), "failed to create file");

	DWORD FileSize = GetFileSize(FileHandle, nullptr);

	Buffer.resize(FileSize);
	DWORD BytesRead;

	CHECK(ReadFile(FileHandle, &Buffer[0], FileSize, &BytesRead, nullptr), "failed read file");
	CHECK(CloseHandle(FileHandle), "failed to close file");
}


/**
 * @brief 파일을 읽고 버퍼에 저장합니다.
 *
 * @note 파일 경로의 문자열은 UTF-16 입니다.
 *
 * @param Path 파일의 경로입니다.
 * @param Buffer[out] 읽은 파일을 저장할 버퍼입니다.
 *
 * @throws
 * 파일 읽기에 실패하면 C++ 표준 예외를 던집니다.
 */
inline void ReadBufferFromFile(const std::wstring& Path, std::vector<uint8_t>& Buffer)
{
	HANDLE FileHandle = CreateFileW(Path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
	CHECK((FileHandle != INVALID_HANDLE_VALUE), "failed to create file");

	DWORD FileSize = GetFileSize(FileHandle, nullptr);

	Buffer.resize(FileSize);
	DWORD BytesRead;

	CHECK(ReadFile(FileHandle, &Buffer[0], FileSize, &BytesRead, nullptr), "failed read file");
	CHECK(CloseHandle(FileHandle), "failed to close file");
}