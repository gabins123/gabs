#pragma once
#include "Event.h"

namespace GabsEngine
{
	class GABS_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float _xOffset, float _yOffset)
			: xOffset(_xOffset), yOffset(_yOffset){}
		inline float GetX() { return xOffset; }
		inline float GetY() { return yOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << xOffset << ", " << yOffset;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCatelogyMouse || EventCatelogyInput)

	private:
		float xOffset, yOffset;
	};

	class GABS_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float _xOffset, float _yOffset)
			: xOffset(_xOffset), yOffset(_yOffset) {}
		inline float GetX() { return xOffset; }
		inline float GetY() { return yOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << xOffset << ", " << yOffset;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCatelogyMouse || EventCatelogyInput)

	private:
		float xOffset, yOffset;
	};

	class GABS_API MouseButtonEvent : public Event
	{
	public:
		inline unsigned int GetButton() { return button; }
		EVENT_CLASS_CATEGORY(EventCatelogyInput | EventCatelogyMouse)

	protected:
		MouseButtonEvent(int _button)
			: button(_button) {}
		int button;
	};

	class GABS_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int _button, int repeatcount)
			: MouseButtonEvent(_button), repeatCount(repeatcount) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << button << " (" << repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);

	private:
		int repeatCount;
	};
	class GABS_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int _button)
			: MouseButtonEvent(_button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);

	};
}