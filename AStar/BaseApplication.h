#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

namespace AIFramework {

	enum AppType { ASTAR, NEURALNETWORK };

	class BaseApplication
	{
	private:

	protected:

		// Pure Virtual Functions
		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
		virtual void Input() = 0;
		virtual void Run() = 0;

		// Utility Objects
		sf::View camera;
		sf::Clock deltaClock;
		sf::Clock timer;

	public:

		// Constructor
		BaseApplication() {};
		// Destructor
		virtual ~BaseApplication() {};

		sf::RenderWindow window;
	};
}