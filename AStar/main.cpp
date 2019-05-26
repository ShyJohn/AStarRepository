#include "AStarApplication.h"


using namespace AIFramework;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Application", sf::Style::Default);

	AStarApplication app(window);

	ImGui::SFML::Init(window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed)
				window.close();
		}
		app.Update();
	}

	return 0;
}
