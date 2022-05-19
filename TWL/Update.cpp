
#include "pch.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>>

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		loadLevel();
	}



	if (m_Playing)
	{
		//update Thomas
		m_Thomas.update(dtAsSeconds);

		//Update Bob
		m_Bob.update(dtAsSeconds);


		//Count down the remaning time for the player
		m_TimeRemaining -= dtAsSeconds;

		//Check to see if Tom or Bob have run out of time
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}

	} // End if playing

	//set the correct view for the current selected character
	if (m_SplitScreen)
	{
		m_LeftView.setCenter(m_Thomas.getCenter());
		m_RightView.setCenter(m_Bob.getCenter());
	}
	else
	{
		//centre the full screen around a specific character
		if (m_Character1)
		{
			m_MainView.setCenter(m_Thomas.getCenter());
		}
		else
		{
			m_MainView.setCenter(m_Bob.getCenter());
		}

	}




}