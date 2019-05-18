#pragma once

#include "Node.h"

#include <iostream>

#define GRID_WIDTH 45
#define GRID_HEIGHT 45
#define RECTANGLE_SIZE 20

enum BuildType { BUILD_NONE, BUILD_EMPTY, BUILD_WALL };

class Application
{
	// CAMERA
	sf::View camera;

	Node r[GRID_WIDTH][GRID_HEIGHT];
	BuildType buildType;

	sf::Clock deltaClock;
	void Input();
	void FpsCounter();

	sf::Vector2i selectedNode;
	sf::Vector2i prevSelectedNode;

public:

	

	// Base Functions
	void Init();
	void Render();
	void Update();
	
	// CONSTRUCTOR
	Application(sf::RenderWindow& windowref) : window(windowref) {
		buildType = BUILD_NONE;
	}
	~Application() {};

	// SFML WINDOW
	sf::RenderWindow& window;

};
