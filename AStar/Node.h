#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "imgui.h"
#include "imgui-SFML.h"

enum GridType { EMPTY, WALL, START, END, PATH };
enum HoverType { HOVER_NONE, HOVER_EMPTY, HOVER_WALL, HOVER_START, HOVER_END };

class Node
{
	sf::RectangleShape rectangleShape;
	GridType type;
	HoverType hoverType;
public:
	Node() {
		type = EMPTY;
		hoverType = HOVER_NONE;
	};
	~Node() {};

	void SetType(GridType _type);
	void SetHoverType(HoverType _hoverType);
	void UpdateHover();
	GridType GetType();
	sf::RectangleShape &GetRectangle();
};