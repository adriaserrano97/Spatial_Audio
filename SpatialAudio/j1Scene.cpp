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

	/*
	if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
	{
		App->audio->PlayMusic("audio/music/elevator_music.ogg", 4.0F);
	}
	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN)
	{
		App->audio->PlayMusic("audio/music/music_sadpiano.ogg", 4.0F);
	}
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

	if (App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN) {
		ret = false;
	}

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	return true;
}