
#include "pch.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>>

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_Playing)
	{
		//Count down the remaning time for the player
		m_TimeRemaining -= dtAsSeconds;

		//Check to see if Tom or Bob have run out of time
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}

	} // End if playing


}