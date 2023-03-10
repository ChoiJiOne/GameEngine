#pragma once

#include <memory>

#include "Macro.h"

struct ma_engine;
struct ma_sound;


/**
 * @brief ����� ó���� �����մϴ�.
 * 
 * @note �� Ŭ������ �̱������� ����� �߰��ϸ� �ٷ� ����� �� �ֽ��ϴ�.
 */
class AudioManager
{
public:
	/**
	 * @brief ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(AudioManager);


	/**
	 * @brief AudioManager�� �ν��Ͻ��� ����ϴ�.
	 * 
	 * @return AudioManager�� �ν��Ͻ� �����ڸ� ��ȯ�մϴ�.
	 */
	static AudioManager& Get()
	{
		static AudioManager Instance;
		return Instance;
	}


	/**
	 * @brief AudioManager�� ��������� �ʱ�ȭ�մϴ�.
	 * 
	 * @throws ���� ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void Setup();


	/**
	 * @brief AudioManager�� ���� ��Ҹ� ��������� �����մϴ�.
	 */
	void Cleanup();


private:
	/**
	 * @brief �׷��� ���� ó���� �����ϴ� Ŭ������ �������Դϴ�.
	 *
	 * @note �����ڴ� �ƹ��� ���۵� �������� �ʽ��ϴ�.
	 */
	AudioManager() = default;


	/**
	 * @brief �׷��� ���� ���ҽ��� �����ϴ� ���� �Ҹ����Դϴ�.
	 */
	virtual ~AudioManager();


private:
	/**
	 * @brief AudioManager�� �ʱ�ȭ�Ǿ����� Ȯ���մϴ�.
	 */
	bool bIsSetup_ = false;


	/**
	 * @brief ���� ���ҽ��� ������ �� ����� �̴� ����� �����Դϴ�.
	 */
	ma_engine* MiniAudioEngine_ = nullptr;


	/**
	 * @brief ���� ���� ���� ���ҽ��Դϴ�.
	 */
	std::vector<ma_sound*> Sounds_;


	/**
	 * @brief AudioManager���� ������ ���� ���ҽ� ���Դϴ�.
	 */
	int32_t CountSoundResource_ = 0;
};