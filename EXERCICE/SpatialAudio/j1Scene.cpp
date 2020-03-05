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

	

	//TODO 3: Now, trigger the change based on screen position
	//To check, use Render values:  camera.x and camera.w (we only check one axis to simplify. In-game, check both axis)
	//Check if the song you want to play is already beign played! 
	//If the orange circle (x = -30, y= -710) is on camera, play elevator music
	//If the red circle (x = -1450, y= -710) is on camera, play sadpiano

	

	//TODO 4: Check in the documentation Mix_SetPosition function. Make SURE you understand it's arguments and how it works.
	// Once you do, Configure 4 channels: channel 1 should be left and close, channel 2 left and far, channel 3 right and close, channel 4 right and far
	//Once the channels are set, make it so F1, F2, F3 and F4 play our loaded sfx (check a function in Audio called PlayFx) in channel 1,2,3 and 4.
	//Hint: maybe you want to check Mix_HaltChannel... ;)
	


	//TODO 5. If you've made it this far, you don't need my help to do this TODO.
	


	//TODO 6. Configure the channel before playing the chunk. Take into account variable distance!
				//DISCLAIMER: You'll need a little math here.

	

	//TODO 7. In the configuration of the channel, take into account the angle that forms the camera position according to 0,0. 
	// Again, math is required. You have at your disposal trigonometry funcs.

	

	//TODO 8. Merge todo 6 and 7.
	




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