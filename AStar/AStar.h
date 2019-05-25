#pragma once
#include "Node.h"
#include "Helpers.h"
#include <set>
#include <utility>

namespace AIFramework
{
	//typedef pa
	struct NodeRecord
	{
		sf::Vector2i parent;
		float f, g, h;
	};

	class AStar
	{
		Node** grid;
		sf::Vector2i start;
		sf::Vector2i end;

		sf::Vector2i prevStart;
		sf::Vector2i prevEnd;

		NodeRecord nodeRecord[GRID_WIDTH][GRID_HEIGHT];

		bool IsValid( int x,  int y);
		bool IsBlocked (Node** nodesArray,  int x,  int y);
		bool IsDestination(int x, const int y);
		float CalculateH(int x, int y);
		void TracePath(int x,  int y);

		typedef std::pair<int, int> Pair;
		typedef std::pair<double, Pair> pPair;

	public:

		AStar() {
			start = sf::Vector2i(0, 0);
			end = sf::Vector2i(0, 0);
		}

		~AStar() {}

		void GeneratePath(Node** _grid);

		// Setters
		void SetStart(sf::Vector2i& _start) { start = _start; }
		void SetEnd(sf::Vector2i& _end) { end = _end; }
		void SetPrevStart(sf::Vector2i& _prevStart) { prevStart = _prevStart; }
		void SetPrevEnd(sf::Vector2i& _prevEnd) { prevEnd = _prevEnd; }

		// Getters
		sf::Vector2i GetStart() { return start; };
		sf::Vector2i GetEnd() { return end; };
		sf::Vector2i GetPrevStart() { return prevStart; }
		sf::Vector2i GetPrevEnd() { return prevEnd; }

		void SetGrid(Node** _grid) { grid = _grid; }

		std::vector<sf::Vector2i> path;

	};
}