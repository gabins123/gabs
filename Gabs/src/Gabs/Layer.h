#pragma once

#include "Core.h"
#include "Gabs/Event/Event.h"

namespace GabsEngine
{
	class GABS_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDettach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e){}

		inline const std::string& GetName() const {  return debugName; }

	protected:
		std::string debugName;
	};
}

