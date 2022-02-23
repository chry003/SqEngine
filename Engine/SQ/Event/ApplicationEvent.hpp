#pragma once

#include "Event.hpp"

namespace Sq {

	class WindowPosEvent : public Event
	{
	public:
		WindowPosEvent(int xpos, int ypos)
			: m_Xpos(xpos), m_Ypos(ypos) {}

		inline int GetXpos() const { return m_Xpos; }
		inline int GetYpos() const { return m_Ypos; }

		sstr ToString() const override
		{
			sstrs ss;

			ss << "WindowPosEvent: " << "x(" << m_Xpos << ")" << ", " << "y(" << m_Ypos << ")";

			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowPosition)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:

		int m_Xpos, m_Ypos;
	};

	class WindowSizeEvent : public Event
	{
	public:
		WindowSizeEvent(ui width, ui height)
			: m_Width(width), m_Height(height) {}

		inline ui GetWidth() const { return m_Width; }
		inline ui GetHeight() const { return m_Height; }

		sstr ToString() const override
		{
			sstrs ss;
			ss << "WindowSizeEvent: " << "width(" << m_Width << ")" << ", " << "height(" << m_Height << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowSize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		ui m_Width, m_Height;
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};

	class WindowRefreshEvent : public Event
	{
	public:
		WindowRefreshEvent(){}

		EVENT_CLASS_TYPE(WindowRefresh)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class WindowFocusedEvent : public Event
	{
	public:
		WindowFocusedEvent(int focused)
			: m_Focused(focused)
		{}

		EVENT_CLASS_TYPE(WindowFocused)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		int m_Focused;
	};

}
