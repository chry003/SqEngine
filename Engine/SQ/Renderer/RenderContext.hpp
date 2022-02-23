#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Core/Base.hpp"
#include "Core/Log.hpp"
#include "Event/Event.hpp"

namespace Sq {

	struct WindowProps
	{
		sstr Title;
		u32 Width;
		u32 Height;

		WindowProps(const sstr& title = "Sq Engine",
			        u32 width = 800,
			        u32 height = 600)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	// FixMe: change it to singleton!
	class RenderContext
	{
	public:
		using EventCallbackFn = sfun<void(Event&)>;

		static void Init(const WindowProps& props = WindowProps());
		static void Terminate();

		static void OnClear();
		static void OnUpdate();
		static void SetVSync(bool enabled);

		static inline void SetEventCallback(const EventCallbackFn& callback) { m_WindowData.EventCallback = callback; };
		static inline bool IsAlive() { return m_WindowData.Alive; }

		static void* GetNativeWindow() { return m_Window; }
		static glm::vec2 GetWindowSize() { return glm::vec2(m_WindowData.Width, m_WindowData.Height); }
		static u32 GetWidth() { return m_WindowData.Width; }
		static u32 GetHeight() { return m_WindowData.Height; }

	private:
		struct WindowData
		{
			sstr Title;
			u32 Width;
			u32 Height;

			bool Alive;
			bool VSync;

			EventCallbackFn EventCallback;
		};

	private:
		static GLFWwindow* m_Window;
		static WindowData m_WindowData;
	};

}