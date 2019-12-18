#pragma once

#ifdef GABS_PLATFORM_WINDOWS
extern GabsEngine::ChickenBehaviour* GabsEngine::CreateApplication();



int main(int argc, char** argv)
{
	GabsEngine::Log::Init();

	auto app = GabsEngine::CreateApplication();
	app->Update();
	delete app;
}
#endif // GABS_PLATFORM_WINDOWS

