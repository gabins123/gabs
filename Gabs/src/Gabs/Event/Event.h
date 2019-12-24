#pragma once

#include "Gabs/Core.h"



namespace GabsEngine
{
	enum class EventType
	{
		None = 0,
		WindowsClose, WindowsResize, WindowsFocus, WindowsLostFocus, WindowsMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};
	enum EventCategory
	{
		None = 0,
		EventCatelogyApplication = BIT(0),
		EventCatelogyInput = BIT(1),
		EventCatelogyKeyboard = BIT(2),
		EventCatelogyMouse = BIT(3),
		EventCatelogyMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::##type;} \
								virtual EventType GetEventType() const override {return GetStaticType();}\
								virtual const char* GetName() const override {return #type;}
#define EVENT_CLASS_CATEGORY(catelogy) virtual int GetCatelogyFlags() const override {return catelogy;}

	class GABS_API Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCatelogyFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCatelogyFlags() & category;
		}
		bool handle = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& _event)
			: event(_event) {}
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (event.GetEventType() == T::GetStaticType())
			{
				event.handle = func(*(T*)&event);
				return true;
			}
			else
				return false;

		}

	private:
		Event& event;
	};
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}
