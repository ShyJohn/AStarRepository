#pragma once
#include "AStarApplication.h"
#include "NeuralNetworkApplication.h"

namespace AIFramework
{
	class MenuApplication : BaseApplication
	{
		
		void Update() override;
		void Render() override;
		void Input() override;
		

	public:
		void Init() override;
		void Run() override;

		MenuApplication()
		{
			Init();
		}
		~MenuApplication() {}
	};
}