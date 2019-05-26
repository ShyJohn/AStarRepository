#pragma once


namespace AIFramework {

	class BaseApplication
	{
		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
		virtual void Input() = 0;

	public:

		BaseApplication() {};
		~BaseApplication() {};
	};

}