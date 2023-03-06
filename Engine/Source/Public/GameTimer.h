#pragma once

#include <cstdint>


/**
 * @brief 시스템 시간에 대한 구조체입니다.
 */
struct SystemTime
{
	int32_t Year;
	int32_t Month;
	int32_t Day;
	int32_t Hour;
	int32_t Minute;
	int32_t Second;
};


/**
 * @brief 게임 타이머 클래스입니다.
 *
 * @note 타이머 클래스의 생성자는 초기화를 수행하지 않으므로 반드시 Start 혹은 Reset 메서드를 호출해야 합니다.
 */
class GameTimer
{
public:
	/**
	 * @brief 타이머 클래스의 생성자입니다.
	 */
	GameTimer();


	/**
	 * @brief 타이머 클래스의 복사 생성자입니다.
	 *
	 * @param Instance 복사할 객체입니다.
	 */
	GameTimer(GameTimer&& Instance) noexcept
		: bIsStop_(Instance.bIsStop_)
		, BaseTime_(Instance.BaseTime_)
		, PausedTime_(Instance.PausedTime_)
		, StopTime_(Instance.StopTime_)
		, PrevTime_(Instance.PrevTime_)
		, CurrTime_(Instance.CurrTime_) {}


	/**
	 * @brief 타이머 클래스의 복사 생성자입니다.
	 *
	 * @param Instance 복사할 객체입니다.
	 */
	GameTimer(const GameTimer& Instance) noexcept
		: bIsStop_(Instance.bIsStop_)
		, BaseTime_(Instance.BaseTime_)
		, PausedTime_(Instance.PausedTime_)
		, StopTime_(Instance.StopTime_)
		, PrevTime_(Instance.PrevTime_)
		, CurrTime_(Instance.CurrTime_) {}


	/**
	 * @brief 타이머 클래스의 가상 소멸자입니다.
	 */
	virtual ~GameTimer() = default;


	/**
	 * @brief 타이머 클래스의 대입 연산자입니다.
	 *
	 * @param Instance 복사할 객체입니다.
	 *
	 * @return 복사한 객체의 참조자를 반환합니다.
	 */
	GameTimer& operator=(GameTimer&& Instance) noexcept
	{
		if (this == &Instance) return *this;

		bIsStop_ = Instance.bIsStop_;
		BaseTime_ = Instance.BaseTime_;
		PausedTime_ = Instance.PausedTime_;
		StopTime_ = Instance.StopTime_;
		PrevTime_ = Instance.PrevTime_;
		CurrTime_ = Instance.CurrTime_;

		return *this;
	}


	/**
	 * @brief 타이머 클래스의 대입 연산자입니다.
	 *
	 * @param Instance 복사할 객체입니다.
	 *
	 * @return 복사한 객체의 참조자를 반환합니다.
	 */
	GameTimer& operator=(const GameTimer& Instance) noexcept
	{
		if (this == &Instance) return *this;

		bIsStop_ = Instance.bIsStop_;
		BaseTime_ = Instance.BaseTime_;
		PausedTime_ = Instance.PausedTime_;
		StopTime_ = Instance.StopTime_;
		PrevTime_ = Instance.PrevTime_;
		CurrTime_ = Instance.CurrTime_;

		return *this;
	}


	/**
	 * @brief 타이머의 초 단위 델타 시간값을 얻습니다.
	 *
	 * @return 초 단위의 델타 시간값을 반환합니다.
	 */
	float GetDeltaSeconds() const;


	/**
	 * @brief 타이머가 중지된 시간을 제외한 전체 초단위 시간값을 반환합니다.
	 *
	 * @return 타이머가 시작된 이후의 중지된 시간을 제외한 전체 시간값을 반환합니다.
	 */
	float GetTotalSeconds() const;


	/**
	 * @brief 타이머의 모든 상태를 리셋합니다.
	 */
	void Reset();


	/**
	 * @brief 타이머를 시작합니다.
	 *
	 * @note 타이머가 중지되어 있다면 중시된 시점부터 시작됩니다.
	 */
	void Start();


	/**
	 * @brief 타이머를 중지시킵니다.
	 */
	void Stop();


	/**
	 * @brief 타이머를 업데이트합니다.
	 */
	void Tick();


	/**
	 * @brief 현재 시스템 시간을 얻습니다.
	 *
	 * @return 현재 시스템 시간 값을 반환합니다.
	 */
	static SystemTime GetCurrentSystemTime();


private:
	/**
	 * @brief 현재의 Tick 카운터 값을 얻습니다.
	 *
	 * @return 현재의 Tick 카운터 값을 얻습니다.
	 */
	int64_t GetTickCounter();


private:
	/**
	 * @brief 타이머의 중지 여부를 확인합니다.
	 */
	bool bIsStop_ = false;


	/**
	 * @brief 타이머가 시작된 시간입니다.
	 */
	int64_t BaseTime_ = 0LL;


	/**
	 * @brief 타이머가 중지된 동안의 누적 시간값 입니다.
	 */
	int64_t PausedTime_ = 0LL;


	/**
	 * @brief 타이머가 중지된 시간입니다.
	 */
	int64_t StopTime_ = 0LL;


	/**
	 * @brief 직전의 Tick 호출 시간입니다.
	 */
	int64_t PrevTime_ = 0LL;


	/**
	 * @brief Tick 호출 시간입니다.
	 */
	int64_t CurrTime_ = 0LL;


	/**
	 * @brief 성능 카운터 빈도의 역수값입니다.
	 */
	double SecondsPerCounter_ = 0.0;
};