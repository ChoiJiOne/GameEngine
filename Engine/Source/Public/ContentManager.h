#pragma once

#include "Macro.h"

#include <memory>
#include <unordered_map>

class Config;
class Texture2D;
class Font;
class Sound;
struct ma_engine;


/**
 * @brief ����Ʈ�� �ε��ϰ� �����մϴ�.
 * 
 * @note �� Ŭ������ �̱������� ����� �߰��ϸ� �ٷ� ����� �� �ֽ��ϴ�.
 */
class ContentManager
{
public:
	/**
	 * @brief ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(ContentManager);


	/**
	 * @brief ContentManager�� �ν��Ͻ��� ����ϴ�.
	 * 
	 * @return ContentManager�� �ν��Ͻ� �����ڸ� ��ȯ�մϴ�.
	 */
	static ContentManager& Get()
	{
		static ContentManager Instance;
		return Instance;
	}


	/**
	 * @brief �ؽ�ó�� �ε��մϴ�.
	 * 
	 * @note ��θ� �������� �ʰ�, Ȯ���ڸ� ������ �̸��� ���ڷ� �����ؾ� �մϴ�.
	 * 
	 * @param Signature �ؽ�ó�� �����ϱ� ���� �ñ״�ó ���ڿ��Դϴ�.
	 * @param FileName �ؽ�ó ������ �̸��Դϴ�. �̶�, �̸��� Ȯ���ڸ� ������ �̸��Դϴ�.
	 * 
	 * @throws
	 * �ؽ�ó�� �����ϴ� �ñ״�ó ���� �浹�ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * �ùٸ� ��θ� �������� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * �ؽ�ó �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * �ؽ�ó ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return ������ �ؽ�ó ���ҽ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Texture2D& LoadTexture2D(const std::string& Signature, const std::string& FileName);


	/**
	 * @brief ������ �޴����� �����ϴ� �ؽ�ó�� ����ϴ�.
	 * 
	 * @param Signature ������ �޴����� �����ϴ� �ؽ�ó�� �ñ״�ó ���Դϴ�.
	 * 
	 * @throws
	 * �ñ״�ó ���� �����ϴ� �ؽ�ó�� �������� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return �ñ״�ó ���� �����ϴ� �ؽ�ó�� �����ڸ� ��ȯ�մϴ�.
	 */
	Texture2D& GetTexture2D(const std::string& Signature);


	/**
	 * @brief ������ �޴����� �����ϴ� �ؽ�ó�� �����մϴ�.
	 * 
	 * @note �ñ״�ó ���� �����ϴ� �ؽ�ó�� �������� ������ �ƹ� ���۵� �������� �ʽ��ϴ�.
	 * 
	 * @param Signature ������ �޴����� �����ϴ� �ؽ�ó�� �ñ״�ó ���Դϴ�.
	 */
	void RemoveTexture2D(const std::string& Signature);


	/**
	 * @brief Ʈ�� Ÿ�� ��Ʈ�� �ε��մϴ�.
	 * 
	 * @note ��θ� �������� �ʰ�, Ȯ���ڸ� ������ �̸��� ���ڷ� �����ؾ� �մϴ�.
	 * 
	 * @param Signature ��Ʈ�� �����ϱ� ���� �ñ״�ó ���ڿ��Դϴ�.
	 * @param FileName Ʈ�� Ÿ�� ��Ʈ ������ �̸��Դϴ�. �̶�, �̸��� Ȯ���ڸ� ������ �̸��Դϴ�. 
	 * @param BeginCodePoint ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �������Դϴ�.
	 * @param EndCodePoint ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �����Դϴ�.
	 * @param FontSize ��Ʈ�� ũ���Դϴ�.
	 * 
	 * @throws
	 * ��Ʈ�� �����ϴ� �ñ״�ó ���� �浹�ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * �ùٸ� ��θ� �������� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * Ʈ�� Ÿ�� ��Ʈ �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * ��Ʈ ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return ������ ��Ʈ ���ҽ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Font& LoadFont(const std::string& Signature, const std::string& FileName, int32_t BeginCodePoint, int32_t EndCodePoint, float FontSize);


	/**
	 * @brief ������ �޴����� �����ϴ� ��Ʈ�� ����ϴ�.
	 *
	 * @param Signature ������ �޴����� �����ϴ� ��Ʈ�� �ñ״�ó ���Դϴ�.
	 *
	 * @throws
	 * �ñ״�ó ���� �����ϴ� ��Ʈ�� �������� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return �ñ״�ó ���� �����ϴ� ��Ʈ�� �����ڸ� ��ȯ�մϴ�.
	 */
	Font& GetFont(const std::string& Signature);


	/**
	 * @brief ������ �޴����� �����ϴ� ��Ʈ�� �����մϴ�.
	 *
	 * @note �ñ״�ó ���� �����ϴ� ��Ʈ�� �������� ������ �ƹ� ���۵� �������� �ʽ��ϴ�.
	 *
	 * @param Signature ������ �޴����� �����ϴ� ��Ʈ�� �ñ״�ó ���Դϴ�.
	 */
	void RemoveFont(const std::string& Signature);


	/**
	 * @brief ���带 �ε��մϴ�.
	 * 
	 * @note ��θ� �������� �ʰ�, Ȯ���ڸ� ������ �̸��� ���ڷ� �����ؾ� �մϴ�.
	 * 
	 * @param Signature ���带 �����ϱ� ���� �ñ״�ó ���ڿ��Դϴ�.
	 * @param FileName ���� ������ �̸��Դϴ�. �̶�, �̸��� Ȯ���ڸ� ������ �̸��Դϴ�. 
	 * 
	 * @throws
	 * ���带 �����ϴ� �ñ״�ó ���� �浹�ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * �ùٸ� ��θ� �������� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * ���� �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * ���� ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return ������ ���� ���ҽ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Sound& LoadSound(const std::string& Signature, const std::string& FileName);


	/**
	 * @brief ������ �޴����� �����ϴ� ���带 ����ϴ�.
	 *
	 * @param Signature ������ �޴����� �����ϴ� ������ �ñ״�ó ���Դϴ�.
	 *
	 * @throws
	 * �ñ״�ó ���� �����ϴ� ���尡 �������� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return �ñ״�ó ���� �����ϴ� ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Sound& GetSound(const std::string& Signature);


	/**
	 * @brief ������ �޴����� �����ϴ� ���带 �����մϴ�.
	 *
	 * @note �ñ״�ó ���� �����ϴ� ���尡 �������� ������ �ƹ� ���۵� �������� �ʽ��ϴ�.
	 *
	 * @param Signature ������ �޴����� �����ϴ� ������ �ñ״�ó ���Դϴ�.
	 */
	void RemoveSound(const std::string& Signature);


	/**
	 * @brief ���� ������ �ε��մϴ�.
	 * 
	 * @param Signature ���带 �����ϱ� ���� �ñ״�ó ���ڿ��Դϴ�.
	 * @param FileName ���� ������ �̸��Դϴ�. �̶�, �̸��� Ȯ���ڸ� ������ �̸��Դϴ�.
	 * 
	 * @throws
	 * ���� ������Ʈ�� �����ϴ� �ñ״�ó ���� �浹�ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * �ùٸ� ��θ� �������� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * ���� ���� �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return ������ ���� ������Ʈ ���ҽ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Config& LoadConfig(const std::string& Signature, const std::string& FileName);


	/**
	 * @brief ������ �޴����� �����ϴ� ���� ������Ʈ�� ����ϴ�.
	 *
	 * @param Signature ������ �޴����� �����ϴ� ���� ������Ʈ�� �ñ״�ó ���Դϴ�.
	 *
	 * @throws
	 * �ñ״�ó ���� �����ϴ� ���� ������Ʈ�� �������� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return �ñ״�ó ���� �����ϴ� ���� ������Ʈ�� �����ڸ� ��ȯ�մϴ�.
	 */
	Config& GetConfig(const std::string& Signature);


	/**
	 * @brief ������ �޴����� �����ϴ� ���� ������Ʈ�� �����մϴ�.
	 *
	 * @note �ñ״�ó ���� �����ϴ� ���� ������Ʈ�� �������� ������ �ƹ� ���۵� �������� �ʽ��ϴ�.
	 *
	 * @param Signature ������ �޴����� �����ϴ� ���� ������Ʈ�� �ñ״�ó ���Դϴ�.
	 */
	void RemoveConfig(const std::string& Signature);


private:
	/**
	 * @brief �������� �����ϴ� Ŭ������ �������Դϴ�.
	 */
	ContentManager();


	/**
	 * @brief �������� �����ϴ� Ŭ������ ����Ҹ����Դϴ�.
	 */
	virtual ~ContentManager();


private:
	/**
	 * @brief ����� ���ҽ� ������ ���� miniaudio �����Դϴ�.
	 */
	std::unique_ptr<ma_engine> AudioEngine_ = nullptr;


	/**
	 * @brief ��� �������� ����Ǿ� �ִ� ����Դϴ�.
	 */
	std::string ContentPath_;


	/**
	 * @brief ������ �޴����� �����ϴ� �ؽ�ó�Դϴ�.
	 */
	std::unordered_map<std::string, std::unique_ptr<Texture2D>> Textures_;


	/**
	 * @brief ������ �޴����� �����ϴ� ��Ʈ�Դϴ�.
	 */
	std::unordered_map<std::string, std::unique_ptr<Font>> Fonts_;


	/**
	 * @brief ������ �޴����� �����ϴ� �����Դϴ�.
	 */
	std::unordered_map<std::string, std::unique_ptr<Sound>> Sounds_;


	/**
	 * @brief ������ �޴����� �����ϴ� ���� ������Ʈ�Դϴ�.
	 */
	std::unordered_map<std::string, std::unique_ptr<Config>> Configs_;
};