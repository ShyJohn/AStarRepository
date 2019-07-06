#include "AStarApplication.h"
#include "MenuApplication.h"
#include "NeuralNetworkApplication.h"

using namespace AIFramework;

void main()
{
	/*AppType appType;

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
	}*/

	//MenuApplication* menuApp = new MenuApplication;
	//menuApp->Run();

	NeuralNetworkApplication* NNApp = new NeuralNetworkApplication;
	NNApp->Run();

	return;
}
