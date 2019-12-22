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

	void ChickenBehaviour::OnEvent(Event& e)
	{
		CORE_LOGWARNING("{0}",e);
	}
	ChickenBehaviour::~ChickenBehaviour()
	{

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
			window->OnUpdate();
		}
	}


}