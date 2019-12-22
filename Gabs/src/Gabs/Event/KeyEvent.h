#pragma once
#include "Event.h"

namespace GabsEngine
{
	class GABS_API KeyEvent : public Event
	{
	public:
		inline unsigned int GetKey() { return keyCode; }
		EVENT_CLASS_CATEGORY(EventCatelogyInput | EventCatelogyKeyboard)
		
	protected:
		KeyEvent(int keycode)
			: keyCode(keycode) {}
		int keyCode;
	};

	class GABS_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatcount)
			: KeyEvent(keycode), repeatCount(repeatcount) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);

	private:
		int repeatCount;
	};

	class GABS_API KeyReleasdEvent : public KeyEvent
	{
	public:
		KeyReleasdEvent(int keycode)
			: KeyEvent(keycode){}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleaseEvent: " << keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);

	};


}