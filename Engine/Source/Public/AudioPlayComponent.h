#pragma once

#include "AudioComponent.h"


/**
 * @brief ������� �÷����ϴ� ������Ʈ�Դϴ�.
 */
class AudioPlayComponent : public AudioComponent
{
public:
	/**
	 * @brief ���� ������Ʈ�� ������ ����� �÷��� ������Ʈ ������ �Դϴ�.
	 * 
	 * @param Object �� ������Ʈ�� ������ ������Ʈ�� ������ ���Դϴ�.
	 * @param AudioSignature �÷����� ������� �ñ״�ó ���Դϴ�.
	 */
	AudioPlayComponent(GameObject* Object, const std::string& AudioSignature);


	/**
	 * @brief ���� ������Ʈ�� ������ ����� �÷��� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~AudioPlayComponent() {}


	/**
	 * @brief ������Ʈ�� ���� ������ �� ���� �����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(AudioPlayComponent);


	/**
	 * @brief ����� �÷��� ������Ʈ�� ������Ʈ�մϴ�.
	 */
	virtual void Tick();


	/**
	 * @brief ������� ũ�⸦ �����մϴ�.
	 *
	 * @param Volume ������� ũ���Դϴ�. ������ 0.0 ~ 1.0 �Դϴ�.
	 */
	void SetVolume(float Volume);


	/**
	 * @brief ���� ������� ũ�⸦ ����ϴ�.
	 *
	 * @return ���� ������� ũ�⸦ ����ϴ�.
	 */
	float GetVolume();


	/**
	 * @brief ������� �ݺ� ���θ� �����մϴ�.
	 *
	 * @param bIsLoop ���� �ݺ� �����Դϴ�.
	 */
	void SetLooping(bool bIsLoop);


	/**
	 * @brief ������� �ݺ� ���θ� ����ϴ�.
	 *
	 * @return ���尡 �ݺ��Ѵٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool GetLooping();


	/**
	 * @brief ������� �÷����մϴ�.
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
	 * @brief ������� �ʱ�ȭ�մϴ�.
	 */
	void Reset();


private:
	/**
	 * @brief ����� ���ҽ��� �ñ״�ó ���Դϴ�.
	 */
	std::string AudioSignature_;
};