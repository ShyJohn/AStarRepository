#include "AStar.h"

namespace AIFramework {

	bool AStar::IsValid( int x,  int y)
	{
		return(x > 0) && (x < GRID_WIDTH)
			&& (y > 0 && y < GRID_HEIGHT);
	}

	bool AStar::IsBlocked(Node** nodesArray,  int x,  int y)
	{
		if (nodesArray[x][y].GetType() == WALL)
			return true;
		else
			return false;
	}

	bool AStar::IsDestination( int x,  int y)
	{
		if (x == end.x && y == end.y)
			return true;
		else
			return false;
	}

	float AStar::CalculateH( int x,  int y)
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

	void AStar::GeneratePath(Node** _grid)
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

		std::set<pPair> openList;
		
		openList.insert(std::make_pair(0.0, std::make_pair(currentNode.x, currentNode.y)));

		bool foundDest = false;

		while (!openList.empty())
		{
			pPair p = *openList.begin();
			
			openList.erase(openList.begin());

			currentNode.x = p.second.first;
			currentNode.y = p.second.second;
			closedList[i][j] = true;

			double gNew, hNew, fNew;

			if (IsValid(currentNode.x - 1, currentNode.y) == true)
			{
				// If the destination cell is the same as the 
				// current successor 
				if (IsDestination(currentNode.x - 1, currentNode.y) == true)
				{
					// Set the Parent of the destination cell 
					nodeRecord[currentNode.x - 1][currentNode.y].parent.x = currentNode.x;
					nodeRecord[currentNode.x - 1][currentNode.y].parent.y = currentNode.y;

					TracePath(currentNode.x, currentNode.y);
					foundDest = true;
					return;
				}
				// If the successor is already on the closed 
				// list or if it is blocked, then ignore it. 
				// Else do the following 
				else if (closedList[currentNode.x - 1][currentNode.y] == false &&
					IsBlocked(grid, currentNode.x - 1, currentNode.y) == false)
				{
					gNew = nodeRecord[currentNode.x][currentNode.y].g + 1.0;
					hNew = CalculateH(currentNode.x - 1, currentNode.y);
					fNew = gNew + hNew;

					// If it isn’t on the open list, add it to 
					// the open list. Make the current square 
					// the parent of this square. Record the 
					// f, g, and h costs of the square cell 
					//                OR 
					// If it is on the open list already, check 
					// to see if this path to that square is better, 
					// using 'f' cost as the measure. 
					if (nodeRecord[currentNode.x - 1][currentNode.y].f == FLT_MAX ||
						nodeRecord[currentNode.x - 1][currentNode.y].f > fNew)
					{
						openList.insert(std::make_pair(fNew, std::make_pair(currentNode.x - 1, currentNode.y)));

						// Update the details of this cell 
						nodeRecord[currentNode.x - 1][currentNode.y].f = fNew;
						nodeRecord[currentNode.x - 1][currentNode.y].g = gNew;
						nodeRecord[currentNode.x - 1][currentNode.y].h = hNew;
						nodeRecord[currentNode.x - 1][currentNode.y].parent.x = currentNode.x;
						nodeRecord[currentNode.x - 1][currentNode.y].parent.y = currentNode.y;
					}
				}
			}

			if (IsValid(currentNode.x + 1, currentNode.y) == true)
			{
				// If the destination cell is the same as the 
				// current successor 
				if (IsDestination(currentNode.x + 1, currentNode.y) == true)
				{
					// Set the Parent of the destination cell 
					nodeRecord[currentNode.x + 1][currentNode.y].parent.x = currentNode.x;
					nodeRecord[currentNode.x + 1][currentNode.y].parent.y = currentNode.y;

					TracePath(currentNode.x, currentNode.y);
					foundDest = true;
					return;
				}
				else if (closedList[currentNode.x + 1][currentNode.y] == false &&
					IsBlocked(grid, currentNode.x + 1, currentNode.y) == false)
				{
					gNew = nodeRecord[currentNode.x][currentNode.y].g + 1.0;
					hNew = CalculateH(currentNode.x + 1, currentNode.y);
					fNew = gNew + hNew;

					if (nodeRecord[currentNode.x + 1][currentNode.y].f == FLT_MAX ||
						nodeRecord[currentNode.x + 1][currentNode.y].f > fNew)
					{
						openList.insert(std::make_pair(fNew, std::make_pair(currentNode.x + 1, currentNode.y)));

						// Update the details of this cell 
						nodeRecord[currentNode.x + 1][currentNode.y].f = fNew;
						nodeRecord[currentNode.x + 1][currentNode.y].g = gNew;
						nodeRecord[currentNode.x + 1][currentNode.y].h = hNew;
						nodeRecord[currentNode.x + 1][currentNode.y].parent.x = currentNode.x;
						nodeRecord[currentNode.x + 1][currentNode.y].parent.y = currentNode.y;
					}
				}
			}

			if (IsValid(currentNode.x, currentNode.y + 1) == true)
			{
				// If the destination cell is the same as the 
				// current successor 
				if (IsDestination(currentNode.x, currentNode.y + 1) == true)
				{
					// Set the Parent of the destination cell 
					nodeRecord[currentNode.x][currentNode.y + 1].parent.x = currentNode.x;
					nodeRecord[currentNode.x][currentNode.y + 1].parent.y = currentNode.y;

					TracePath(currentNode.x, currentNode.y + 1);
					foundDest = true;
					return;
				}
				else if (closedList[currentNode.x][currentNode.y + 1] == false &&
					IsBlocked(grid, currentNode.x, currentNode.y + 1) == false)
				{
					gNew = nodeRecord[currentNode.x][currentNode.y].g + 1.0;
					hNew = CalculateH(currentNode.x, currentNode.y + 1);
					fNew = gNew + hNew;

					if (nodeRecord[currentNode.x][currentNode.y + 1].f == FLT_MAX ||
						nodeRecord[currentNode.x][currentNode.y + 1].f > fNew)
					{
						openList.insert(std::make_pair(fNew, std::make_pair(currentNode.x, currentNode.y + 1)));

						// Update the details of this cell 
						nodeRecord[currentNode.x][currentNode.y + 1].f = fNew;
						nodeRecord[currentNode.x][currentNode.y + 1].g = gNew;
						nodeRecord[currentNode.x][currentNode.y + 1].h = hNew;
						nodeRecord[currentNode.x][currentNode.y + 1].parent.x = currentNode.x;
						nodeRecord[currentNode.x][currentNode.y + 1].parent.y = currentNode.y;
					}
				}
			}

			if (IsValid(currentNode.x, currentNode.y - 1) == true)
			{
				// If the destination cell is the same as the 
				// current successor 
				if (IsDestination(currentNode.x, currentNode.y - 1) == true)
				{
					// Set the Parent of the destination cell 
					nodeRecord[currentNode.x][currentNode.y - 1].parent.x = currentNode.x;
					nodeRecord[currentNode.x][currentNode.y - 1].parent.y = currentNode.y;

					TracePath(currentNode.x, currentNode.y - 1);
					foundDest = true;
					return;
				}
				else if (closedList[currentNode.x][currentNode.y - 1] == false &&
					IsBlocked(grid, currentNode.x, currentNode.y - 1) == false)
				{
					gNew = nodeRecord[currentNode.x][currentNode.y].g + 1.0;
					hNew = CalculateH(currentNode.x, currentNode.y - 1);
					fNew = gNew + hNew;

					if (nodeRecord[currentNode.x][currentNode.y - 1].f == FLT_MAX ||
						nodeRecord[currentNode.x][currentNode.y - 1].f > fNew)
					{
						openList.insert(std::make_pair(fNew, std::make_pair(currentNode.x, currentNode.y - 1)));

						// Update the details of this cell 
						nodeRecord[currentNode.x][currentNode.y - 1].f = fNew;
						nodeRecord[currentNode.x][currentNode.y - 1].g = gNew;
						nodeRecord[currentNode.x][currentNode.y - 1].h = hNew;
						nodeRecord[currentNode.x][currentNode.y - 1].parent.x = currentNode.x;
						nodeRecord[currentNode.x][currentNode.y - 1].parent.y = currentNode.y;
					}
				}
			}

			if (IsValid(currentNode.x - 1, currentNode.y - 1) == true)
			{
				// If the destination cell is the same as the 
				// current successor 
				if (IsDestination(currentNode.x - 1, currentNode.y - 1) == true)
				{
					// Set the Parent of the destination cell 
					nodeRecord[currentNode.x - 1][currentNode.y - 1].parent.x = currentNode.x;
					nodeRecord[currentNode.x - 1][currentNode.y - 1].parent.y = currentNode.y;

					TracePath(currentNode.x - 1, currentNode.y - 1);
					foundDest = true;
					return;
				}
				else if (closedList[currentNode.x - 1][currentNode.y - 1] == false &&
					IsBlocked(grid, currentNode.x - 1, currentNode.y - 1) == false)
				{
					gNew = nodeRecord[currentNode.x - 1][currentNode.y].g + 1.414;
					hNew = CalculateH(currentNode.x - 1, currentNode.y - 1);
					fNew = gNew + hNew;

					if (nodeRecord[currentNode.x - 1][currentNode.y - 1].f == FLT_MAX ||
						nodeRecord[currentNode.x - 1][currentNode.y - 1].f > fNew)
					{
						openList.insert(std::make_pair(fNew, std::make_pair(currentNode.x - 1, currentNode.y - 1)));

						// Update the details of this cell 
						nodeRecord[currentNode.x - 1][currentNode.y - 1].f = fNew;
						nodeRecord[currentNode.x - 1][currentNode.y - 1].g = gNew;
						nodeRecord[currentNode.x - 1][currentNode.y - 1].h = hNew;
						nodeRecord[currentNode.x - 1][currentNode.y - 1].parent.x = currentNode.x;
						nodeRecord[currentNode.x - 1][currentNode.y - 1].parent.y = currentNode.y;
					}
				}
			}

			if (IsValid(currentNode.x + 1, currentNode.y - 1) == true)
			{
				// If the destination cell is the same as the 
				// current successor 
				if (IsDestination(currentNode.x + 1, currentNode.y - 1) == true)
				{
					// Set the Parent of the destination cell 
					nodeRecord[currentNode.x + 1][currentNode.y - 1].parent.x = currentNode.x;
					nodeRecord[currentNode.x + 1][currentNode.y - 1].parent.y = currentNode.y;

					TracePath(currentNode.x + 1, currentNode.y - 1);
					foundDest = true;
					return;
				}
				else if (closedList[currentNode.x + 1][currentNode.y - 1] == false &&
					IsBlocked(grid, currentNode.x + 1, currentNode.y - 1) == false)
				{
					gNew = nodeRecord[currentNode.x + 1][currentNode.y].g + 1.414;
					hNew = CalculateH(currentNode.x + 1, currentNode.y - 1);
					fNew = gNew + hNew;

					if (nodeRecord[currentNode.x + 1][currentNode.y - 1].f == FLT_MAX ||
						nodeRecord[currentNode.x + 1][currentNode.y - 1].f > fNew)
					{
						openList.insert(std::make_pair(fNew, std::make_pair(currentNode.x + 1, currentNode.y - 1)));

						// Update the details of this cell 
						nodeRecord[currentNode.x + 1][currentNode.y - 1].f = fNew;
						nodeRecord[currentNode.x + 1][currentNode.y - 1].g = gNew;
						nodeRecord[currentNode.x + 1][currentNode.y - 1].h = hNew;
						nodeRecord[currentNode.x + 1][currentNode.y - 1].parent.x = currentNode.x;
						nodeRecord[currentNode.x + 1][currentNode.y - 1].parent.y = currentNode.y;
					}
				}
			}

			if (IsValid(currentNode.x - 1, currentNode.y + 1) == true)
			{
				// If the destination cell is the same as the 
				// current successor 
				if (IsDestination(currentNode.x - 1, currentNode.y + 1) == true)
				{
					// Set the Parent of the destination cell 
					nodeRecord[currentNode.x - 1][currentNode.y + 1].parent.x = currentNode.x;
					nodeRecord[currentNode.x - 1][currentNode.y + 1].parent.y = currentNode.y;

					TracePath(currentNode.x - 1, currentNode.y + 1);
					foundDest = true;
					return;
				}
				else if (closedList[currentNode.x - 1][currentNode.y + 1] == false &&
					IsBlocked(grid, currentNode.x - 1, currentNode.y + 1) == false)
				{
					gNew = nodeRecord[currentNode.x - 1][currentNode.y].g + 1.414;
					hNew = CalculateH(currentNode.x - 1, currentNode.y + 1);
					fNew = gNew + hNew;

					if (nodeRecord[currentNode.x - 1][currentNode.y + 1].f == FLT_MAX ||
						nodeRecord[currentNode.x - 1][currentNode.y + 1].f > fNew)
					{
						openList.insert(std::make_pair(fNew, std::make_pair(currentNode.x - 1, currentNode.y + 1)));

						// Update the details of this cell 
						nodeRecord[currentNode.x - 1][currentNode.y + 1].f = fNew;
						nodeRecord[currentNode.x - 1][currentNode.y + 1].g = gNew;
						nodeRecord[currentNode.x - 1][currentNode.y + 1].h = hNew;
						nodeRecord[currentNode.x - 1][currentNode.y + 1].parent.x = currentNode.x;
						nodeRecord[currentNode.x - 1][currentNode.y + 1].parent.y = currentNode.y;
					}
				}
			}

			if (IsValid(currentNode.x + 1, currentNode.y + 1) == true)
			{
				// If the destination cell is the same as the 
				// current successor 
				if (IsDestination(currentNode.x + 1, currentNode.y + 1) == true)
				{
					// Set the Parent of the destination cell 
					nodeRecord[currentNode.x + 1][currentNode.y + 1].parent.x = currentNode.x;
					nodeRecord[currentNode.x + 1][currentNode.y + 1].parent.y = currentNode.y;

					TracePath(currentNode.x + 1, currentNode.y + 1);
					foundDest = true;
					return;
				}
				else if (closedList[currentNode.x + 1][currentNode.y + 1] == false &&
					IsBlocked(grid, currentNode.x + 1, currentNode.y + 1) == false)
				{
					gNew = nodeRecord[currentNode.x + 1][currentNode.y].g + 1.414;
					hNew = CalculateH(currentNode.x + 1, currentNode.y + 1);
					fNew = gNew + hNew;

					if (nodeRecord[currentNode.x + 1][currentNode.y + 1].f == FLT_MAX ||
						nodeRecord[currentNode.x + 1][currentNode.y + 1].f > fNew)
					{
						openList.insert(std::make_pair(fNew, std::make_pair(currentNode.x + 1, currentNode.y + 1)));

						// Update the details of this cell 
						nodeRecord[currentNode.x + 1][currentNode.y + 1].f = fNew;
						nodeRecord[currentNode.x + 1][currentNode.y + 1].g = gNew;
						nodeRecord[currentNode.x + 1][currentNode.y + 1].h = hNew;
						nodeRecord[currentNode.x + 1][currentNode.y + 1].parent.x = currentNode.x;
						nodeRecord[currentNode.x + 1][currentNode.y + 1].parent.y = currentNode.y;
					}
				}
			}
		}
	}
}