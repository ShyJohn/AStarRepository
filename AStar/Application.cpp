#include "Application.h"

void Application::Init()
{
	// INIT CAMERA
	camera.reset(sf::FloatRect(window.getSize().x, window.getSize().y, window.getSize().x, window.getSize().y));
	camera.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

}

void Application::Update()
{
	Render();
}

void Application::Render()
{
	window.clear();

	window.display();
}