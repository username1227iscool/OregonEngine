#ifndef LOG_H
#define LOG_H

#include "ogpch.h"

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Orgeng {
    class ORGENG_API Log {
    public:
        static void Init();
        static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// CLIENT LOG
#define OG_TRACE(...)  ::Orgeng::Log::GetClientLogger()->trace(__VA_ARGS__)
#define OG_INFO(...)   ::Orgeng::Log::GetClientLogger()->info(__VA_ARGS__)
#define OG_WARN(...)   ::Orgeng::Log::GetClientLogger()->warn(__VA_ARGS__)
#define OG_ERROR(...)  ::Orgeng::Log::GetClientLogger()->error(__VA_ARGS__)
#define OG_FATAL(...)  ::Orgeng::Log::GetClientLogger()->critical(__VA_ARGS__)

// core LOG
#define OG_CORE_TRACE(...)  ::Orgeng::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define OG_CORE_INFO(...)   ::Orgeng::Log::GetCoreLogger()->info(__VA_ARGS__)
#define OG_CORE_WARN(...)   ::Orgeng::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define OG_CORE_ERROR(...)  ::Orgeng::Log::GetCoreLogger()->error(__VA_ARGS__)
#define OG_CORE_FATAL(...)  ::Orgeng::Log::GetCoreLogger()->critical(__VA_ARGS__)
#endif