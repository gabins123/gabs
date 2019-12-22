#pragma once
#include "gpch.h"

#include "Gabs/Core.h"
#include "Gabs/event/Event.h"

namespace GabsEngine
{
	struct WindowPros
	{
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowPros(const std::string&_title = "Gabs Engine"
				,unsigned int _width=1280, unsigned int _height=720)
			:title(_title), width(_width),height(_height) {}
		
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event & e)>;
		
		virtual ~Window() {}
		
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enable) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowPros& pros = WindowPros());
	};
}