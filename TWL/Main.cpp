// SFML_Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Engine.h"

int main()
{
  //Declare an instance of Engine
	Engine engine;

	//Start the game engine
	engine.run();

	//Quit the game when the engine is done
	return 0;
}

