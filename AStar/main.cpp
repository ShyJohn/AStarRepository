#include "Application.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Application", sf::Style::Default);

	Application app(window);

	app.Init();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		app.Update();
	}

	return 0;
}