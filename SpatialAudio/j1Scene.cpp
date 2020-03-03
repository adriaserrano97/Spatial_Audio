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
bool j1Scene::Awake(pugi::xml_node& config)
{
	
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	

	
	App->audio->PlayMusic("audio/music/ace_of_flopdisks.ogg", 4.0F);
		


	debug_tex = App->tex->Load("maps/path2.png");
	
		
	

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

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	return true;
}