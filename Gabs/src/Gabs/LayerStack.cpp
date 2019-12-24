#include "gpch.h"
#include "LayerStack.h"


namespace GabsEngine
{
	LayerStack::LayerStack()
	{
		layerInsert = layer.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* e : layer)
		{
			delete e;
		}
	}

	void LayerStack::PushLayer(Layer* _layer)
	{
		layerInsert = layer.emplace(layerInsert, _layer);
	}
	void LayerStack::PushOverlay(Layer* _overlayer)
	{
		layer.emplace_back(_overlayer);
	}
	void LayerStack::PopLayer(Layer* _layer)
	{
		auto it = std::find(layer.begin(), layer.end(), _layer);
		if(it!=layer.end())
		{
			layer.erase(it);
			layerInsert--;
		}
	}
	void LayerStack::PopOverlay(Layer* _overlayer)
	{
		auto it = std::find(layer.begin(), layer.end(), _overlayer);
		if (it != layer.end())
		{
			layer.erase(it);
		}
	}


}