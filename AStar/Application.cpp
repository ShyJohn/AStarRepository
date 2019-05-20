#include "Application.h"

namespace AIFramework
{
	void Application::Init()
	{
		int i, j;

		// INIT CAMERA
		camera.reset(sf::FloatRect(window.getSize().x, window.getSize().y, window.getSize().x, window.getSize().y));
		camera.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

		buildType = BUILD_NONE;
		timer.restart();

		// Allocate memory for grid array
		node = new Node*[GRID_WIDTH];
		for (i = 0; i < GRID_WIDTH; i++)
			node[i] = new Node[GRID_HEIGHT];

		// Initialise Grid
		for (i = 0; i < GRID_WIDTH; i++)
		{
			for (j = 0; j < GRID_HEIGHT; j++)
			{
				node[i][j].GetRectangle().setSize(sf::Vector2f(RECTANGLE_SIZE - 1.0f, RECTANGLE_SIZE - 1.0f));
				node[i][j].GetRectangle().setPosition(sf::Vector2f(RECTANGLE_SIZE * i, RECTANGLE_SIZE * j));

				if (i == 0 || i == GRID_WIDTH - 1 || j == 0 || j == GRID_HEIGHT - 1)
					node[i][j].SetType(WALL);
				else
					node[i][j].SetType(EMPTY);
			}
		}

	}

	void Application::Update()
	{
		Input();
		FpsCounter();

		DetectSelectedNode();

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
				window.draw(node[i][j].GetRectangle());
			}
		}

		// Render GUI
		ImGui::SFML::Render(window);

		window.display();
	}

	void Application::Input()
	{
		ImguiInput();

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
		if (ImGui::Button("Reset Grid")) {
			ResetGrid();
		}
		if (ImGui::Button("Load Grid From File")) {
			fileHandler.LoadLevel(node);
		}
		ImGui::SameLine();
		if (ImGui::Button("Save Grid to File")) {
			fileHandler.SaveLevel(node);
		}
		if (ImGui::Button("Start Point")) {
			buildType = BUILD_START;
		}
		ImGui::SameLine();
		if (ImGui::Button("End Point")) {
			buildType = BUILD_END;
		}
		ImGui::End();
	}


	void Application::FpsCounter()
	{
		float lastTime = 0;

		float currentTime = deltaClock.restart().asSeconds();
		float fps = 1.f / (currentTime - lastTime);
		lastTime = currentTime;

		if (timer.getElapsedTime().asMilliseconds() > 100)
		{
			timer.restart();
			fpsCounter = fps;
		}
		ImGui::Begin("Info");
		ImGui::Text("FPS: %.0f", fpsCounter);
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
					node[i][j].SetType(WALL);
				else
					node[i][j].SetType(EMPTY);
			}
		}
	}

	void Application::DetectSelectedNode()
	{

		// Detect selected node using mouse position
		if (sf::Mouse::getPosition(window).x < (RECTANGLE_SIZE * (GRID_WIDTH))
			&& sf::Mouse::getPosition(window).y < (RECTANGLE_SIZE * (GRID_HEIGHT))
			&& sf::Mouse::getPosition(window).x > 0
			&& sf::Mouse::getPosition(window).y > 0)
		{
			selectedNode.x = (int)(sf::Mouse::getPosition(window).x / RECTANGLE_SIZE);
			selectedNode.y = (int)(sf::Mouse::getPosition(window).y / RECTANGLE_SIZE);

			// Highlight the selected node
			if (selectedNode.x != prevSelectedNode.x || selectedNode.y != prevSelectedNode.y)
			{
				switch (buildType)
				{
				case BUILD_EMPTY:
					node[selectedNode.x][selectedNode.y].SetHoverType(HOVER_EMPTY);
					break;
				case BUILD_WALL:
					node[selectedNode.x][selectedNode.y].SetHoverType(HOVER_WALL);
					break;
				case BUILD_NONE:
					node[selectedNode.x][selectedNode.y].SetHoverType(HOVER_NONE);
					break;
				case BUILD_START:
					node[selectedNode.x][selectedNode.y].SetHoverType(HOVER_START);
					break;
				case BUILD_END:
					node[selectedNode.x][selectedNode.y].SetHoverType(HOVER_END);
					break;
				}
				node[prevSelectedNode.x][prevSelectedNode.y].SetHoverType(HOVER_NONE);
				prevSelectedNode = selectedNode;
			}

			// Build on grid
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				switch (buildType)
				{
				case BUILD_EMPTY:
					node[selectedNode.x][selectedNode.y].SetType(EMPTY);
					break;
				case BUILD_WALL:
					node[selectedNode.x][selectedNode.y].SetType(WALL);
					break;
				case BUILD_START:
					node[selectedNode.x][selectedNode.y].SetType(START);
					node[pathfinder.getPrevStart().x][pathfinder.getPrevStart().y].SetType(EMPTY);
					pathfinder.setStart(selectedNode);
					pathfinder.setPrevStart(selectedNode);
					break;
				case BUILD_END:
					node[selectedNode.x][selectedNode.y].SetType(END);
					node[pathfinder.getPrevEnd().x][pathfinder.getPrevEnd().y].SetType(EMPTY);
					pathfinder.setEnd(selectedNode);
					pathfinder.setPrevEnd(selectedNode);
					break;
				}
			}
		}

	}
}