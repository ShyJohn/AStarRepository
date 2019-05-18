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

	
	void Init();
	void Input();
	void ImguiInput();
	void FpsCounter();
	void ResetGrid();
	void DetectSelectedNode();

	sf::Vector2i selectedNode;
	sf::Vector2i prevSelectedNode;

public:

	

	// Base Functions
	void Render();
	void Update();
	
	// CONSTRUCTOR
	Application(sf::RenderWindow& windowref) : window(windowref) {
		Init();
	}
	~Application() {};

	// SFML WINDOW
	sf::RenderWindow& window;

};
