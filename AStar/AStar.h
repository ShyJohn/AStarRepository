#pragma once
#include "Node.h"

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
	void setStart(sf::Vector2i _start) { start = _start; }
	void setEnd(sf::Vector2i _end) { end = _end; }
	void setPrevStart(sf::Vector2i _prevStart) { prevStart = _prevStart; }
	void setPrevEnd(sf::Vector2i _prevEnd) { prevEnd = _prevEnd; }

	// Getters
	sf::Vector2i getStart() { return start; };
	sf::Vector2i getEnd() { return end; };
	sf::Vector2i getPrevStart() { return prevStart; }
	sf::Vector2i getPrevEnd() { return prevEnd; }

};