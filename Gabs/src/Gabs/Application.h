#pragma once
#include "Core.h"
#include "Window.h"

namespace GabsEngine
{
	class GABS_API ChickenBehaviour
	{
	public:
		ChickenBehaviour();
		virtual ~ChickenBehaviour();

		void Update();
		
		void Run();

		void OnEvent(Event& e);
	private:
		std::unique_ptr<Window> window;
		bool running = true;
	};
	ChickenBehaviour* CreateApplication();

}

