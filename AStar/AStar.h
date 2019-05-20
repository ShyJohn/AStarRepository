#pragma once
#include "Node.h"

namespace AIFramework
{
	class AStar
	{

		sf::Vector2i start;
		sf::Vector2i end;

		sf::Vector2i prevStart;
		sf::Vector2i prevEnd;

	public:

		AStar() {
			start = sf::Vector2i(0, 0);
			end = sf::Vector2i(0, 0);
			prevStart = sf::Vector2i(0, 0);
			prevEnd = sf::Vector2i(0, 0);
		}

		~AStar() {}

		// Setters
		void setStart(const sf::Vector2i& _start) { start = _start; }
		void setEnd(const sf::Vector2i& _end) { end = _end; }
		void setPrevStart(const sf::Vector2i& _prevStart) { prevStart = _prevStart; }
		void setPrevEnd(const sf::Vector2i& _prevEnd) { prevEnd = _prevEnd; }

		// Getters
		sf::Vector2i getStart() const { return start; };
		sf::Vector2i getEnd() const { return end; };
		sf::Vector2i getPrevStart() const { return prevStart; }
		sf::Vector2i getPrevEnd() const { return prevEnd; }

	};
}