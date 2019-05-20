#include "Input.h"

namespace AIFramework
{
	static Input* InputSingleton = nullptr;

	Input::Input()
	{
		InputSingleton = this;
	}

}