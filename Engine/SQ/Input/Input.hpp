#pragma once

#include <glm/glm.hpp>
#include "Core/Base.hpp"
#include "KeyCodes.hpp"
#include "MouseCodes.hpp"

namespace Sq {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);
		static bool IsMouseButtonPressed(MouseCode button);

		static glm::vec2 GetMousePosition();
		static f32 GetMouseX();
		static f32 GetMouseY();
	};
}