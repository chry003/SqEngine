#pragma once

#include "Event.hpp"

namespace Sq {

	class KeyPressedEvent : public Event
	{
	public:
		KeyPressedEvent(int key, int count)
			: m_Key(key), m_Count(count) {}

		sstr ToString() const override
		{
			sstrs ss;
			ss << "KeyPressedEvent: " << "key(" << m_Key << ") " << "repeat(" << m_Count << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	private:
		int m_Key, m_Count;
	};

	class KeyReleasedEvent : public Event
	{
	public:
		KeyReleasedEvent(int key)
			: m_Key(key) {}

		sstr ToString() const override
		{
			sstrs ss;
			ss << "KeyReleasedEvent: " << "key(" << m_Key << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	private:
		int m_Key;
	};
}