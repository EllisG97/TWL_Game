#include "pch.h"
#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter& character)
{

	bool reachedGoal = false;

	//make a rect for all the parts
	FloatRect detectionZone = character.getPosition();

	//Make a rect to test each blocks
	FloatRect block;

	block.width = TILE_SIZE;


	//build a zone around tom for collisions
	int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;

	//Thomas is the tall character to check tiles above
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3;

	//Ensure no positons below zero are tested
	//or higher up than the maximum array
	if (startX < 0) startX = 0;
	if (startY < 0) startY = 0;
	if (endX >= m_LM.getLevelSize().x)
		endX = m_LM.getLevelSize().x;
	if (endY = m_LM.getLevelSize().y)
		endY = m_LM.getLevelSize().y;

	//check if the character has fallen off the map
	for (int x = startX; x < endX; x++)
	{
		for (int y = startY; y < endY; y++)
		{
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			//Has the character been burnt or drowned?
			//use head for detection 
			if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 3)
			{
				if (character.getHead().intersects(block))
				{
					character.spawn(m_LM.getStartPosition(), GRAVITY);

					//which sound should we play?
					if (m_ArrayLevel[y][x] == 2) //fire
						//play burn sound
						m_SM.playFallInFire();

					else //water
					{
						//play water sound
						m_SM.playFallInWater();

					}
						
				}
			}
				//is character colliding with a block?
			if (m_ArrayLevel[y][x] == 1)
			{
				if (character.getRight().intersects(block))
				{
					character.stopRight(block.left);
				}
				else if (character.getLeft().intersects(block))
				{
					character.stopLeft(block.left);
				}

				if (character.getFeet().intersects(block))
				{
					character.stopFalling(block.top);
				}
				else if (character.getHead().intersects(block))
				{
					character.stopJump();
				}

			}

			//collision linked to particles
			

			//has the character reached the goal?
			if (m_ArrayLevel[y][x] == 4)
			{
				//character has reached the end of the level
				reachedGoal = true;
			}

		}
	
	}

	return reachedGoal;

}