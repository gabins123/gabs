#pragma once
#include "Event.h"

namespace GabsEngine
{
	class GABS_API WindowsResizeEvent : public Event
	{
	public:
		WindowsResizeEvent(unsigned int _width, unsigned int _height)
			: width(_width), height(_height){}
		inline unsigned int GetWidth() { return width; }
		inline unsigned int GetHeight() { return height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowsResizeEvent: " << width << ", " << height;
			return ss.str();
		}
		EVENT_CLASS_TYPE(WindowsResize)
		EVENT_CLASS_CATEGORY(EventCatelogyApplication)
	private:
		unsigned int width, height;
	};

	class GABS_API WindowsCloseEvent : public Event
	{
	public:
		WindowsCloseEvent() { }
		EVENT_CLASS_TYPE(WindowsClose)
		EVENT_CLASS_CATEGORY(EventCatelogyApplication)
	};
	class GABS_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() { }
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCatelogyApplication)
	};
	class GABS_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() { }
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCatelogyApplication)
	};
	class GABS_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() { }
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCatelogyApplication)
	};
}