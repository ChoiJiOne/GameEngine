#pragma once

#include <memory>

#include "Macro.h"

struct ma_engine;
struct ma_sound;


/**
 * @brief 오디오 처리를 수행합니다.
 * 
 * @note 이 클래스는 싱글턴으로 헤더만 추가하면 바로 사용할 수 있습니다.
 */
class AudioManager
{
public:
	/**
	 * @brief 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(AudioManager);


	/**
	 * @brief AudioManager의 인스턴스를 얻습니다.
	 * 
	 * @return AudioManager의 인스턴스 참조자를 반환합니다.
	 */
	static AudioManager& Get()
	{
		static AudioManager Instance;
		return Instance;
	}


	/**
	 * @brief AudioManager를 명시적으로 초기화합니다.
	 * 
	 * @throws 내부 리소스 생성에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void Setup();


	/**
	 * @brief AudioManager의 내부 요소를 명시적으로 정리합니다.
	 */
	void Cleanup();


	/**
	 * @brief 사운드 리소스를 생성합니다.
	 * 
	 * @param ResourcePath 사운드 리소스의 경로입니다.
	 * 
	 * @throws 
	 * 사운드 파일 로딩에 실패하면 C++ 표준 예외를 던집니다.
	 * 사운드 리소스 생성에 실패하면 C++ 표준 예외를 던집니다.
	 * 
	 * @return 생성된 사운드 리소스의 아이디를 반환합니다.
	 */
	int32_t CreateSound(const std::string& ResourcePath);


	/**
	 * @brief 사운드의 크기를 설정합니다.
	 * 
	 * @param SoundID 크기를 설정할 사운드의 아이디입니다.
	 * @param Volume 사운드의 크기입니다. 범위는 0.0 ~ 1.0 입니다.
	 * 
	 * @throws SoundID에 대응하는 사운드 리소스가 없을 경우 C++ 표준 예외를 던집니다.
	 */
	void SetSoundVolume(int32_t SoundID, float Volume);


	/**
	 * @brief 현재 사운드의 크기를 얻습니다.
	 * 
	 * @param SoundID 소리 크기를 얻을 사운드의 아이디입니다.
	 * 
	 * @throws SoundID에 대응하는 사운드 리소스가 없을 경우 C++ 표준 예외를 던집니다.
	 * 
	 * @return 현재 사운드의 크기를 얻습니다.
	 */
	float GetSoundVolume(int32_t SoundID);


	/**
	 * @brief 사운드의 반복 여부를 설정합니다.
	 * 
	 * @param SoundID 반복 여부를 설정할 사운드의 아이디입니다.
	 * @param bIsLoop 사운드 반복 여부입니다.
	 * 
	 * @throws SoundID에 대응하는 사운드 리소스가 없을 경우 C++ 표준 예외를 던집니다.
	 */
	void SetSoundLooping(int32_t SoundID, bool bIsLoop);


	/**
	 * @brief 사운드의 반복 여부를 얻습니다.
	 * 
	 * @param SoundID 반복 여부를 확인할 사운드의 아이디입니다.
	 * 
	 * @throws SoundID에 대응하는 사운드 리소스가 없을 경우 C++ 표준 예외를 던집니다.
	 * 
	 * @return 사운드가 반복한다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool GetSoundLooping(int32_t SoundID);


	/**
	 * @brief 사운드를 플레이합니다.
	 * 
	 * @note 이전에 중지한 적이 있다면 중지한 시점부터 플레이됩니다.
	 * 
	 * @param SoundID 플레이할 사운드의 아이디입니다.
	 * 
	 * @throws SoundID에 대응하는 사운드 리소스가 없을 경우 C++ 표준 예외를 던집니다.
	 */
	void PlaySound(int32_t SoundID);


	/**
	 * @brief 사운드가 플레이중인지 확인합니다.
	 * 
	 * @param SoundID 플레이 중인지 확인할 사운드 아이디입니다.
	 * 
	 * @throws SoundID에 대응하는 사운드 리소스가 없을 경우 C++ 표준 예외를 던집니다.
	 * 
	 * @return 사운드가 플레이 중이라면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsPlayingSound(int32_t SoundID);


	/**
	 * @brief 사운드 플레이가 끝났는지 확인합니다.
	 * 
	 * @param 플레이가 끝났는지 확인할 사운드 아이디입니다.
	 * 
	 * @throws SoundID에 대응하는 사운드 리소스가 없을 경우 C++ 표준 예외를 던집니다.
	 * 
	 * @return 사운드 플레이가 끝났다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsDoneSound(int32_t SoundID);


	/**
	 * @brief 사운드 플레이를 중지합니다.
	 * 
	 * @param SoundID 플레이를 중지할 사운드 아이디입니다.
	 * 
	 * @throws SoundID에 대응하는 사운드 리소스가 없을 경우 C++ 표준 예외를 던집니다.
	 */
	void StopSound(int32_t SoundID);


	/**
	 * @brief 사운드 플레이가 중지 되었는지 확인합니다.
	 *
	 * @param SoundID 플레이가 중지 되었는지 확인할 사운드 아이디입니다.
	 * 
	 * @throws SoundID에 대응하는 사운드 리소스가 없을 경우 C++ 표준 예외를 던집니다.
	 * 
	 * @return 사운드 플레이가 중지 되었다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool IsStoppingSound(int32_t SoundID);


	/**
	 * @brief 사운드를 초기화합니다.
	 * 
	 * @param 초기화할 사운드의 아이디입니다.
	 * 
	 * @throws SoundID에 대응하는 사운드 리소스가 없을 경우 C++ 표준 예외를 던집니다.
	 */
	void ResetSound(int32_t SoundID);


private:
	/**
	 * @brief 그래픽 관련 처리를 수행하는 클래스의 생성자입니다.
	 *
	 * @note 생성자는 아무런 동작도 수행하지 않습니다.
	 */
	AudioManager() = default;


	/**
	 * @brief 그래픽 관련 리소스를 정리하는 가상 소멸자입니다.
	 */
	virtual ~AudioManager();


private:
	/**
	 * @brief AudioManager가 초기화되었는지 확인합니다.
	 */
	bool bIsSetup_ = false;


	/**
	 * @brief 사운드 리소스를 생성할 때 사용할 미니 오디오 엔진입니다.
	 */
	std::unique_ptr<ma_engine> MiniAudioEngine_ = nullptr;


	/**
	 * @brief 관리 중인 사운드 리소스입니다.
	 */
	std::vector<std::unique_ptr<ma_sound>> Sounds_;


	/**
	 * @brief AudioManager에서 생성한 사운드 리소스 수입니다.
	 */
	int32_t CountSoundResource_ = 0;
};