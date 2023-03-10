#include "AudioManager.h"

// @third party code - BEGIN
#include <miniaudio/miniaudio.h>
// @third party code - END

void AudioManager::Setup()
{
	if (bIsSetup_) return;

	CHECK((ma_engine_init(nullptr, MiniAudioEngine_) == MA_SUCCESS), "failed to initialize miniaudio engine...");

	bIsSetup_ = true;
}

void AudioManager::Cleanup()
{
	if (!bIsSetup_) return;

	for (auto& Sound : Sounds_)
	{
		ma_sound_uninit(Sound);
	}

	ma_engine_uninit(MiniAudioEngine_);
	MiniAudioEngine_ = nullptr;

	bIsSetup_ = false;
}

AudioManager::~AudioManager()
{
	Cleanup();
}
