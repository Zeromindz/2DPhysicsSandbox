#include <iostream>


//Include the necessary header file here for your game type
#include "Example.h"
#include "EntryPoint.h"
#include "GameWorld.h"

int main()
{
	GameWorld program;	//Make the type of this variable your game application and you'll be good to go.

	while (program.IsRunning())
	{
		program.Update();
		program.Render();
	}
	return 0;
}