#pragma once

#include "Event.hpp"

namespace Sq {

    class MousePositionEvent : public Event
    {
    public:
        MousePositionEvent(f32 xpos, f32 ypos)
        : m_xpos(xpos), m_ypos(ypos)
        {

        }

        sstr ToString() const override
        {
            sstrs ss;
            ss << "MousePositionEvent: " << m_xpos << ", " << m_ypos;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MousePosition)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        f32 m_xpos, m_ypos;
    };

    class MouseButtonPressedEvent : public Event
    {
    public:

    	MouseButtonPressedEvent(int button)
    		: m_Button(button) {}

        sstr ToString() const override
        {
            sstrs ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }

    	EVENT_CLASS_TYPE(MouseButtonPressed)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
    	int m_Button;
    };

    class MouseButtonReleasedEvent : public Event
    {
    public:

    	MouseButtonReleasedEvent(int button)
    		: m_Button(button) {}

        sstr ToString() const override
        {
            sstrs ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }

    	EVENT_CLASS_TYPE(MouseButtonReleased)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
    	int m_Button;
    };

    class MouseScrollEvent : public Event
    {
    public:

    	MouseScrollEvent(f32 xoffset, f32 yoffset)
    		: m_Xoffset(xoffset), m_Yoffset(yoffset) {}


        sstr ToString() const override
        {
            sstrs ss;
            ss << "MouseScrollEvent: " << m_Xoffset << ", " << m_Yoffset;
            return ss.str();
        }

    	EVENT_CLASS_TYPE(MouseScroll)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
    	f32 m_Xoffset, m_Yoffset;
    };

}