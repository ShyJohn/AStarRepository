#include "Node.h"

void Node::SetType(GridType _type)
{
	type = _type;
	sf::Color colour;
	switch (type)
	{
	case EMPTY: colour = sf::Color::White;
		break;
	case WALL: colour = sf::Color::Red;
		break;
	case START: colour = sf::Color::Green;
		break;
	case END: colour = sf::Color::Blue;
		break;
	}
	rectangleShape.setFillColor(colour);
}

void Node::SetHoverType(HoverType _hoverType)
{
	hoverType = _hoverType;
	UpdateHover();
}

void Node::UpdateHover()
{
	sf::Color colour;
	switch (hoverType)
	{
	case HOVER_NONE:
		switch (type)
		{
		case EMPTY: colour = sf::Color::White;
			break;
		case WALL: colour = sf::Color::Red;
			break;
		case START: colour = sf::Color::Green;
			break;
		case END: colour = sf::Color::Blue;
			break;
		}
		break;
	case HOVER_EMPTY: colour = sf::Color(255, 255, 255, 200);
		break;
	case HOVER_WALL: colour = sf::Color(255, 0, 0, 200);
		break;
	case HOVER_START: colour = sf::Color(0, 255, 0, 200);
		break;
	case HOVER_END: colour = sf::Color(0, 0, 255, 200);
		break;
	}

	rectangleShape.setFillColor(colour);
}

GridType Node::GetType()
{
	return type;
}

sf::RectangleShape &Node::GetRectangle()
{
	return rectangleShape;
}