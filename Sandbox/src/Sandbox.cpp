#include "Sq.hpp"

// Main Layer
class TriangleLayer : public Sq::Layer
{
public:
	TriangleLayer()
		: m_Camera(0.0f, 800.0f, 0.0f, 600.0f)
	{
	}

	void OnAttach() override
	{
		m_Shader = Sq::MakeRef<Sq::Shader>("common shader", "./assets/Shader/basic.vert", "./assets/Shader/basic.frag");
		m_Texture = Sq::MakeRef<Sq::Texture2D>();
		m_Sprite = Sq::MakeRef<Sq::Sprite>(m_Shader);

		Sq::RendererCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Sq::Renderer::Begin(m_Camera);
	}

	void OnUpdate(float dt) override
	{
		for (int y = 0; y < 600; y += 50)
		{
			for (int x = 0; x < 600; x += 50)
			{
				m_Sprite->Draw(
					m_Texture,
					img,
					glm::vec3(x, y, 0.0f),
					glm::vec2(30.0f, 30.0f),
					0.0f,
					glm::vec3(0.0f, 1.0f, 0.0f)
				);
			}
		}
	}

private:
	glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
	float speed = 0.5f;

	Sq::OrthographicCamera m_Camera;
	Sq::Ref<Sq::Shader> m_Shader;
	Sq::Ref<Sq::Texture2D> m_Texture;
	Sq::Ref<Sq::Sprite> m_Sprite;
	u32 img = Sq::Image2D::Load("./assets/Images/Circle.png");
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