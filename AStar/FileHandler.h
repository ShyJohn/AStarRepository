#pragma once

#include <fstream>
#include "Helpers.h"
#include "Node.h"

namespace AIFramework
{
	class FileHandler
	{

	public:
		void LoadLevel(Node** nodesArray)
		{
			std::fstream reader("Level.txt");
			int i, j;
			int tempType;

			if (reader.is_open())
			{
				for (i = 0; i < GRID_WIDTH; i++)
				{
					for (j = 0; j < GRID_HEIGHT; j++)
					{
						// Read File
						reader >> tempType;
						nodesArray[i][j].SetType((GridType)tempType);
					}
				}
			}
			reader.close();
		}

		void SaveLevel(Node** nodesArray)
		{
			int i, j;

			std::fstream writer("Level.txt");

			GridType tempType;

			if (writer.is_open())
			{
				for (i = 0; i < GRID_WIDTH; i++)
				{
					for (j = 0; j < GRID_HEIGHT; j++)
					{
						// Save File
						writer << (int)nodesArray[i][j].GetType() << std::endl;
					}
				}
			}
			writer.close();
		}
	};
}