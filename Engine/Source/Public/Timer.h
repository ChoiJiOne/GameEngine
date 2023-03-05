#pragma once

#include <cstdint>


/**
 * @brief Ÿ�̸� Ŭ�����Դϴ�.
 * 
 * @note Ÿ�̸� Ŭ������ �����ڴ� �ʱ�ȭ�� �������� �����Ƿ� �ݵ�� Start Ȥ�� Reset �޼��带 ȣ���ؾ� �մϴ�.
 */
class Timer
{
public:
	/**
	 * @brief Ÿ�̸� Ŭ������ �������Դϴ�.
	 */
	Timer();


	/**
	 * @brief Ÿ�̸� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param Instance ������ ��ü�Դϴ�.
	 */
	Timer(Timer&& Instance) noexcept
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
	Timer(const Timer& Instance) noexcept
		: bIsStop_(Instance.bIsStop_)
		, BaseTime_(Instance.BaseTime_)
		, PausedTime_(Instance.PausedTime_)
		, StopTime_(Instance.StopTime_)
		, PrevTime_(Instance.PrevTime_)
		, CurrTime_(Instance.CurrTime_) {}


	/**
	 * @brief Ÿ�̸� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Timer() = default;


	/**
	 * @brief Ÿ�̸� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param Instance ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	Timer& operator=(Timer&& Instance) noexcept
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
	Timer& operator=(const Timer& Instance) noexcept
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
	 * @note �ð� ������ �ʴ����Դϴ�.
	 *
	 * @return �� ������ ��Ÿ �ð����� ��ȯ�մϴ�.
	 */
	float GetDeltaTime() const;


	/**
	 * @brief Ÿ�̸Ӱ� ������ �ð��� ������ ��ü �ð����� ��ȯ�մϴ�.
	 * 
	 * @note �ð� ������ �ʴ����Դϴ�.
	 *
	 * @return Ÿ�̸Ӱ� ���۵� ������ ������ �ð��� ������ ��ü �ð����� ��ȯ�մϴ�.
	 */
	float GetTotalTime() const;


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
	 * @brief Tick ȣ�� �ð��Գ��ϴ�.
	 */
	int64_t CurrTime_ = 0LL;


	/**
	 * @brief ���� ī���� ���� �������Դϴ�.
	 */
	double SecondsPerCounter_ = 0.0;
};