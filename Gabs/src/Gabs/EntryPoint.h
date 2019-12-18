#pragma once

#ifdef GABS_PLATFORM_WINDOWS
extern ChickenBehaviour::Application* ChickenBehaviour::CreateApplication();

int main(int argc, char** argv)
{
	auto app = ChickenBehaviour::CreateApplication();
	app->Update();
	delete app;
}
#endif // GABS_PLATFORM_WINDOWS

