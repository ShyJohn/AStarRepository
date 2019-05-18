#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "imgui.h"
#include "imgui-SFML.h"

enum GridType { EMPTY, WALL };
enum HoverType { HOVER_NONE, HOVER_EMPTY, HOVER_WALL };


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

	/*bool Hover(sf::Vector2i mousePosition)
	{
		if (mousePosition.x < rectangleShape.getPosition().x) return false;
		if (mousePosition.x > (rectangleShape.getPosition().x + rectangleShape.getSize().x)) return false;
		if (mousePosition.y < rectangleShape.getPosition().y) return false;
		if (mousePosition.y > (rectangleShape.getPosition().y + rectangleShape.getSize().y)) return false;
		return true;
	}

	bool Hover(sf::Vector2i mousePosition, BuildType buildType)
	{
		if (mousePosition.x < rectangleShape.getPosition().x) return false;
		if (mousePosition.x > (rectangleShape.getPosition().x + rectangleShape.getSize().x)) return false;
		if (mousePosition.y < rectangleShape.getPosition().y) return false;
		if (mousePosition.y > (rectangleShape.getPosition().y + rectangleShape.getSize().y)) return false;

		switch (buildType)
		{
		case BUILD_EMPTY: hoverType = HOVER_EMPTY;
			break;
		case BUILD_WALL: hoverType = HOVER_WALL;
			break;
		}

		return true;
	}*/

	/*void HoverUpdate(sf::Vector2i mousePosition)
	{
		if (hoverType != prevHoverType)
		{
			if (!Hover(mousePosition))
			{
				hoverType = HOVER_NONE;
				switch (type)
				{
				case EMPTY: rectangleShape.setFillColor(sf::Color::White);
					break;
				case WALL: rectangleShape.setFillColor(sf::Color::Red);
				}
			}
			else
			{
				switch (hoverType)
				{
				case EMPTY: rectangleShape.setFillColor(sf::Color(0, 0, 0, 120));
					break;
				case WALL: rectangleShape.setFillColor(sf::Color(255, 0, 0, 120));
				}
			}
		}
	}*/
};