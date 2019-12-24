#pragma once
#include "Core.h"
#include "Window.h"
#include <Gabs/LayerStack.h>

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


		void PushLayer(Layer* layer);

		void PushOverlayer(Layer* overlayer);


	private:
		std::unique_ptr<Window> window;
		bool running = true;
		bool OnCloseWindow(Event& e);
		LayerStack layerStack;
	};
	ChickenBehaviour* CreateApplication();

}

