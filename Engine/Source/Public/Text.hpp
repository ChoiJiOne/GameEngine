#pragma once

#include "Macro.h"

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <windows.h>


/**
 * @brief ����ȭ�� ���ڿ��� ��ȯ�մϴ�. �� �޼���� snprintf�� ��ü�ϱ� ���� �޼����Դϴ�.
 *
 * @see https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf
 *
 * @param Text ���� ���ڿ��Դϴ�.
 * @param ... Argument �������� ������ �����͸� �����ϴ� �μ��Դϴ�.
 *
 * @return �������� �Ϸ�� ���ڿ��� ��ȯ�մϴ�.
 */
template<typename ... Args>
inline std::string Format(const std::string& Text, Args ... Argument)
{
	size_t Size = static_cast<size_t>(std::snprintf(nullptr, 0, Text.c_str(), Argument ...)) + 1;

	auto Buffer = std::make_unique<char[]>(Size);
	std::snprintf(Buffer.get(), Size, Text.c_str(), Argument ...);

	return std::string(Buffer.get(), Buffer.get() + Size - 1);
}


/**
 * @brief ����ȭ�� ���ڿ��� ��ȯ�մϴ�. �� �޼���� swprintf�� ��ü�ϱ� ���� �޼����Դϴ�.
 *
 * @see https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf
 *
 * @param Text ���� ���ڿ��Դϴ�.
 * @param ... Argument �������� ������ �����͸� �����ϴ� �μ��Դϴ�.
 *
 * @return �������� �Ϸ�� ���ڿ��� ��ȯ�մϴ�.
 */
template<typename ... Args>
inline std::wstring Format(const std::wstring& Text, Args ... Argument)
{
	size_t Size = static_cast<size_t>(std::swprintf(nullptr, 0, Text.c_str(), Argument ...)) + 1;

	auto Buffer = std::make_unique<wchar_t[]>(Size);
	std::swprintf(Buffer.get(), Size, Text.c_str(), Argument ...);

	return std::wstring(Buffer.get(), Buffer.get() + Size - 1);
}

/**
 * @brief ���ڿ��� Ư�� �������� ����� ���ͷ� ����ϴ�.
 *
 * @param Text Ư�� �������� ����� ���ͷ� ���� ���ڿ��Դϴ�.
 * @param Delimiter ���ڿ��� ���� �����Դϴ�.
 *
 * @return �������� ���ڿ��� ���͸� ��ȯ�մϴ�.
 */
inline std::vector<std::string> Split(const std::string& Text, const std::string& Delimiter)
{
	std::string ParseText = Text;
	std::vector<std::string> Tokens;
	std::size_t Position = 0;

	while ((Position = ParseText.find(Delimiter)) != std::string::npos)
	{
		Tokens.push_back(ParseText.substr(0, Position));
		ParseText.erase(0, Position + Delimiter.length());
	}

	Tokens.push_back(ParseText);
	return Tokens;
}


/**
 * @brief ���ڿ��� Ư�� �������� ����� ���ͷ� ����ϴ�.
 *
 * @param Text Ư�� �������� ����� ���ͷ� ���� ���ڿ��Դϴ�.
 * @param Delimiter ���ڿ��� ���� �����Դϴ�.
 *
 * @return �������� ���ڿ��� ���͸� ��ȯ�մϴ�.
 */
inline std::vector<std::wstring> Split(const std::wstring& Text, const std::wstring& Delimiter)
{
	std::wstring ParseText = Text;
	std::vector<std::wstring> Tokens;
	std::size_t Position = 0;

	while ((Position = ParseText.find(Delimiter)) != std::wstring::npos)
	{
		Tokens.push_back(ParseText.substr(0, Position));
		ParseText.erase(0, Position + Delimiter.length());
	}

	Tokens.push_back(ParseText);
	return Tokens;
}


/**
 * @brief UTF-8 ���ڿ��� UTF-16 ���ڿ��� ��ȯ�մϴ�.
 *
 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar
 *
 * @param Text UTF-8 ����� ���ڿ��Դϴ�.
 *
 * @return ��ȯ�� UTF-16 ���ڿ��� ��ȯ�մϴ�.
 */
inline std::wstring Convert(const std::string& Text)
{
	int32_t Size = MultiByteToWideChar(CP_UTF8, 0, &Text[0], static_cast<int32_t>(Text.size()), nullptr, 0);
	CHECK((Size != 0), "failed to convert UTF-8 to UTF-16");

	std::wstring ConvertText(Size, 0);
	CHECK((MultiByteToWideChar(CP_UTF8, 0, &Text[0], static_cast<int32_t>(Text.size()), &ConvertText[0], Size) != 0), "failed to convert UTF-8 to UTF-16");

	return ConvertText;
}


/**
 * @brief UTF-16 ���ڿ��� UTF-8 ���ڿ��� ��ȯ�մϴ�.
 *
 * @see https://learn.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-widechartomultibyte
 *
 * @param Text UTF-16 ����� ���ڿ��Դϴ�.
 *
 * @return ��ȯ�� UTF-8 ���ڿ��� ��ȯ�մϴ�.
 */
inline std::string Convert(const std::wstring& Text)
{
	int32_t Size = WideCharToMultiByte(CP_ACP, 0, &Text[0], static_cast<int32_t>(Text.size()), nullptr, 0, nullptr, nullptr);
	CHECK((Size != 0), "failed to convert UTF-16 to UTF-8");

	std::string ConvertText(Size, 0);
	CHECK((WideCharToMultiByte(CP_UTF8, 0, &Text[0], static_cast<int32_t>(Text.size()), &ConvertText[0], Size, nullptr, nullptr) != 0), "failed to convert UTF-16 to UTF-8");

	return ConvertText;
}