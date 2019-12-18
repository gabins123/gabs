#pragma once
#include "Core.h"

namespace GabsEngine
{
	class GABS_API ChickenBehaviour
	{
	public:
		ChickenBehaviour();
		virtual ~ChickenBehaviour();

		void Update();
		
	};

	ChickenBehaviour* CreateApplication();

}

