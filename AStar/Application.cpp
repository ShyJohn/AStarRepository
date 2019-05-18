#include "Application.h"

void Application::Init()
{
	// INIT CAMERA
	camera.reset(sf::FloatRect(window.getSize().x, window.getSize().y, window.getSize().x, window.getSize().y));
	camera.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

	int i = 0;
	int j = 0;

	for (i = 0; i < GRID_WIDTH; i++)
	{
		for (j = 0; j < GRID_HEIGHT; j++)
		{
			r[i][j].GetRectangle().setSize(sf::Vector2f(RECTANGLE_SIZE - 1.0f, RECTANGLE_SIZE - 1.0f));
			r[i][j].GetRectangle().setPosition(sf::Vector2f(RECTANGLE_SIZE * i, RECTANGLE_SIZE * j));

			if (i == 0 || i == GRID_WIDTH - 1 || j == 0 || j == GRID_HEIGHT - 1)
				r[i][j].SetType(WALL);
			else
				r[i][j].SetType(EMPTY);
		}
	}
}

void Application::Update()
{
	Input();
	FpsCounter();

	if (sf::Mouse::getPosition(window).x <= (RECTANGLE_SIZE * (GRID_WIDTH - 1)) 
		&& sf::Mouse::getPosition(window).y <= (RECTANGLE_SIZE * (GRID_HEIGHT - 1))
		&& sf::Mouse::getPosition(window).x > 0
		&& sf::Mouse::getPosition(window).y > 0)
	{
		selectedNode.x = (int)(sf::Mouse::getPosition(window).x / RECTANGLE_SIZE);
		selectedNode.y = (int)(sf::Mouse::getPosition(window).y / RECTANGLE_SIZE);

		if (selectedNode.x != prevSelectedNode.x || selectedNode.y != prevSelectedNode.y)
		{
			switch (buildType)
			{
			case BUILD_EMPTY:
				r[selectedNode.x][selectedNode.y].SetHoverType(HOVER_EMPTY);
				break;
			case BUILD_WALL:
				r[selectedNode.x][selectedNode.y].SetHoverType(HOVER_WALL);
				break;
			case BUILD_NONE:
				r[selectedNode.x][selectedNode.y].SetHoverType(HOVER_NONE);
				break;
			}

			r[prevSelectedNode.x][prevSelectedNode.y].SetHoverType(HOVER_NONE);
			prevSelectedNode = selectedNode;
		}
		
	}

	Render();
}
void Application::Input()
{
	ImGui::SFML::Update(window, deltaClock.restart());

	char windowTitle[255] = "ImGui + SFML = <3";

	ImGui::Begin("Grid Editor");

	if (ImGui::Button("None")) {
		buildType = BUILD_NONE;
	}
	ImGui::SameLine();
	if (ImGui::Button("Wall")) {
		buildType = BUILD_WALL;
	}
	ImGui::SameLine();
	if (ImGui::Button("Empty")) {
		buildType = BUILD_EMPTY;
	}

	ImGui::End(); // end window

}
void Application::Render()
{
	
	
	window.clear();
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		for (int j = 0; j < GRID_HEIGHT; j++)
		{
			window.draw(r[i][j].GetRectangle());
		}
	}
	ImGui::SFML::Render(window);
	window.display();
}

void::Application::FpsCounter()
{
	float lastTime = 0;

	float currentTime = deltaClock.restart().asSeconds();
	float fps = 1.f / (currentTime - lastTime);
	lastTime = currentTime;

	ImGui::Begin("Info");
	ImGui::Text("FPS: %.0f", fps);
	ImGui::End();
}