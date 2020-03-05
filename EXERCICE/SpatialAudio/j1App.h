#ifndef __j1APP_H__
#define __j1APP_H__

#define TIME_CONST 50
#define MAX_DT 3

#include "p2List.h"
#include "j1Module.h"

#include "PugiXml\src\pugixml.hpp"

typedef unsigned int uint;

// Modules
class j1Window;
class j1Input;
class j1Render;
class j1Textures;
class j1Audio;
class j1Scene;
class j1Map;
class j1Collision;
class j1FadeToBlack;
class j1PathFinding;
class j1EntityManager;
class j1Fonts;
class j1Gui;
class j1Console;


class j1App
{
public:

	// Constructor
	j1App(int argc, char* args[]);

	// Destructor
	virtual ~j1App();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called each loop iteration
	bool Update();

	// Called before quitting
	bool CleanUp();

	// Add a new module to handle
	void AddModule(j1Module* module);

	// Exposing some properties for reading
	int GetArgc() const;
	const char* GetArgv(int index) const;
	const char* GetTitle() const;
	const char* GetOrganization() const;

	

private:

	// Load config file
	pugi::xml_node LoadConfig(pugi::xml_document&) const;

	// Call modules before each loop iteration
	bool PreUpdate();

	// Call modules on each loop iteration
	bool DoUpdate();

	// Call modules after each loop iteration
	bool PostUpdate();

	

public:

	// Modules
	j1Window*			win;
	j1Input*			input;
	j1Render*			render;
	j1Textures*			tex;
	j1Audio*			audio;
	j1Scene*			scene;
	j1Map*				map;
	j1Collision*		colliders;
	j1FadeToBlack*		fade;
	j1PathFinding*		pathfinding;
	j1EntityManager*	entityManager;
	j1Fonts*			font;
	j1Gui*				gui;
	j1Console*			console;

	//timers

	
	uint32_t				frames;

	uint				frameRate = 0;

private:
	p2List<j1Module*>	modules;

	int					argc;
	char**				args;

	p2SString			title;
	p2SString			organization;



	bool				cap_frames;
	float				dt;
};

extern j1App* App; 

#endif