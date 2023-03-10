#include "AudioManager.h"

#include <algorithm>

// @third party code - BEGIN
#include <miniaudio/miniaudio.h>
// @third party code - END

void AudioManager::Setup()
{
	if (bIsSetup_) return;

	CHECK((ma_engine_init(nullptr, MiniAudioEngine_) == MA_SUCCESS), "failed to initialize miniaudio engine...");
	Sounds_.resize(0);

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

int32_t AudioManager::CreateSound(const std::string& ResourcePath)
{
	ma_sound* Sound = nullptr;

	CHECK((ma_sound_init_from_file(MiniAudioEngine_, ResourcePath.c_str(), 0, nullptr, nullptr, Sound) == MA_SUCCESS), "failed to cretae sound resource...");
	Sounds_.push_back(Sound);

	return CountSoundResource_++;
}

void AudioManager::SetSoundVolume(int32_t SoundID, float Volume)
{
	CHECK((0 <= SoundID && SoundID < Sounds_.size()), "out of range sound id...");

	Volume = std::clamp<float>(Volume, 0.0f, 1.0f);
	ma_sound_set_volume(Sounds_[SoundID], Volume);
}

float AudioManager::GetSoundVolume(int32_t SoundID)
{
	CHECK((0 <= SoundID && SoundID < Sounds_.size()), "out of range sound id...");

	return ma_sound_get_volume(Sounds_[SoundID]);
}

void AudioManager::SetSoundLooping(int32_t SoundID, bool bIsLoop)
{
	CHECK((0 <= SoundID && SoundID < Sounds_.size()), "out of range sound id...");

	ma_sound_set_looping(Sounds_[SoundID], static_cast<ma_bool32>(bIsLoop));
}

bool AudioManager::GetSoundLooping(int32_t SoundID)
{
	CHECK((0 <= SoundID && SoundID < Sounds_.size()), "out of range sound id...");

	return ma_sound_is_looping(Sounds_[SoundID]) == MA_TRUE;
}

void AudioManager::PlaySound(int32_t SoundID)
{
	CHECK((0 <= SoundID && SoundID < Sounds_.size()), "out of range sound id...");
	CHECK(ma_sound_start(Sounds_[SoundID]) == MA_SUCCESS, "failed to play sound");
}

bool AudioManager::IsPlayingSound(int32_t SoundID)
{
	CHECK((0 <= SoundID && SoundID < Sounds_.size()), "out of range sound id...");

	return ma_sound_is_playing(Sounds_[SoundID]) == MA_TRUE;
}

bool AudioManager::IsDoneSound(int32_t SoundID)
{
	CHECK((0 <= SoundID && SoundID < Sounds_.size()), "out of range sound id...");

	return ma_sound_at_end(Sounds_[SoundID]) == MA_TRUE;
}

void AudioManager::StopSound(int32_t SoundID)
{
	CHECK((0 <= SoundID && SoundID < Sounds_.size()), "out of range sound id...");
	CHECK(ma_sound_stop(Sounds_[SoundID]) == MA_SUCCESS, "failed to stop play sound");
}

bool AudioManager::IsStoppingSound(int32_t SoundID)
{
	return !IsDoneSound(SoundID) && !IsPlayingSound(SoundID);
}

void AudioManager::ResetSound(int32_t SoundID)
{
	CHECK(ma_sound_seek_to_pcm_frame(Sounds_[SoundID], 0) == MA_SUCCESS, "failed to reset play sound");
}

AudioManager::~AudioManager()
{
	Cleanup();
}
