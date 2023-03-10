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
	ma_engine* MiniAudioEngine_ = nullptr;


	/**
	 * @brief 관리 중인 사운드 리소스입니다.
	 */
	std::vector<ma_sound*> Sounds_;


	/**
	 * @brief AudioManager에서 생성한 사운드 리소스 수입니다.
	 */
	int32_t CountSoundResource_ = 0;
};