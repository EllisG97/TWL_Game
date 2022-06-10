
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

		//detect collisions and if goal has been reached
		//second part only activates if thomas has reached home
		if (detectCollisions(m_Thomas) && detectCollisions(m_Bob))
		{
			//New level required
			m_NewLevelRequired = true;
			//play the goal reached sound
			m_SM.playReachGoal();

		}
		else
		{
			//run bobs collisions detection 
			detectCollisions(m_Bob);
		}


		//Count down the remaning time for the player
		m_TimeRemaining -= dtAsSeconds;

		//Check to see if Tom or Bob have run out of time
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}

	} // End if playing

	//check if a fire sound is needed
	vector<Vector2f>::iterator it;

	//Iterate through the vector of vector2f objects
	for (it = m_FireEmitters.begin(); it != m_FireEmitters.end(); it++)
	{
		//Where is the emitter?
		//Store location in pos
		float posX = (*it).x;
		float posY = (*it).y;

		//is the emitter near the player?
		//Make a 500 pixel rect around emitter
		FloatRect localRect(posX - 250, posY - 250, 500, 500);

		//Is the player inside the rect?
		if (m_Thomas.getPosition().intersects(localRect))
		{
			//play the sound and pass in location as well
			m_SM.playFire(Vector2f(posX, posY), m_Thomas.getCenter());
		}
	}


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


	//Time to update the HUD?
	//Increment the num of frames since last HUD calculation
	m_FramesSinceLastHUDUpdate++;

	// Update the HUD every m_TargetFramesPerHUDUpdate frames
	if (m_FramesSinceLastHUDUpdate > m_TargetFramesPerHUDUpdate)
	{
		//Update game HUD text
		stringstream ssTime;
		stringstream ssLevel;

		//update game time text
		ssTime << (int)m_TimeRemaining;
		m_Hud.setTime(ssTime.str());

		//update the level text
		ssLevel << "Level: " << m_LM.getCurrentLevel();
		m_Hud.setLevel(ssLevel.str());
		m_FramesSinceLastHUDUpdate = 0;
	}

	//update the particles
	if (m_PS.running())
	{
		m_PS.update(dtAsSeconds);
	}



}