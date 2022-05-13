#pragma once
#include "PlayableCharacter.h"

class Thomas : public PlayableCharacter
{
public:
	//A constructor for Mr Thomas
	Thomas();

	//Overriden inpute handler for Thomas
	bool virtual handleInput();


};