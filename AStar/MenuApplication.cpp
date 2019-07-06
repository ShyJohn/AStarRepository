#include "MenuApplication.h"

namespace AIFramework
{
	void MenuApplication::Init()
	{
		window.create(sf::VideoMode(400, 400), "Main Menu", sf::Style::Default);

		ImGui::SFML::Init(window);
	}

	void MenuApplication::Update()
	{
		Input();
		Render();
	}
	void MenuApplication::Render()
	{
		window.clear();

		// Render GUI
		
		ImGui::SFML::Render(window);

		window.display();
	}
	void MenuApplication::Input()
	{
		ImGui::SFML::Update(window, deltaClock.restart());

		// Main Menu UI
		ImGui::Begin("AI Framework");

		if (ImGui::Button("A* Application")) {
			AStarApplication* aStarApp = new AStarApplication;
			aStarApp->Run();
		}
		if (ImGui::Button("Neural Network Application")) {
			NeuralNetworkApplication* neuralNetworkApp = new NeuralNetworkApplication;
			neuralNetworkApp->Run();
		}
		ImGui::End();
	}
	void MenuApplication::Run()
	{
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				ImGui::SFML::ProcessEvent(event);

				if (event.type == sf::Event::Closed)
					window.close();
			}
			Update();
		}
	}

}