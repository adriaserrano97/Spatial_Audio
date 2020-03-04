#include "p2Defs.h"
#include "p2Log.h"
#include "j1Audio.h"
#include "p2List.h"
#include "SDL/include/SDL.h"
#include "SDL_mixer\include\SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

j1Audio::j1Audio() : j1Module()
{
	music = NULL;
	name.create("audio");
}

// Destructor
j1Audio::~j1Audio()
{}

// Called before render is available
bool j1Audio::Awake()
{

	bool ret = true;
	SDL_Init(0);

	

	if(SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
	{
		active = false;
		ret = true;
	}
	//TODO 1: Nothing to do here. Just wanted to remind you all that we need to load support for formats.

	// load support for OGG
	int flags = MIX_INIT_OGG;
	int init = Mix_Init(flags);

	if((init & flags) != flags)
	{
		active = false;
		ret = true;
	}

	//Initialize SDL_mixer
	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		active = false;
		ret = true;
	}

	//Load SFX needed. The Load function returns the int we need to call it in PlayFx, so we store it for easier use.

	//jump_sound =		LoadFx(PATH(fxFolder.GetString(), config.child("fx").attribute("jump").as_string()));
	//bomb_sound =		LoadFx(PATH(fxFolder.GetString(), config.child("fx").attribute("bomb").as_string()));
	
	return ret;
}

// Called before quitting
bool j1Audio::CleanUp()
{
	if(!active)
		return true;


	if(music != NULL)
	{
		Mix_FreeMusic(music);
	}

	p2List_item<Mix_Chunk*>* item;
	for(item = fx.start; item != NULL; item = item->next)
		Mix_FreeChunk(item->data);

	fx.clear();

	Mix_CloseAudio();
	Mix_Quit();
	SDL_QuitSubSystem(SDL_INIT_AUDIO);

	return true;
}

// Play a music file
bool j1Audio::PlayMusic(const char* path, float fade_time) //path = where the .ogg is || fade_time = how long takes the fadeout. I reccommend 4.0F
{
	bool ret = true;

	// If the Mixer has not been initiated, exit the function.
	if(!active)
		return false;

	//If the music is already loaded:
	if(music != NULL)
	{
		if(fade_time > 0.0f) 
		{
			Mix_FadeOutMusic(int(fade_time * 1000.0f)); //This plays the music! argument is in milisecond, so we multiply by 1000
		}
		else
		{
			Mix_HaltMusic(); //This stops music. It's useful: we can use this function to change between different songs because of this!
		}

		// this call blocks until fade out is done, then frees the music
		Mix_FreeMusic(music);
	}
	//If it is not loaded, load it
	music = Mix_LoadMUS(path); //<- this command is what you want if you wanna load music manually

	if(music == NULL)
	{
		ret = false; //if failed to load, just exit.
	}
	else
	{
		if(fade_time > 0.0f)
		{
			if(Mix_FadeInMusic(music, -1, (int) (fade_time * 1000.0f)) < 0) //that -1 indicates infinite loops. Can be changed for an actual integer.
			{
				ret = false;
			}
		}
		else
		{
			if(Mix_PlayMusic(music, -1) < 0) //that -1 indicates infinite loops. Can be changed for an actual integer.
			{
				ret = false;
			}
		}
	}

	return ret;
}

// Load WAV
unsigned int j1Audio::LoadFx(const char* path)
{
	unsigned int ret = 0;

	if(!active)
		return 0;

	Mix_Chunk* chunk = Mix_LoadWAV(path);

	if(chunk == NULL)
	{
	}

	else
	{
		fx.add(chunk);
		ret = fx.count();
	}

	return ret;
}

// Play WAV
bool j1Audio::PlayFx(unsigned int id, int repeat)
{
	bool ret = false;
	id += 0;
	if(!active)
		return false;

	if(id > 0 && id <= fx.count())
	{
		Mix_PlayChannel(-1, fx[id - 1], repeat);
		//Input explanation: first argument is channel, -1  meanining first free channel. Second argument is a pointer to the chunk to play.
		//3rd argument is number of loops. if you want in once, put 0. -1 plays it "infinite" times.
	}

	return ret;
}

