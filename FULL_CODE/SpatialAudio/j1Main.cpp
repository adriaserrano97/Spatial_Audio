#include <stdlib.h>

#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"

// This is needed here because SDL redefines main function
// do not add any other libraries here, instead put them in their modules
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )


enum MainState
{
	CREATE = 1,
	AWAKE,
	START,
	LOOP,
	CLEAN,
	FAIL,
	EXIT
};

j1App* App = NULL;

int main(int argc, char* args[])
{

	MainState state = MainState::CREATE;
	int result = EXIT_FAILURE;

	while(state != EXIT)
	{
		
		switch(state)
		{

			// Allocate the engine --------------------------------------------
			case CREATE:

			App = new j1App(argc, args);

			if(App != NULL)
				state = AWAKE;
			else
				state = FAIL;

			break;

			// Awake all modules -----------------------------------------------
			case AWAKE:
			if(App->Awake() == true)
				state = START;
			else
			{
				state = FAIL;
			}

			break;

			// Call all modules before first frame  ----------------------------
			case START:
			if(App->Start() == true)
			{
				state = LOOP;
			}
			else
			{
				state = FAIL;
			}
			break;

			// Loop all modules until we are asked to leave ---------------------
			case LOOP:
			if(App->Update() == false)
				state = CLEAN;
			break;

			// Cleanup allocated memory -----------------------------------------
			case CLEAN:
			if(App->CleanUp() == true)
			{
				RELEASE(App);
				result = EXIT_SUCCESS;
				state = EXIT;
			}
			else
				state = FAIL;

			break;

			// Exit with errors and shame ---------------------------------------
			case FAIL:
			result = EXIT_FAILURE;
			state = EXIT;
			break;
		}
	}

	LOG("... Bye! :)\n");

	// Dump memory leaks
	return result;
}