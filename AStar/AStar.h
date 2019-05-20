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

		NodeRecord nodeRecord[GRID_WIDTH][GRID_HEIGHT];

		std::vector<sf::Vector2i> path;

		bool IsValid(const int x, const int y);
		bool IsBlocked (Node** nodesArray, const int x, const int y);
		bool IsDestination(const int x, const int y);
		float CalculateH(const int x, const int y);
		void TracePath(const int x, const int y);

	public:

		AStar() {
			start = sf::Vector2i(0, 0);
			end = sf::Vector2i(0, 0);
		}

		~AStar() {}

		void GeneratePath(Node** _grid, sf::Vector2i _start, sf::Vector2i end);

		//// Setters
		//void SetStart(const sf::Vector2i& _start) { start = _start; }
		//void SetEnd(const sf::Vector2i& _end) { end = _end; }
		//void SetPrevStart(const sf::Vector2i& _prevStart) { prevStart = _prevStart; }
		//void SetPrevEnd(const sf::Vector2i& _prevEnd) { prevEnd = _prevEnd; }

		//// Getters
		//sf::Vector2i GetStart() const { return start; };
		//sf::Vector2i GetEnd() const { return end; };
		//sf::Vector2i GetPrevStart() const { return prevStart; }
		//sf::Vector2i GetPrevEnd() const { return prevEnd; }

		//void SetGrid(Node** _grid) { grid = _grid; }

	};
}