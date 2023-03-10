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


	/**
	 * @brief ���� ���ҽ��� �����մϴ�.
	 * 
	 * @param ResourcePath ���� ���ҽ��� ����Դϴ�.
	 * 
	 * @throws 
	 * ���� ���� �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * ���� ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return ������ ���� ���ҽ��� ���̵� ��ȯ�մϴ�.
	 */
	int32_t CreateSound(const std::string& ResourcePath);


	/**
	 * @brief ������ ũ�⸦ �����մϴ�.
	 * 
	 * @param SoundID ũ�⸦ ������ ������ ���̵��Դϴ�.
	 * @param Volume ������ ũ���Դϴ�. ������ 0.0 ~ 1.0 �Դϴ�.
	 * 
	 * @throws SoundID�� �����ϴ� ���� ���ҽ��� ���� ��� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void SetSoundVolume(int32_t SoundID, float Volume);


	/**
	 * @brief ���� ������ ũ�⸦ ����ϴ�.
	 * 
	 * @param SoundID �Ҹ� ũ�⸦ ���� ������ ���̵��Դϴ�.
	 * 
	 * @throws SoundID�� �����ϴ� ���� ���ҽ��� ���� ��� C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return ���� ������ ũ�⸦ ����ϴ�.
	 */
	float GetSoundVolume(int32_t SoundID);


	/**
	 * @brief ������ �ݺ� ���θ� �����մϴ�.
	 * 
	 * @param SoundID �ݺ� ���θ� ������ ������ ���̵��Դϴ�.
	 * @param bIsLoop ���� �ݺ� �����Դϴ�.
	 * 
	 * @throws SoundID�� �����ϴ� ���� ���ҽ��� ���� ��� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void SetSoundLooping(int32_t SoundID, bool bIsLoop);


	/**
	 * @brief ������ �ݺ� ���θ� ����ϴ�.
	 * 
	 * @param SoundID �ݺ� ���θ� Ȯ���� ������ ���̵��Դϴ�.
	 * 
	 * @throws SoundID�� �����ϴ� ���� ���ҽ��� ���� ��� C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return ���尡 �ݺ��Ѵٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool GetSoundLooping(int32_t SoundID);


	/**
	 * @brief ���带 �÷����մϴ�.
	 * 
	 * @note ������ ������ ���� �ִٸ� ������ �������� �÷��̵˴ϴ�.
	 * 
	 * @param SoundID �÷����� ������ ���̵��Դϴ�.
	 * 
	 * @throws SoundID�� �����ϴ� ���� ���ҽ��� ���� ��� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void PlaySound(int32_t SoundID);


	/**
	 * @brief ���尡 �÷��������� Ȯ���մϴ�.
	 * 
	 * @param SoundID �÷��� ������ Ȯ���� ���� ���̵��Դϴ�.
	 * 
	 * @throws SoundID�� �����ϴ� ���� ���ҽ��� ���� ��� C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return ���尡 �÷��� ���̶�� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsPlayingSound(int32_t SoundID);


	/**
	 * @brief ���� �÷��̰� �������� Ȯ���մϴ�.
	 * 
	 * @param �÷��̰� �������� Ȯ���� ���� ���̵��Դϴ�.
	 * 
	 * @throws SoundID�� �����ϴ� ���� ���ҽ��� ���� ��� C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return ���� �÷��̰� �����ٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsDoneSound(int32_t SoundID);


	/**
	 * @brief ���� �÷��̸� �����մϴ�.
	 * 
	 * @param SoundID �÷��̸� ������ ���� ���̵��Դϴ�.
	 * 
	 * @throws SoundID�� �����ϴ� ���� ���ҽ��� ���� ��� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void StopSound(int32_t SoundID);


	/**
	 * @brief ���� �÷��̰� ���� �Ǿ����� Ȯ���մϴ�.
	 *
	 * @param SoundID �÷��̰� ���� �Ǿ����� Ȯ���� ���� ���̵��Դϴ�.
	 * 
	 * @throws SoundID�� �����ϴ� ���� ���ҽ��� ���� ��� C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return ���� �÷��̰� ���� �Ǿ��ٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsStoppingSound(int32_t SoundID);


	/**
	 * @brief ���带 �ʱ�ȭ�մϴ�.
	 * 
	 * @param �ʱ�ȭ�� ������ ���̵��Դϴ�.
	 * 
	 * @throws SoundID�� �����ϴ� ���� ���ҽ��� ���� ��� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void ResetSound(int32_t SoundID);


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
	std::unique_ptr<ma_engine> MiniAudioEngine_ = nullptr;


	/**
	 * @brief ���� ���� ���� ���ҽ��Դϴ�.
	 */
	std::vector<std::unique_ptr<ma_sound>> Sounds_;


	/**
	 * @brief AudioManager���� ������ ���� ���ҽ� ���Դϴ�.
	 */
	int32_t CountSoundResource_ = 0;
};