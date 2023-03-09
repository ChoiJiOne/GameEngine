#pragma once

#include "Macro.h"
#include "Math.hpp"

#include <vector>
#include <string>
#include <memory>
#include <d3d11.h>


/**
 * @brief �ؽ�ó ��Ʋ�󽺿� ǥ�õ� ���� �����Դϴ�.
 */
struct Glyph
{
	int32_t CodePoint;
	Vec2i Position0;
	Vec2i Position1;
	float XOffset;
	float YOffset;
	float XOffset2;
	float YOffset2;
	float XAdvance;
};


/**
 * @brief Ʈ�� Ÿ�� ��Ʈ�� �����ϴ� ���ڵ��� �ؽ�ó ��Ʋ���Դϴ�.
 */
class TTFont
{
public:
	/**
	 * @brief Ʈ�� Ÿ�� ��Ʈ�� �ε��ϰ� �ؽ�Ʈ �ؽ�ó ��Ʋ�󽺸� �����ϴ� ��Ʈ�� �������Դϴ�.
	 * 
	 * @param Device �ؽ�ó ��Ʋ�󽺸� �����ϴ� �� ����� ����̽��Դϴ�.
	 * @param ResourcePath Ʈ�� Ÿ�� ��Ʈ ������ ����Դϴ�.
	 * @param BeginCodePoint ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �������Դϴ�.
	 * @param EndCodePoint ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �����Դϴ�.
	 * @param FontSize ��Ʈ�� ũ���Դϴ�.
	 * 
	 * @throws 
	 * Ʈ�� Ÿ�� ��Ʈ �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * �ؽ�ó ��Ʋ�� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	TTFont(ID3D11Device* Device, const std::string& ResourcePath, int32_t BeginCodePoint, int32_t EndCodePoint, float FontSize);


	/**
	 * @brief ��Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~TTFont();


	/**
	 * @brief ���� �����ڿ� ���� �����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(TTFont);


	/**
	 * @brief �ؽ�ó ��Ʋ�� �����͸� ����ϴ�.
	 * 
	 * @return 2D �ؽ�ó ��Ʋ�� �����͸� ����ϴ�.
	 */
	ID3D11Texture2D* GetTextureAtlas() { return TextureAtlas_; }


	/**
	 * @brief ���̴��� ���ε� �� �ؽ�ó ��Ʋ�� ���ҽ� �並 ����ϴ�.
	 * 
	 * @return ���̴��� ���ε� �� �ؽ�ó ��Ʋ�� ���ҽ� �並 ��ȯ�մϴ�.
	 */
	ID3D11ShaderResourceView* GetTextureAtlasView() { return TextureAtlasView_; }


	/**
	 * @brief �ڵ� ����Ʈ�� �����ϴ� ���� ��ġ �� ũ�� ������ ����ϴ�.
	 *
	 * @param CodePoint ��ġ �� ������ �˰� ���� �ڵ� ����Ʈ ���Դϴ�.
	 *
	 * @throws �ڵ� ����Ʈ ���� ���� ���� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return �ڵ� ����Ʈ�� �����ϴ� ������ ��ġ �� ũ�� ������ ��ȯ�մϴ�.
	 */
	const Glyph& GetGlyph(int32_t CodePoint) const;


	/**
	 * @brief �ؽ�ó ��Ʋ���� ũ�⸦ ����ϴ�.
	 * 
	 * @return �ؽ�ó ��Ʋ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	int32_t GetAtlasSize() const { return AtlasSize_; }


	/**
	 * @brief �ڵ� ����Ʈ�� ���� ���� ���ԵǴ��� Ȯ���մϴ�.
	 *
	 * @param CodePoint ���� �˻縦 ������ �ڵ� ����Ʈ ���Դϴ�.
	 *
	 * @return ���� ���� �ִٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool HasCodePointInRange(int32_t CodePoint) const;


	/**
	 * @brief �ؽ�Ʈ�� ũ�⸦ �����մϴ�.
	 * 
	 * @note ���� ������ �ȼ� �����Դϴ�.
	 *
	 * @param Text ������ �ؽ�Ʈ�Դϴ�.
	 * @param Width[out] ������ �ؽ�Ʈ�� ���� ũ���Դϴ�.
	 * @param Height[out] ������ �ؽ�Ʈ�� ���� ũ���Դϴ�.
	 */
	template <typename T>
	void MeasureText(const std::wstring& Text, T& Width, T& Height) const
	{
		int32_t TextHeight = -1;
		int32_t TextWidth = 0;

		for (const auto& Unicode : Text)
		{
			const Glyph& UnicodeInfo = GetGlyph(static_cast<int32_t>(Unicode));

			int32_t CurrWidth = static_cast<int32_t>(UnicodeInfo.XAdvance);
			int32_t CurrHeight = UnicodeInfo.Position1.y - UnicodeInfo.Position0.y;

			TextWidth += CurrWidth;

			if (CurrHeight > TextHeight)
			{
				TextHeight = CurrHeight;
			}
		}

		Width = static_cast<T>(TextWidth);
		Height = static_cast<T>(TextHeight);
	}


private:
	/**
	 * @brief �ؽ�ó ��Ʋ�� ��Ʈ���� �����մϴ�.
	 * 
	 * @note �ؽ�ó ��Ʋ���� ���� ���� ũ��� �����ϴ�.
	 *
	 * @param Buffer Ʈ�� Ÿ�� ��Ʈ ���ҽ� �����Դϴ�.
	 * @param BeginCodePoint ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �������Դϴ�.
	 * @param EndCodePoint ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �����Դϴ�.
	 * @param FontSize ��Ʈ�� ũ���Դϴ�.
	 * @param Glyphs[out] �ؽ�ó ��Ʋ�� ���� �ڵ� ����Ʈ�� �����ϴ� ���� ��ġ �� ũ�� �����Դϴ�.
	 * @param AtlasSize[out] �ؽ�ó ��Ʋ�� ũ���Դϴ�.
	 *
	 * @return ������ �ؽ�ó ��Ʋ�� ��Ʈ���� ��ȯ�մϴ�.
	 */
	std::shared_ptr<uint8_t[]> GenerateTextureAtlasBitmap(
		const std::vector<uint8_t>& Buffer,
		int32_t BeginCodePoint,
		int32_t EndCodePoint,
		float FontSize,
		std::vector<Glyph>& Glyphs,
		int32_t& AtlasSize
	);


	/**
	 * @brief �ؽ�ó ��Ʋ�� ��Ʈ������ ���� �ؽ�ó ���ҽ��� �����մϴ�.
	 *
	 * @param Device �ؽ�ó ���ҽ��� ������ �� ����� ����̽��Դϴ�.
	 * @param Bitmap �ؽ�ó ��Ʋ�� ��Ʈ���Դϴ�.
	 * @param AtlasSize �ؽ�ó ��Ʋ�� ��Ʈ���� ���� ���� ũ���Դϴ�
	 *
	 * @throws �ؽ�ó ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return �ؽ�ó ��Ʋ�� ���� ����� ��ȯ�մϴ�. ������ �����ϸ� S_OK, �׷��� �ʴٸ� �� ���� ���� ��ȯ�մϴ�.
	 */
	HRESULT CreateTextureAtlasFromBitmap(
		ID3D11Device* Device,
		const std::shared_ptr<uint8_t[]>& Bitmap,
		const int32_t& AtlasSize
	);


private:
	/**
	 * @brief ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �������Դϴ�.
	 * 
	 * @note �ؽ�ó ��Ʋ�󽺴� �������� �����մϴ�.
	 */
	int32_t BeginCodePoint_ = 0;


	/**
	 * @brief ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �����Դϴ�.
	 * 
	 * @note �ؽ�ó ��Ʋ�󽺴� ������ �����մϴ�.
	 */
	int32_t EndCodePoint_ = 0;


	/**
	 * @brief �ؽ�ó ��Ʋ���� ũ���Դϴ�.
	 */
	int32_t AtlasSize_ = 0;


	/**
	 * @brief �ؽ�ó ��Ʋ�� ���� �ڵ� ����Ʈ�� �����ϴ� ���� ��ġ �� ũ�� �����Դϴ�.
	 */
	std::vector<Glyph> Glyphs_;


	/**
	 * @brief �ؽ�Ʈ �ؽ�ó ��Ʋ���Դϴ�.
	 */
	ID3D11Texture2D* TextureAtlas_ = nullptr;


	/**
	 * @brief �ؽ�Ʈ �ؽ�ó ��Ʋ�� ���ҽ� ���Դϴ�.
	 */
	ID3D11ShaderResourceView* TextureAtlasView_ = nullptr;
};