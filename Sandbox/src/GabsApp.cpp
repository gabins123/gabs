#include "Gabs.h"

class TestLayer : public GabsEngine::Layer
{
public:
	TestLayer()
		: Layer("Test")
	{
	}
	void OnUpdate() override
	{
		//CORE_LOG("T is updating");
	}
	void OnEvent(GabsEngine::Event& event) override
	{
		CORE_LOGERROR("{0}",event);
	}
};

class GabsApp : public GabsEngine::ChickenBehaviour
{
public:
	GabsApp()
	{
		PushLayer(new TestLayer());
	}
	~GabsApp()
	{

	}
};

GabsEngine::ChickenBehaviour* GabsEngine::CreateApplication()
{
	CORE_LOG("Start");
	return new GabsApp();
}