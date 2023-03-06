#include "GameTimer.h"
#include "Macro.h"

#include <windows.h>

GameTimer::GameTimer()
{
	int64_t CounterPerSeconds;
	CHECK((QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&CounterPerSeconds))), "failed to query performance frequency");

	SecondsPerCounter_ = 1.0 / static_cast<double>(CounterPerSeconds);
}

float GameTimer::GetDeltaSeconds() const
{
	float DeltaSeconds = 0.0f;

	if (!bIsStop_)
	{
		DeltaSeconds = static_cast<float>(CurrTime_ - PrevTime_) * static_cast<float>(SecondsPerCounter_);
	}

	return DeltaSeconds;
}

float GameTimer::GetTotalSeconds() const
{
	float TotalSeconds = static_cast<float>(SecondsPerCounter_);

	if (bIsStop_)
	{
		TotalSeconds *= static_cast<float>(StopTime_ - PausedTime_ - BaseTime_);
	}
	else
	{
		TotalSeconds *= static_cast<float>(CurrTime_ - PausedTime_ - BaseTime_);
	}

	return TotalSeconds;
}

void GameTimer::Reset()
{
	int64_t Counter = GetTickCounter();

	bIsStop_ = false;
	BaseTime_ = Counter;
	PausedTime_ = 0LL;
	StopTime_ = 0LL;
	PrevTime_ = Counter;
	CurrTime_ = Counter;
}

void GameTimer::Start()
{
	if (bIsStop_)
	{
		int64_t Counter = GetTickCounter();

		PausedTime_ += (Counter - StopTime_);
		PrevTime_ = Counter;
		StopTime_ = 0LL;
		bIsStop_ = false;
	}
}

void GameTimer::Stop()
{
	if (!bIsStop_)
	{
		StopTime_ = GetTickCounter();
		bIsStop_ = true;
	}
}

void GameTimer::Tick()
{
	PrevTime_ = CurrTime_;
	CurrTime_ = GetTickCounter();
}

SystemTime GameTimer::GetCurrentSystemTime()
{
	SYSTEMTIME CurrentSystemTime;
	GetLocalTime(&CurrentSystemTime);

	return SystemTime{
		CurrentSystemTime.wYear,
		CurrentSystemTime.wMonth,
		CurrentSystemTime.wDay,
		CurrentSystemTime.wHour,
		CurrentSystemTime.wMinute,
		CurrentSystemTime.wSecond
	};
}

int64_t GameTimer::GetTickCounter()
{
	int64_t Counter = 0LL;
	CHECK((QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&Counter))), "failed to query performance counter");

	return Counter;
}