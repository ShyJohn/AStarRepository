#pragma once

#include <fstream>
#include "Helpers.h"
#include "Node.h"

class FileHandler
{

public:
	void LoadLevel(Node** nodesArray)
	{
		std::fstream reader("Level.txt");
		int i, j;

		for (i = 0; i < GRID_WIDTH; i++)
		{
			for (j = 0; j < GRID_HEIGHT; j++)
			{
				// Read File
				//nodesArray[i][j].SetType(EMPTY);
			}
		}
	}

	void SaveLevel(Node** nodesArray)
	{
		int i, j, nodeValue;

		std::ofstream saveFile;
		saveFile.open("Level.txt");
		for (i = 0; i < GRID_WIDTH; i++)
		{
			for (j = 0; j < GRID_HEIGHT; j++)
			{
				// Save File
				//saveFile << nodesArray[i][j];
			}
		}

	}
};