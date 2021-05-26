#include "NeuralNetworkApplication.h"

namespace AIFramework
{
	void NeuralNetworkApplication::Init()
	{
		window.create(sf::VideoMode(1600, 900), "Main Menu", sf::Style::Default);

		ImGui::SFML::Init(window);
	}

	void NeuralNetworkApplication::Update()
	{
		Input();
		Render();
	}
	void NeuralNetworkApplication::Render()
	{
		window.clear();

		// Render GUI

		ImGui::SFML::Render(window);

		window.display();
	}
	void NeuralNetworkApplication::Input()
	{
		ImGui::SFML::Update(window, deltaClock.restart());

		ImGui::Begin("AI Framework");

		if (ImGui::Button("Stuff")) {

		}

		ImGui::End();
	}
	void NeuralNetworkApplication::Run()
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
