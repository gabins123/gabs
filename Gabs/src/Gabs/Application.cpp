#include "gpch.h"

#include "Application.h"
#include "Event/ApplicationEvent.h"

#include <GLFW/glfw3.h>
namespace GabsEngine
{
	ChickenBehaviour::ChickenBehaviour()
	{
		window = std::unique_ptr<Window>(Window::Create());
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