#include "AudioManager.h"

AudioManager::AudioManager():
	m_audio_data(NULL),
	m_audio_data_len(0),
	m_audio_stream(NULL),
	m_loop(false),
	m_audio_spec()
{
}

AudioManager::~AudioManager()
{
	SDL_free(m_audio_data);
}

void AudioManager::update()
{
	// https://examples.libsdl.org/SDL3/audio/03-load-wav/
	if (m_loop)
	{
		if (SDL_GetAudioStreamQueued(m_audio_stream) < (int) m_audio_data_len) {
			SDL_PutAudioStreamData(m_audio_stream, m_audio_data, m_audio_data_len);
		}
	}
}

bool AudioManager::loadWAV(std::string filename)
{
	if (!SDL_LoadWAV(filename.c_str(), &m_audio_spec, &m_audio_data, &m_audio_data_len)) {
		SDL_Log("Couldn't load .wav file: %s", SDL_GetError());
		return false;
	}

	/* Create our audio stream in the same format as the .wav file. It'll convert to what the audio hardware wants. */
	m_audio_stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &m_audio_spec, NULL, NULL);
	if (!m_audio_stream) {
		SDL_Log("Couldn't create audio stream: %s", SDL_GetError());
		return false;
	}
	return true;
}

void AudioManager::pause()
{
	SDL_PauseAudioStreamDevice(m_audio_stream);
}

void AudioManager::play()
{
	SDL_ResumeAudioStreamDevice(m_audio_stream);
}
