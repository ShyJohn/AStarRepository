#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Application
{
	// CAMERA
	sf::View camera;

	sf::RectangleShape r;
public:

	// Base Functions
	void Init();
	void Render();
	void Update();

	// CONSTRUCTOR
	Application(sf::RenderWindow& windowref) : window(windowref) {}
	
	// SFML WINDOW
	sf::RenderWindow& window;

};
