#pragma once

#include "AStar.h"
#include "FileHandler.h"
#include <iostream>

namespace AIFramework
{
	enum BuildType { BUILD_NONE, BUILD_EMPTY, BUILD_WALL, BUILD_START, BUILD_END };

	class Application
	{
		// CAMERA
		sf::View camera;

		Node** node;

		AStar pathfinder;

		BuildType buildType;
		sf::Clock deltaClock;
		sf::Clock timer;

		FileHandler fileHandler;

		void Init();
		void Input();

		void ImguiInput();
		void FpsCounter();
		void ResetGrid();
		void DetectSelectedNode();

		sf::Vector2i selectedNode;
		sf::Vector2i prevSelectedNode;

		float fpsCounter;
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
}