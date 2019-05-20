#pragma once
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

namespace AIFramework {

	class Input
	{

	private:
		friend class Application;

		Input();
		~Input() = default;

		bool leftButtonPressed;
	public:

		static bool GetLeftMouseButton();
		static bool GetLeftMouseButtonDown();

	};
}