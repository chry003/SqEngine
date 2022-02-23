#include "Sq.hpp"

// Main Layer
class TriangleLayer : public Sq::Layer
{
public:
	TriangleLayer()
		: m_Camera(0.0f, 4.0f, 0.0f, 6.0f)
	{
	}

	// Setup onLoad Settings
	void OnAttach() override
	{
		// Vertex Array Buffer Layout
		m_BufferLayout = Sq::BufferLayout(
			{
				{ Sq::ShaderDataType::Float3, "u_Position" },
				{ Sq::ShaderDataType::Float2, "u_TexCord" }
			}
		);

		// Common Shader
		m_Shader = Sq::MakeRef<Sq::Shader>("common shader", "./assets/Shader/basic.vert", "./assets/Shader/basic.frag");
		// Vertex Array
		m_VAO = Sq::MakeRef<Sq::VertexArray>();
		// Vertex Buffer
		m_VBO = Sq::MakeRef<Sq::VertexBuffer>(vertexData, sizeof(vertexData));
		// Index Buffer
		m_IBO = Sq::MakeRef<Sq::IndexBuffer>(ind, sizeof(ind));
		// Texture
		m_Texture = Sq::MakeRef<Sq::Texture2D>();

		// Load Image / texture (png, jpg | RGB & RGBA)
		img = m_Texture->Load("./assets/test2.jpg");

		Sq::RendererCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		m_VBO->SetLayout(m_BufferLayout);
		m_VAO->AddVertexBuffer(m_VBO);
		m_VAO->SetIndexBuffer(m_IBO);

		m_Shader->Bind();
		m_Shader->SetFloat4("u_Color", { 0.2f, 0.2f, 0.8f, 1.0f });
		m_Shader->SetInt("u_Texture", 0);
		m_Shader->Bind();
		m_Texture->Bind(img);
	}

	void OnUpdate(float dt) override
	{
		// SQ_TRACE("Sec: {0}, Ms: {1}", Sq::timer.GetSeconds(), Sq::timer.GetMilliseconds());
		Sq::Renderer::Begin(m_Camera);

		{
	        if (Sq::Input::IsKeyPressed(Sq::Key::A))
	        {
	        	pos.x += speed * (-1) * dt;
	        }
	        else if (Sq::Input::IsKeyPressed(Sq::Key::D))
	        {
	        	pos.x -= speed * (-1) * dt;
	        }
	        else if (Sq::Input::IsKeyPressed(Sq::Key::W))
	        {
	        	pos.y -= speed * (-1) * dt;
	        }
	        else if (Sq::Input::IsKeyPressed(Sq::Key::S))
	        {
	        	pos.y += speed * (-1) * dt;
	        }
		}

		// m_Camera.SetPosition(pos);
		m_Shader->SetMat4("u_ModalViewMatrix", glm::translate(glm::mat4(1.0f), pos));
		Sq::Renderer::Submit(m_VAO, m_Shader);

	}

private:
	float vertexData[5 * 4] = 
	{
		//	Vertex(3*4) 	Texture
		-0.5f, -0.5f, 0.0f,	0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
	};

	ui ind[6] = 
	{
		0, 1, 2,
		2, 3, 0
	};

	glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
	float speed = 0.5f;

	Sq::OrthographicCamera m_Camera;
	Sq::BufferLayout m_BufferLayout;
	Sq::Ref<Sq::Shader> m_Shader;
	Sq::Ref<Sq::Texture2D> m_Texture;
	Sq::Ref<Sq::VertexArray> m_VAO;
	Sq::Ref<Sq::VertexBuffer> m_VBO;
	Sq::Ref<Sq::IndexBuffer> m_IBO;

	u32 img;
};

class Sandbox : public Sq::Application
{
public:
    Sandbox()
    {
    	PushOverlay(new TriangleLayer());
    }
    ~Sandbox()
    {
        
    }
};

Sq::Application* Sq::CreateApplication()
{
    return new Sandbox();
}