#include "pch.hpp"
#include "Input.hpp"
#include "Renderer/RenderContext.hpp"

namespace Sq {

	bool Input::IsKeyPressed(KeyCode key)
	{
		auto* window = static_cast<GLFWwindow*>(RenderContext::GetNativeWindow());
		auto state = glfwGetKey(window, static_cast<int>(key));
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressed(MouseCode button)
	{
		auto* window = static_cast<GLFWwindow*>(RenderContext::GetNativeWindow());
		auto state = glfwGetMouseButton(window, static_cast<int>(button));
		return state == GLFW_PRESS;
	}
	
	glm::vec2 Input::GetMousePosition()
	{
		auto* window = static_cast<GLFWwindow*>(RenderContext::GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		
		glm::vec2 pos = {(f32)xpos, (f32)ypos};
		return pos;
	}

	f32 Input::GetMouseX()
	{
		return GetMousePosition().x;
	}

	f32 Input::GetMouseY()
	{
		return GetMousePosition().y;
	}

}