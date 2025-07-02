#pragma once

#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>


class AudioManager
{
public:
	AudioManager();
	~AudioManager();

	void update();

	bool loadWAV(std::string filename);

	void pause();
	void play();

private:
	SDL_AudioStream* m_audio_stream;
	SDL_AudioSpec m_audio_spec;
	Uint8* m_audio_data;
	Uint32 m_audio_data_len;

	bool m_loop;
};