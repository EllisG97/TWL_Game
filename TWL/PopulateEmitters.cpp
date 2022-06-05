#include "pch.h"
#include "Engine.h"

using namespace sf;
using namespace std;

void Engine::populateEmitters(
	vector <Vector2f>& vSoundEmitters, int** arrayLevel) 
{
	//make sure vector is empty
	vSoundEmitters.empty();

	//keep track of past emitter
	//to pevent making too many 
	FloatRect previousEmitter;

	//search for the fire in the current level
	for (int x = 0; x < (int)m_LM.getLevelSize().x; x++)
	{
		for (int y = 0; y < (int)m_LM.getLevelSize().y; y++)
		{
			if (arrayLevel[y][x] == 2) //fire is present
			{
				//skip over any fire tiles near previous emitter
				if (!FloatRect(x * TILE_SIZE,
					y * TILE_SIZE,
					TILE_SIZE,
					TILE_SIZE).intersects(previousEmitter))
				{
					//add coordinates of watre block
					vSoundEmitters.push_back(
						Vector2f(x * TILE_SIZE, y * TILE_SIZE));
					//make a 6 x 6 rectangle block
					//to prevent making any more close range emitters
					previousEmitter.left = x * TILE_SIZE;
					previousEmitter.top = y * TILE_SIZE;
					previousEmitter.width = TILE_SIZE * 6;
					previousEmitter.height = TILE_SIZE * 6;
				}
			}

		}
	}

	return;
}
