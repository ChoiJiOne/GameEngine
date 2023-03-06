#pragma once

#include <cstdint>


/**
 * @brief �ý��� �ð��� ���� ����ü�Դϴ�.
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
 * @brief ���� Ÿ�̸� Ŭ�����Դϴ�.
 *
 * @note Ÿ�̸� Ŭ������ �����ڴ� �ʱ�ȭ�� �������� �����Ƿ� �ݵ�� Start Ȥ�� Reset �޼��带 ȣ���ؾ� �մϴ�.
 */
class GameTimer
{
public:
	/**
	 * @brief Ÿ�̸� Ŭ������ �������Դϴ�.
	 */
	GameTimer();


	/**
	 * @brief Ÿ�̸� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param Instance ������ ��ü�Դϴ�.
	 */
	GameTimer(GameTimer&& Instance) noexcept
		: bIsStop_(Instance.bIsStop_)
		, BaseTime_(Instance.BaseTime_)
		, PausedTime_(Instance.PausedTime_)
		, StopTime_(Instance.StopTime_)
		, PrevTime_(Instance.PrevTime_)
		, CurrTime_(Instance.CurrTime_) {}


	/**
	 * @brief Ÿ�̸� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param Instance ������ ��ü�Դϴ�.
	 */
	GameTimer(const GameTimer& Instance) noexcept
		: bIsStop_(Instance.bIsStop_)
		, BaseTime_(Instance.BaseTime_)
		, PausedTime_(Instance.PausedTime_)
		, StopTime_(Instance.StopTime_)
		, PrevTime_(Instance.PrevTime_)
		, CurrTime_(Instance.CurrTime_) {}


	/**
	 * @brief Ÿ�̸� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~GameTimer() = default;


	/**
	 * @brief Ÿ�̸� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param Instance ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief Ÿ�̸� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param Instance ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief Ÿ�̸��� �� ���� ��Ÿ �ð����� ����ϴ�.
	 *
	 * @return �� ������ ��Ÿ �ð����� ��ȯ�մϴ�.
	 */
	float GetDeltaSeconds() const;


	/**
	 * @brief Ÿ�̸Ӱ� ������ �ð��� ������ ��ü �ʴ��� �ð����� ��ȯ�մϴ�.
	 *
	 * @return Ÿ�̸Ӱ� ���۵� ������ ������ �ð��� ������ ��ü �ð����� ��ȯ�մϴ�.
	 */
	float GetTotalSeconds() const;


	/**
	 * @brief Ÿ�̸��� ��� ���¸� �����մϴ�.
	 */
	void Reset();


	/**
	 * @brief Ÿ�̸Ӹ� �����մϴ�.
	 *
	 * @note Ÿ�̸Ӱ� �����Ǿ� �ִٸ� �߽õ� �������� ���۵˴ϴ�.
	 */
	void Start();


	/**
	 * @brief Ÿ�̸Ӹ� ������ŵ�ϴ�.
	 */
	void Stop();


	/**
	 * @brief Ÿ�̸Ӹ� ������Ʈ�մϴ�.
	 */
	void Tick();


	/**
	 * @brief ���� �ý��� �ð��� ����ϴ�.
	 *
	 * @return ���� �ý��� �ð� ���� ��ȯ�մϴ�.
	 */
	static SystemTime GetCurrentSystemTime();


private:
	/**
	 * @brief ������ Tick ī���� ���� ����ϴ�.
	 *
	 * @return ������ Tick ī���� ���� ����ϴ�.
	 */
	int64_t GetTickCounter();


private:
	/**
	 * @brief Ÿ�̸��� ���� ���θ� Ȯ���մϴ�.
	 */
	bool bIsStop_ = false;


	/**
	 * @brief Ÿ�̸Ӱ� ���۵� �ð��Դϴ�.
	 */
	int64_t BaseTime_ = 0LL;


	/**
	 * @brief Ÿ�̸Ӱ� ������ ������ ���� �ð��� �Դϴ�.
	 */
	int64_t PausedTime_ = 0LL;


	/**
	 * @brief Ÿ�̸Ӱ� ������ �ð��Դϴ�.
	 */
	int64_t StopTime_ = 0LL;


	/**
	 * @brief ������ Tick ȣ�� �ð��Դϴ�.
	 */
	int64_t PrevTime_ = 0LL;


	/**
	 * @brief Tick ȣ�� �ð��Դϴ�.
	 */
	int64_t CurrTime_ = 0LL;


	/**
	 * @brief ���� ī���� ���� �������Դϴ�.
	 */
	double SecondsPerCounter_ = 0.0;
};