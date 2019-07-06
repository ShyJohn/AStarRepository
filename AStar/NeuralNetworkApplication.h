#pragma once
#include "BaseApplication.h"

namespace AIFramework
{
	class NeuralNetworkApplication : BaseApplication
	{

		void Update() override;
		void Render() override;
		void Input() override;


	public:
		void Init() override;
		void Run() override;

		NeuralNetworkApplication()
		{
			Init();
		}
		~NeuralNetworkApplication() {}
	};
}