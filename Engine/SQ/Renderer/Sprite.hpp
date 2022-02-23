#pragma once

#include <glm/glm.hpp>

#include "Core/Base.hpp"
#include "Graphics.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "Renderer.hpp"

namespace Sq {

	class Sprite {
	public:
		Sprite(Ref<Shader> shader);
		~Sprite() {}

		void Draw(Ref<Texture2D> texture2D, const u32& textureID, const glm::vec3& Position, const glm::vec2& Size, float Rotate, const glm::vec3& Color);

	private:
		Ref<Shader> m_Shader;
		Ref<VertexArray> m_VAO;
	private:
		void InitRenderData();
	};
}