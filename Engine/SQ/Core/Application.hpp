#pragma once

#include "Base.hpp"
#include "Timer.hpp"
#include "Event/Event.hpp"
#include "Layer/LayerStack.hpp"

namespace Sq{
    class Application
    {
    public:
        Application();
        virtual ~Application();
        
        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

        void Run();
    private:
        static Application* s_Instance;
        // Timer m_Timer = Timer::GetInstance();
        LayerStack m_LayerStack;
    };
    
    Application* CreateApplication();
}