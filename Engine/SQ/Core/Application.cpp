#include "pch.hpp"
#include "Application.hpp"

#include "Renderer/RenderContext.hpp"

namespace Sq {

    Application::Application()
    {
        RenderContext::Init();
        RenderContext::SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
        // RenderContext::SetVSync(false);
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        // dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

        // SQ_CORE_INFO("{0}", e.ToString());
        
        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
        {
            (*--it)->OnEvent(e);
            if(e.Handled())
                break;
        }
    }

    void Application::PushLayer(Layer* layer) 
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* overlay) 
    {
        m_LayerStack.PushOverlay(overlay);
        overlay->OnAttach();
    }

    void Application::Run()
    {
        timer.Init();
    	while(RenderContext::IsAlive())
        {
            RenderContext::OnClear();

            for (Layer* layer : m_LayerStack)
            {
                layer->OnUpdate(timer.DeltaTime());
            }

            RenderContext::OnUpdate();

            timer.Tick();
        }
    }

    Application::~Application()
    {
    	RenderContext::Terminate();
    }

}
