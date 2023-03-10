#include "AudioManager.h"

#include <algorithm>

// @third party code - BEGIN
#include <miniaudio/miniaudio.h>
// @third party code - END

static std::unique_ptr<ma_engine> MiniAudioEngine = nullptr;
static std::vector<std::unique_ptr<ma_sound>> Sounds;

void AudioManager::Setup()
{
	if (bIsSetup_) return;

	MiniAudioEngine = std::make_unique<ma_engine>();
	CHECK((ma_engine_init(nullptr, MiniAudioEngine.get()) == MA_SUCCESS), "failed to initialize miniaudio engine...");
	Sounds.resize(0);

	bIsSetup_ = true;
}

void AudioManager::Cleanup()
{
	if (!bIsSetup_) return;

	for (auto& Sound : Sounds)
	{
		ma_sound_uninit(Sound.get());
		Sound.reset();
	}

	ma_engine_uninit(MiniAudioEngine.get());
	MiniAudioEngine.reset();

	bIsSetup_ = false;
}

int32_t AudioManager::CreateSound(const std::string& ResourcePath)
{
	std::unique_ptr<ma_sound> Sound = std::make_unique<ma_sound>();

	CHECK((ma_sound_init_from_file(MiniAudioEngine.get(), ResourcePath.c_str(), 0, nullptr, nullptr, Sound.get()) == MA_SUCCESS), "failed to cretae sound resource...");
	Sounds.push_back(std::move(Sound));

	return CountSoundResource_++;
}

void AudioManager::SetSoundVolume(int32_t SoundID, float Volume)
{
	CHECK((0 <= SoundID && SoundID < Sounds.size()), "out of range sound id...");

	Volume = std::clamp<float>(Volume, 0.0f, 1.0f);
	ma_sound_set_volume(Sounds[SoundID].get(), Volume);
}

float AudioManager::GetSoundVolume(int32_t SoundID)
{
	CHECK((0 <= SoundID && SoundID < Sounds.size()), "out of range sound id...");

	return ma_sound_get_volume(Sounds[SoundID].get());
}

void AudioManager::SetSoundLooping(int32_t SoundID, bool bIsLoop)
{
	CHECK((0 <= SoundID && SoundID < Sounds.size()), "out of range sound id...");

	ma_sound_set_looping(Sounds[SoundID].get(), static_cast<ma_bool32>(bIsLoop));
}

bool AudioManager::GetSoundLooping(int32_t SoundID)
{
	CHECK((0 <= SoundID && SoundID < Sounds.size()), "out of range sound id...");

	return ma_sound_is_looping(Sounds[SoundID].get()) == MA_TRUE;
}

void AudioManager::PlaySound(int32_t SoundID)
{
	CHECK((0 <= SoundID && SoundID < Sounds.size()), "out of range sound id...");
	CHECK(ma_sound_start(Sounds[SoundID].get()) == MA_SUCCESS, "failed to play sound");
}

bool AudioManager::IsPlayingSound(int32_t SoundID)
{
	CHECK((0 <= SoundID && SoundID < Sounds.size()), "out of range sound id...");

	return ma_sound_is_playing(Sounds[SoundID].get()) == MA_TRUE;
}

bool AudioManager::IsDoneSound(int32_t SoundID)
{
	CHECK((0 <= SoundID && SoundID < Sounds.size()), "out of range sound id...");

	return ma_sound_at_end(Sounds[SoundID].get()) == MA_TRUE;
}

void AudioManager::StopSound(int32_t SoundID)
{
	CHECK((0 <= SoundID && SoundID < Sounds.size()), "out of range sound id...");
	CHECK(ma_sound_stop(Sounds[SoundID].get()) == MA_SUCCESS, "failed to stop play sound");
}

bool AudioManager::IsStoppingSound(int32_t SoundID)
{
	return !IsDoneSound(SoundID) && !IsPlayingSound(SoundID);
}

void AudioManager::ResetSound(int32_t SoundID)
{
	CHECK(ma_sound_seek_to_pcm_frame(Sounds[SoundID].get(), 0) == MA_SUCCESS, "failed to reset play sound");
}

AudioManager::~AudioManager()
{
	Cleanup();
}