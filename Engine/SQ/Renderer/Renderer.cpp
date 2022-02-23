#include "pch.hpp"
#include "Renderer.hpp"

namespace Sq {

	Renderer::OrthographicCameraMatrix* Renderer::m_RendererElements = new Renderer::OrthographicCameraMatrix;

	void Renderer::Begin(OrthographicCamera& camera) 
	{
		m_RendererElements->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::Submit(const Ref<VertexArray>& vertexArray, const Ref<Shader>& shader)
	{
		shader->Bind();
		vertexArray->Bind();
		shader->SetMat4("u_ViewPorjectionMatrix", m_RendererElements->ViewProjectionMatrix);

		RendererCommand::Draw(vertexArray);
	}

}