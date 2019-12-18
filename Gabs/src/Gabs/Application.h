#pragma once
#include "Core.h"

namespace ChickenBehaviour
{
	class GABS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Update();
		
	};

	Application* CreateApplication();
}

