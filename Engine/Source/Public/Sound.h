#pragma once

#include "Macro.h"

#include <memory>

struct ma_engine;
struct ma_sound;


/**
 * @brief �÷��� ������ ���� ���ҽ��Դϴ�.
 */
class Sound
{
public:
	/**
	 * @brief ���� ���ҽ� �������Դϴ�.
	 * 
	 * @param AudioEngine ���� ���ҽ��� ������ �� ����� miniaudio �����Դϴ�.
	 * @param ResourcePath ���� ������ ���� ����Դϴ�.
	 * 
	 * @throws
	 * ���� ���� �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * ���� ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	Sound(ma_engine* AudioEngine, const std::string& ResourcePath);


	/**
	 * @brief ���� ���ҽ� �������� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Sound();


	/**
	 * @brief ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Sound);


	/**
	 * @brief ������ ũ�⸦ �����մϴ�.
	 * 
	 * @param Volume ������ ũ���Դϴ�. ������ 0.0 ~ 1.0 �Դϴ�.
	 */
	void SetVolume(float Volume);


	/**
	 * @brief ���� ������ ũ�⸦ ����ϴ�.
	 * 
	 * @return ���� ������ ũ�⸦ ����ϴ�.
	 */
	float GetVolume();


	/**
	 * @brief ������ �ݺ� ���θ� �����մϴ�.
	 * 
	 * @param bIsLoop ���� �ݺ� �����Դϴ�.
	 */
	void SetLooping(bool bIsLoop);


	/**
	 * @brief ������ �ݺ� ���θ� ����ϴ�.
	 * 
	 * @return ���尡 �ݺ��Ѵٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool GetLooping();


	/**
	 * @brief ���带 �÷����մϴ�. 
	 * 
	 * @note ������ ������ ���� �ִٸ� ������ �������� �÷��̵˴ϴ�.
	 */
	void Play();


	/**
	 * @brief ���尡 �÷��������� Ȯ���մϴ�.
	 * 
	 * @return ���尡 �÷��� ���̶�� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsPlaying();


	/**
	 * @brief ���� �÷��̰� �������� Ȯ���մϴ�.
	 * 
	 * @return ���� �÷��̰� �����ٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsDone();


	/**
	 * @brief ���� �÷��̸� �����մϴ�.
	 */
	void Stop();


	/**
	 * @brief ���� �÷��̰� ���� �Ǿ����� Ȯ���մϴ�.
	 * 
	 * @return ���� �÷��̰� ���� �Ǿ��ٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsStopping();


	/**
	 * @brief ���带 �ʱ�ȭ�մϴ�.
	 */
	void Reset();


private:
	/**
	 * @brief miniaudio ���� ���ҽ��� �����͸� ����ϴ�.
	 * 
	 * @return miniaudio ���� ���ҽ��� �����͸� ��ȯ�մϴ�.
	 */
	ma_sound* GetSoundPrt() { return Sound_.get(); }


private:
	/**
	 * @brief miniaudio ���� ���ҽ��Դϴ�.
	 */
	std::unique_ptr<ma_sound> Sound_ = nullptr;
};