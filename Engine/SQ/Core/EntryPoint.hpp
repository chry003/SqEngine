#pragma once

#ifdef SQ_PLATFORM_LINUX

extern Sq::Application* Sq::CreateApplication();

int main(int argc, char** argv)
{
    Sq::Log::Init();
	SQ_CORE_WARN("Initialized Log!");
    auto app = Sq::CreateApplication();
    app->Run();
    delete app;
}

#else
    #error Squel only Support Linux!
#endif