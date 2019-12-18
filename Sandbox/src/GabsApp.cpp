#include "Gabs.h"

class GabsApp : public ChickenBehaviour::Application
{
public:
	GabsApp()
	{

	}
	~GabsApp()
	{

	}
};

ChickenBehaviour::Application* ChickenBehaviour::CreateApplication()
{
	printf("We create a new app");
	return new GabsApp();
}