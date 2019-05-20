#include "AStar.h"

namespace AIFramework {

	bool AStar::IsValid(const int x, const int y)
	{
		return(x > 0) && (x < GRID_WIDTH)
			&& (y > 0 && y < GRID_HEIGHT);
	}

	bool AStar::IsBlocked(Node** nodesArray, const int x, const int y)
	{
		if (nodesArray[x][y].GetType() == WALL)
			return true;
		else
			return false;
	}

	bool AStar::IsDestination(const int x, const int y)
	{
		if (x == end.x && y == end.y)
			return true;
		else
			return false;
	}

	float AStar::CalculateH(const int x, const int y)
	{
		return std::sqrt((x - end.x) * (x - end.x) + (y - end.y) * (y - end.y));
	}

	void AStar::TracePath(int x, int y)
	{
		while (!(nodeRecord[x][y].parent.x == x 
			  && nodeRecord[x][y].parent.y == y))
		{
			path.push_back(sf::Vector2i(x, y));
			sf::Vector2i tempNode = nodeRecord[x][y].parent;
			x = tempNode.x;
			y = tempNode.y;
		}

		path.push_back(sf::Vector2i(x, y));

		while (!path.empty())
			path.pop_back();
		
		return;
	}

	void AStar::GeneratePath(Node** _grid, sf::Vector2i _start, sf::Vector2i end)
	{
		bool closedList[GRID_WIDTH][GRID_HEIGHT];
		memset(closedList, false, sizeof(closedList));
		
		int i, j;

		for (i = 0; i < GRID_WIDTH; i++)
		{
			for (j = 0; j < GRID_HEIGHT; j++)
			{
				nodeRecord[i][j].f = FLT_MAX;
				nodeRecord[i][j].g = FLT_MAX;
				nodeRecord[i][j].h = FLT_MAX;
				nodeRecord[i][j].parent = sf::Vector2i(-1, -1);
			}
		}

		sf::Vector2i currentNode = start;

		nodeRecord[currentNode.x][currentNode.y].f = 0.0f;
		nodeRecord[currentNode.x][currentNode.y].g = 0.0f;
		nodeRecord[currentNode.x][currentNode.y].h = 0.0f;
		nodeRecord[currentNode.x][currentNode.y].parent = currentNode;

		std::set<sf::Vector2i> openList;
		
		openList.insert(currentNode);

	}
}