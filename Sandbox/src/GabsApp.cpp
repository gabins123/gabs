#include "Gabs.h"

class GabsApp : public GabsEngine::ChickenBehaviour
{
public:
	GabsApp()
	{

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