#pragma once
#include "PlayableCharacter.h"

class Bob : public PlayableCharacter
{
public:
	//a constructor for Mr Bob
	Bob();


	//overriden input handler for Bob
	bool virtual handleInput();



};