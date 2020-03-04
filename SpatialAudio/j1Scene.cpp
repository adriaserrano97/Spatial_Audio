#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Scene.h"

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");

}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{

	//We will use this laster
	background = App->tex->Load("textures/background.png");
	debug_tex = App->tex->Load("textures/test.png");

	


	//TODO 1: Use PlayMusic function in module Audio. Check the function, I've added detailed explanation on what it does.
	//The music you wanna be playing is "elevator_music.ogg" found in game/audio/music.
	//"PlayMusic" is an amalgamation of several SDL functions regarding loading, playing, fadeout, looping... It makes everything easier 
	
	//App->audio->PlayMusic("audio/music/elevator_music.ogg", 4.0F);
	
		
	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	

	bool ret = true;

	

	return ret;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	//TODO 2: Use the structure on TODO1 and just add some "if..."
	//Notice that PlayMusic automatically handles fadeout. Hooray!
	//F6 should play elevator music, F7 sadpiano.

	/*
	if (App->input->GetKey(SDL_SCANCODE_F6) == KEY_DOWN)
	{
		App->audio->PlayMusic("audio/music/elevator_music.ogg", 4.0F);
	}
	if (App->input->GetKey(SDL_SCANCODE_F7) == KEY_DOWN)
	{
		App->audio->PlayMusic("audio/music/music_sadpiano.ogg", 4.0F);
	}
	*/

	//TODO 3: Now, trigger the change based on screen position
	//To check, use Render values:  camera.x and camera.w (we only check one axis to simplify. In-game, check both axis)
	//Check if the song you want to play is already beign played! 
	//If the orange circle (x = -30, y= -710) is on camera, play elevator music
	//If the red circle (x = -1450, y= -710) is on camera, play sadpiano

	/*
	if (App->render->camera.x < -30 + App->render->camera.w && App->render->camera.x > -30 && SongPlaying != 1)
	{
		SongPlaying = 1;
		App->audio->PlayMusic("audio/music/elevator_music.ogg", 1.0F);
	}
	if (App->render->camera.x > -1450) 
	{
		if (App->render->camera.x < -440) {
			if(SongPlaying != 2){
			SongPlaying = 2;
			App->audio->PlayMusic("audio/music/music_sadpiano.ogg", 1.0F);
			}
		}
	}
	*/

	//TODO 4: Check in the documentation Mix_SetPosition function. Make SURE you understand it's arguments and how it works.
	// Once you do, Configure 4 channels: channel 1 should be left and close, channel 2 left and far, channel 3 right and close, channel 4 right and far
	//Once the channels are set, make it so F1, F2, F3 and F4 play our loaded sfx (check a function in Audio called PlayFx) in channel 1,2,3 and 4.
	//Hint: maybe you want to check Mix_HaltChannel... ;)
	/*
	if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
	{
		Mix_HaltChannel(-1);
		Mix_SetPosition(1, 270, 1);
		App->audio->PlayFx(1,App->audio->small_sound,0);
	}
	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN)
	{
		Mix_HaltChannel(-1);
		Mix_SetPosition(2, 270, 200);
		App->audio->PlayFx(2, App->audio->small_sound, 0);
	}
	if (App->input->GetKey(SDL_SCANCODE_F3) == KEY_DOWN)
	{
		Mix_HaltChannel(-1);
		Mix_SetPosition(3, 90, 1);
		App->audio->PlayFx(3, App->audio->small_sound, 0);
	}
	if (App->input->GetKey(SDL_SCANCODE_F4) == KEY_DOWN)
	{
		Mix_HaltChannel(-1);
		Mix_SetPosition(4, 90, 200);
		App->audio->PlayFx(4, App->audio->small_sound, 0);
	}
	*/


	//TODO 5. If you've made it this far, you don't need my help to do this TODO.
	/*
	if (App->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN)
	{
		Mix_HaltChannel(-1);
		App->audio->PlayFx(5, App->audio->small_sound, 0);
	}
	*/


	//TODO 6. Configure the channel before playing the chunk. Take into account variable distance!
				//DISCLAIMER: You'll need a little math here.

	/*
	if (App->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN)
	{
		Mix_HaltChannel(-1);
		int distance = (App->render->camera.x * App->render->camera.x + App->render->camera.y * App->render->camera.y); // cause remember, inverse square law
		distance = distance / 500; //to scale a bit
		int volume = (distance * 255) / App->render->camera.w;
		if (volume < 0) { volume = 0; } if (volume > 255) { volume =  255; }
		Mix_SetPosition(5, 0,volume);
		App->audio->PlayFx(5, App->audio->small_sound, 0);
	}
	*/

	//TODO 7. In the configuration of the channel, take into account the angle that forms the camera position according to 0,0. 
	// Again, math is required. You have at your disposal trigonometry funcs.

	/*
	if (App->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN)
	{
		Mix_HaltChannel(-1);
		//int distance = (App->render->camera.x * App->render->camera.x + App->render->camera.y * App->render->camera.y); // cause remember, inverse square law
		//distance = distance / 500; //to scale a bit
		//int volume = (distance * 255) / App->render->camera.w;
		//if (volume < 0) { volume = 0; } if (volume > 255) { volume =  255; }

		float angle = 90;
		if (App->render->camera.y == 0) { 
			angle = atan(-App->render->camera.x); }
		else { 
			angle = atan((-App->render->camera.x) / (App->render->camera.y)); 
		}
		angle = angle * 57 + 360; //conversion from rad to degree +270. We add +90 extra cause sdl has 0 as its front for some fkn reason. 

		Mix_SetPosition(5, angle , 0);
		App->audio->PlayFx(5, App->audio->small_sound, 0);
	}
	*/

	//TODO 8. Merge todo 6 and 7.
	/*
		Mix_HaltChannel(-1);
		int distance = (App->render->camera.x * App->render->camera.x + App->render->camera.y * App->render->camera.y); // cause remember, inverse square law
		distance = distance / 500; //to scale a bit
		int volume = (distance * 255) / App->render->camera.w;
		if (volume < 0) { volume = 0; } if (volume > 255) { volume =  255; }

		float angle = 90;
		if (App->render->camera.y == 0) { 
			angle = atan(-App->render->camera.x); }
		else { 
			angle = atan((-App->render->camera.x) / (App->render->camera.y)); 
		}
		angle = angle * 57 + 360; //conversion from rad to degree +270. We add +90 extra cause sdl has 0 as its front for some fkn reason. 

		Mix_SetPosition(5, angle , volume);
		App->audio->PlayFx(5, App->audio->small_sound, 0);

	*/




	//just moving camera around
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		App->render->camera.y -= 10;

	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		App->render->camera.y += 10;

	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		App->render->camera.x -= 10;

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		App->render->camera.x += 10;



	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate() {
	
	bool ret = true;

	App->render->Blit(background, 0, 0);


	//Update title
	static char title[256];
	sprintf_s(title, 256, " Spatial Audio Task || Adria Serrano || Camera X: %i || Camera Y: %i  ",
				App->render->camera.x, App->render->camera.y);
	
	if (App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN) {
		ret = false;
	}

	App->win->SetTitle(title);

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	return true;
}