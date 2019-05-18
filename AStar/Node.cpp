#include "Node.h"

void Node::SetType(GridType _type)
{
	type = _type;
	sf::Color colour = type == EMPTY ? sf::Color::White : sf::Color::Red;
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
		}
		break;
	case HOVER_EMPTY:
		colour = sf::Color(255, 255, 255, 200);
		break;
	case HOVER_WALL:
		colour = sf::Color(255, 0, 0, 200);
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