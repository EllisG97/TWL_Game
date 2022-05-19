#include "pch.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TextureHolder.h"
#include <sstream>
#include <fstream>
#include "LevelManager.h"

using namespace sf;
using namespace std;

int** levelManager::nextLevel(VertexArray& rVaLevel)
{
	m_LevelSize.x = 0;
	m_LevelSize.y = 0;

	//get the next level
	m_CurrentLevel++;
	if (m_CurrentLevel > NUM_LEVELS)
	{
		m_CurrentLevel = 1;
		m_TimeModifier -= .1f;
	}

	//Load the correct level from a text file
	string levelToLoad;
	switch (m_CurrentLevel)
	{
	case 1:
		levelToLoad = "levels/level1.txt";
		m_StartPosition.x = 100;
		m_StartPosition.y = 100;
		m_BaseTimeLimit = 30.0f;
		break;

	case 2:
		levelToLoad = "levels/level2.txt";
		m_StartPosition.x = 100;
		m_StartPosition.y = 3600;
		m_BaseTimeLimit = 100.0f;
		break;

	case 3:
		levelToLoad = "levels/level3.txt";
		m_StartPosition.x = 1250;
		m_StartPosition.y = 0;
		m_BaseTimeLimit = 30.0f;
		break;

	case 4:
		levelToLoad = "levels/level4.txt";
		m_StartPosition.x = 50;
		m_StartPosition.y = 200;
		m_BaseTimeLimit = 50.0f;
		break;


	}

	ifstream inputFile(levelToLoad);
	string s;

	//count the number of rows in the txt file
	while (getline(inputFile, s))
	{
		++m_LevelSize.y;
	}

	//store the length of the rows
	m_LevelSize.x = s.length();

	//go back to the start of the file
	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	//prepare the second array to hold int values from the txt file
	int** arrayLevel = new int* [m_LevelSize.y];
	for (int i = 0; i < m_LevelSize.y; i++)
	{
		//add a new array into each array element
		arrayLevel[i] = new int[m_LevelSize.x];

	}

	//Loop through the file and store all the 2d array values
	string row;
	int y = 0;
	while (inputFile >> row)
	{
		for (int x = 0; x < row.length(); x++)
		{
			const char val = row[x];
			arrayLevel[y][x] = atoi(&val);

		}
		y++;
	}

	//close the file
	inputFile.close();

	//What type of primitive are we adding?
	rVaLevel.setPrimitiveType(Quads);

	//set the size of the vertex array
	rVaLevel.resize(m_LevelSize.x * m_LevelSize.y * VERT_IN_QUAD);

	//start at the beginning of the array 
	int currentVertex = 0;

	for (int x = 0; x < m_LevelSize.x; x++)
	{
		for (int y = 0; y = m_LevelSize.y; y++)
		{
			//position each vertex in current quad
			rVaLevel[currentVertex = 0].position =
				Vector2f(x * TILE_SIZE,
					y * TILE_SIZE);

			rVaLevel[currentVertex + 1].position =
				Vector2f((x * TILE_SIZE) + TILE_SIZE,
					y * TILE_SIZE);

			rVaLevel[currentVertex + 2].position =
				Vector2f((x * TILE_SIZE) + TILE_SIZE,
					(y * TILE_SIZE) + TILE_SIZE);

			rVaLevel[currentVertex + 3].position =
				Vector2f((x * TILE_SIZE),
					(y * TILE_SIZE) + TILE_SIZE);

			//Which tile from the sprite sheet should we use?
			int verticalOffset = arrayLevel[y][x] * TILE_SIZE;

			rVaLevel[currentVertex + 0].texCoords =
				Vector2f(0, 0 + verticalOffset);

			rVaLevel[currentVertex + 1].texCoords =
				Vector2f(TILE_SIZE, 0 + verticalOffset);

			rVaLevel[currentVertex + 2].texCoords =
				Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);

			rVaLevel[currentVertex + 3].texCoords =
				Vector2f(0, TILE_SIZE + verticalOffset);

			//position ready for the next four vertices
			currentVertex = currentVertex + VERT_IN_QUAD;

		}
	}

	return arrayLevel;

} //end of next level function