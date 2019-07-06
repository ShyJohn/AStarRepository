#pragma once
#include "BaseApplication.h"
#include "AStar.h"
#include "FileHandler.h"
#include <iostream>

namespace AIFramework
{
	enum BuildType { BUILD_NONE, BUILD_EMPTY, BUILD_WALL, BUILD_START, BUILD_END };

	class AStarApplication : BaseApplication
	{
		// CAMERA
		AStar pathfinder;

		BuildType buildType;


		FileHandler fileHandler;

		void Init();
		void Input();

		void ImguiInput();
		
		void ResetGrid();
		void DetectSelectedNode();
		void FpsCounter();
		sf::Vector2i selectedNode;
		sf::Vector2i prevSelectedNode;

		float fpsCounter;

		bool leftclick;

	public:

		// Base Functions
		void Render();
		void Update();

		void Run();
		// CONSTRUCTOR
		AStarApplication() {
			Init();
		}
		~AStarApplication() {};

		// SFML WINDOW
		//sf::RenderWindow& window;

		Node** node;


	};
}