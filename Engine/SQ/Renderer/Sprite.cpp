#include "pch.hpp"
#include "Sprite.hpp"

namespace Sq {

	Sprite::Sprite(Ref<Shader> shader)
		: m_Shader(shader)
	{
		InitRenderData();
	}

	void Sprite::InitRenderData() 
	{
		BufferLayout m_BufferLayout = BufferLayout(
			{
				{ Sq::ShaderDataType::Float3, "u_Position" },
				{ Sq::ShaderDataType::Float2, "u_TexCoord" }
			}
		);

		float vertexData[9 * 4] = 
		{
			0.0f, 0.0f, 0.0f, 	0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 	0.0f, 1.0f,
			1.0f, 1.0f, 0.0f, 	1.0f, 1.0f,
			1.0f, 0.0f, 0.0f, 	1.0f, 0.0f
		};

		ui ind[6] = { 0, 1, 2, 2, 3, 0 };

		m_VAO = MakeRef<VertexArray>();
		Ref<VertexBuffer> m_VBO = MakeRef<VertexBuffer>(vertexData, sizeof(vertexData));
		Ref<IndexBuffer> m_IBO = MakeRef<IndexBuffer>(ind, sizeof(ind));

		m_VBO->SetLayout(m_BufferLayout);
		m_VAO->AddVertexBuffer(m_VBO);
		m_VAO->SetIndexBuffer(m_IBO);
	}

	void Sprite::Draw(Ref<Texture2D> texture2D, const u32& textureID, const glm::vec3& Position, const glm::vec2& Size, float Rotate, const glm::vec3& Color) 
	{
		m_Shader->Bind();
		glm::mat4 model = glm::mat4(1.0f);

		model = glm::translate(model, Position);
		model = glm::translate(model, glm::vec3(0.5f * Size.x, 0.5f * Size.y, 0.0f));
		model = glm::rotate(model, Rotate, glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::translate(model, glm::vec3(-0.5f * Size.x, -0.5f * Size.y, 0.0f));
		model = glm::scale(model, glm::vec3(Size, 1.0f));

		texture2D->Bind(textureID);

		m_Shader->SetMat4("u_ModalViewMatrix", model);
		m_Shader->SetInt("u_Texture", 0);

		Renderer::Submit(m_VAO, m_Shader);
	}

}