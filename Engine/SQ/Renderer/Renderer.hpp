#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "Camera/OrthographicCamera.hpp"
#include "Graphics.hpp"
#include "Shader.hpp"

namespace Sq {

	class RendererCommand
	{
	public:
		inline static void SetClearColor(const glm::vec4& color)
		{
			glClearColor(color.r, color.g, color.b, color.a);
		}

		inline static void Draw(const Ref<VertexArray> vertexArray)
		{
			glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
		}
	};

	class Renderer
	{
	public:
		static void Begin(OrthographicCamera& camera);
		static void Submit(const Ref<VertexArray>& vertexArray, const Ref<Shader>& shader);
	private:
		struct OrthographicCameraMatrix
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static OrthographicCameraMatrix* m_RendererElements;
	};
}