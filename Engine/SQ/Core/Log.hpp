#pragma once

#include "Base.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Sq {

    class Log
    {
    public:
        static void Init();

        inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define SQ_CORE_TRACE(...)    ::Sq::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SQ_CORE_INFO(...)     ::Sq::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SQ_CORE_WARN(...)     ::Sq::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SQ_CORE_ERROR(...)    ::Sq::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SQ_CORE_FATAL(...)    ::Sq::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SQ_TRACE(...)	      ::Sq::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SQ_INFO(...)	      ::Sq::Log::GetClientLogger()->info(__VA_ARGS__)
#define SQ_WARN(...)	      ::Sq::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SQ_ERROR(...)	      ::Sq::Log::GetClientLogger()->error(__VA_ARGS__)
#define SQ_FATAL(...)	      ::Sq::Log::GetClientLogger()->fatal(__VA_ARGS__)