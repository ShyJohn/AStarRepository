#include "Application.h"

void Application::Init()
{
	// INIT CAMERA
	camera.reset(sf::FloatRect(window.getSize().x, window.getSize().y, window.getSize().x, window.getSize().y));
	camera.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

	
	// Initialise Grid
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

	// Detect selected node using mouse position
	if (sf::Mouse::getPosition(window).x < (RECTANGLE_SIZE * (GRID_WIDTH)) 
		&& sf::Mouse::getPosition(window).y < (RECTANGLE_SIZE * (GRID_HEIGHT))
		&& sf::Mouse::getPosition(window).x > 0
		&& sf::Mouse::getPosition(window).y > 0)
	{
		selectedNode.x = (int)(sf::Mouse::getPosition(window).x / RECTANGLE_SIZE);
		selectedNode.y = (int)(sf::Mouse::getPosition(window).y / RECTANGLE_SIZE);
	}

	Render();
}

void Application::Render()
{
	window.clear();

	// Render Grid
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		for (int j = 0; j < GRID_HEIGHT; j++)
		{
			window.draw(r[i][j].GetRectangle());
		}
	}

	// Render GUI
	ImGui::SFML::Render(window);

	window.display();
}

void Application::Input()
{
	ImguiInput();

	// Highlight the selected node
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

	// Build on grid
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		switch (buildType)
		{
		case BUILD_EMPTY:
			r[selectedNode.x][selectedNode.y].SetType(EMPTY);
			break;
		case BUILD_WALL:
			r[selectedNode.x][selectedNode.y].SetType(WALL);
			break;
		}
	}

}
void Application::ImguiInput()
{
	ImGui::SFML::Update(window, deltaClock.restart());

	// GUI Grid editor
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
	ImGui::SameLine();
	if (ImGui::Button("Reset Grid")) {
		ResetGrid();
	}

	ImGui::End();
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

void Application::ResetGrid()
{
	int i = 0;
	int j = 0;

	for (i = 0; i < GRID_WIDTH; i++)
	{
		for (j = 0; j < GRID_HEIGHT; j++)
		{
			if (i == 0 || i == GRID_WIDTH - 1 || j == 0 || j == GRID_HEIGHT - 1)
				r[i][j].SetType(WALL);
			else
				r[i][j].SetType(EMPTY);
		}
	}
}