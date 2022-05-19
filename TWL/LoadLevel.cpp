#include "pch.h"
#include "Engine.h"

void Engine::loadLevel()
{

	m_Playing = false;

	//delete the previously allocated memory
	for (int i = 0; i < m_LM.getLevelSize().y; ++i)
	{
		delete[] m_ArrayLevel[i];
	}
	delete[] m_ArrayLevel;

	//load the next 2d array with the map for the level
	//Repopulate the vertex array too
	m_ArrayLevel = m_LM.nextLevel(m_VALevel);

	//How long is the new time limit?
	m_TimeRemaining - m_LM.getTimeLimit();

	//Spawn Mr Thomas and Mr Bob
	m_Thomas.spawn(m_LM.getStartPosition(), GRAVITY);
	m_Bob.spawn(m_LM.getStartPosition(), GRAVITY);


	//prevent code running again
	m_NewLevelRequired = false;



}