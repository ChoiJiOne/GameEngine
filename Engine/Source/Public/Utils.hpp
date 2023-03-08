#pragma once

#include "Macro.h"

#include <unordered_map>


/**
 * @brief Ű ���� �����ϴ� ���� �����ϴ��� Ȯ���մϴ�.
 *
 * @param Key �浹�ϴ��� Ȯ���� Ű ���Դϴ�.
 * @param KeyValueResource Ű-�� ���� �ڷᱸ���Դϴ�.
 *
 * @return �̹� Ű ���� �����ϴ� ���� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
 */
template<typename TKey, typename TValue>
bool IsExistKey(const TKey& Key, const std::unordered_map<TKey, TValue>& KeyValueResource)
{
	return KeyValueResource.find(Key) != KeyValueResource.end();
}


/**
 * @brief Ű ���� �����ϴ� ���� �����մϴ�.
 *
 * @note Ű ���� �����ϴ� ���� �������� �ʴ´ٸ� �ƹ� ���۵� �������� �ʽ��ϴ�.
 *
 * @param Key ������ �������� Ű ���Դϴ�.
 * @param KeyValueResource ������ Ű-�� ���� �ڷᱸ���Դϴ�.
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
 * @brief ������ �а� ���ۿ� �����մϴ�.
 * 
 * @note ���� ����� ���ڿ��� UTF-8 �Դϴ�.
 * 
 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilea
 * 
 * @param Path ������ ����Դϴ�.
 * @param Buffer[out] ���� ������ ������ �����Դϴ�.
 * 
 * @throws
 * ���� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
 * ���� �б⿡ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
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
 * @brief ������ �а� ���ۿ� �����մϴ�.
 *
 * @note ���� ����� ���ڿ��� UTF-16 �Դϴ�.
 *
 * @param Path ������ ����Դϴ�.
 * @param Buffer[out] ���� ������ ������ �����Դϴ�.
 *
 * @throws
 * ���� �б⿡ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
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