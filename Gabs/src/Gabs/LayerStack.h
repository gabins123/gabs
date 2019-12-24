#pragma once

#include "Core.h"
#include "Layer.h"

#include <vector>


namespace GabsEngine
{
	class GABS_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* _layer);
		void PushOverlay(Layer* _overlayer);
		void PopLayer(Layer* _layer);
		void PopOverlay(Layer* _overlayer);


		std::vector<Layer*>::iterator begin() { return layer.begin(); }
		std::vector<Layer*>::iterator end() { return layer.end(); }

	private:
		std::vector<Layer*> layer;
		std::vector<Layer*>::iterator layerInsert;
	};
}

