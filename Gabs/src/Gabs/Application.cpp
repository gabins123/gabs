#include "gpch.h"

#include "Application.h"
#include "Event/ApplicationEvent.h"

#include <GLFW/glfw3.h>
namespace GabsEngine
{

#define SET_EVENT_CALLBACK(x) std::bind(&ChickenBehaviour::x, this, std::placeholders::_1)

	ChickenBehaviour::ChickenBehaviour()
	{
		window = std::unique_ptr<Window>(Window::Create());
		window->SetEventCallback(SET_EVENT_CALLBACK(OnEvent));
	}
	void ChickenBehaviour::PushLayer(Layer* layer)
	{
		layerStack.PushLayer(layer);
	}
	void ChickenBehaviour::PushOverlayer(Layer* layer)
	{
		layerStack.PushOverlay(layer);
	}
	void ChickenBehaviour::OnEvent(Event& e)
	{

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowsCloseEvent>(SET_EVENT_CALLBACK(OnCloseWindow));


		for (auto it = layerStack.end(); it != layerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.handle)
				break;
		}

	}
	ChickenBehaviour::~ChickenBehaviour()
	{

	}
	bool ChickenBehaviour::OnCloseWindow(Event& e)
	{
		running = false;
		return true;
	}

	void ChickenBehaviour::Update()
	{
		while (true);
	}
	void ChickenBehaviour::Run()
	{
		while (running)
		{
			glClearColor(0, 1,1, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : layerStack)
			{
				layer->OnUpdate();
			}

			window->OnUpdate();
		}
	}


}