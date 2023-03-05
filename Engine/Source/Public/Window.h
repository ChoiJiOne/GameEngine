#pragma once

#include "Macro.h"

#include <cstdint>
#include <string>

#include <windows.h>


/**
 * @brief ������ Ŭ������ ������ �Ķ�����Դϴ�.
 * 
 * @note Ÿ��Ʋ�� ���ڿ� ������ UTF-16 �Դϴ�.
 */
struct WindowConstructorParam
{
	std::wstring Title;
	int32_t PositionX;
	int32_t PositionY;
	int32_t Width;
	int32_t Height;
	bool bIsFullScreen; /* Ǯ ��ũ�� ��� Ȱ��ȭ �� Ÿ��Ʋ�� ������ ��Ҵ� ���õ˴ϴ�. */
};


/**
 * @brief ������ â�� ���� �� �����մϴ�.
 */
class Window
{
public:
	/**
	 * @brief ������ â�� ���� �� �����ϴ� Ŭ������ �������Դϴ�.
	 * 
	 * @note Ÿ��Ʋ�� ���ڿ� ������ UTF-16 �Դϴ�.
	 *
	 * @param ConstructorParam ������ Ŭ������ ���� �Ķ�����Դϴ�.
	 *
	 * @throws ������ â ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	explicit Window(const WindowConstructorParam& ConstructorParam);


	/**
	 * @brief ������ â�� ���� �� �����ϴ� Ŭ������ �������Դϴ�.
	 *
	 * @param Title UTF-16 ����� �������� Ÿ��Ʋ�Դϴ�.
	 * @param PositionX ������ ���� ����� X��ǥ�Դϴ�.
	 * @param PositionY ������ ���� ����� Y��ǥ�Դϴ�.
	 * @param Width �������� ���� ũ���Դϴ�.
	 * @param Height �������� ���� ũ���Դϴ�.
	 * @param bIsFullScreen �������� Ǯ ��ũ�� ��� �����Դϴ�. Ȱ��ȭ �Ǿ��ٸ� Ÿ��Ʋ�� ������ ��Ҵ� ���õ˴ϴ�.
	 * 
	 * @throws ������ â ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	explicit Window(
		const std::wstring& Title,
		int32_t PositionX,
		int32_t PositionY,
		int32_t Width,
		int32_t Height,
		bool bIsFullScreen
	);


	/**
	 * @brief ������ â�� ���� �� �����ϴ� Ŭ������ ���� �Ҹ����Դϴ�
	 */
	virtual ~Window();


	/**
	 * @brief ���� �����ڿ� ���� �����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Window);


	/**
	 * @brief ���� �������� ũ�⸦ ����ϴ�.
	 * 
	 * @param Width[out] ���� �������� ���� ũ���Դϴ�.
	 * @param Height[out] ���� �������� ���� ũ���Դϴ�.
	 * 
	 * @throws ������ â�� ũ�⸦ ��� �� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	template <typename T>
	void GetSize(T& Width, T& Height)
	{
		RECT WindowRect = {};
		CHECK(GetClientRect(WindowHandle_, &WindowRect), "failed to get client size");

		Width = static_cast<T>(WindowRect.right - WindowRect.left);
		Height = static_cast<T>(WindowRect.bottom - WindowRect.top);
	}


	/**
	 * @brief ���� ������ ũ�⸦ �����մϴ�.
	 * 
	 * @param Width ������ �������� ���� ũ���Դϴ�.
	 * @param Height ������ �������� ���� ũ���Դϴ�.
	 * 
	 * @throws ������ â�� ũ�⸦ �����ϴ� �� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	template<typename T>
	void SetSize(T Width, T Height)
	{
		RECT Rect = { 0, 0, static_cast<LONG>(Width), static_cast<LONG>(Height) };
		CHECK(AdjustWindowRect(&Rect, WS_OVERLAPPEDWINDOW, false), "failed to adjust window size");
	}


	/**
	 * @brief ������ â�� �ڵ��� ����ϴ�.
	 * 
	 * @return ������ â�� �ڵ� ���� ��ȯ�մϴ�.
	 */
	HWND GetHandle() { return WindowHandle_; }


	/**
	 * @brief ������ â�� Ǯ ��ũ�� ������� Ȯ���մϴ�.
	 * 
	 * @return ������ ���� Ǯ ��ũ�� ����� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsFullScreen() const { return bIsFullScreen_; }


private:
	/**
	 * @brief ������ Ŭ������ ����մϴ�.
	 * 
	 * @param ClassTitle UTF-16 ����� ������ Ŭ������ Ÿ��Ʋ�Դϴ�.
	 * 
	 * @throws ������ Ŭ���� ��Ͽ� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void RegisterWindowClass(const std::wstring& ClassTitle);


private:
	/**
	 * @brief ������ â�� Ǯ ��ũ�� ������� Ȯ���մϴ�.
	 */
	bool bIsFullScreen_ = false;


	/**
	 * @brief ������ â �ڵ鷯�Դϴ�.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/learnwin32/creating-a-window
	 */
	HWND WindowHandle_ = nullptr;
};