#include "Core.h"
#include "Log.h"

std::shared_ptr<spdlog::logger> Orgeng::Log::s_ClientLogger;

void Orgeng::Log::Init() {
    spdlog::set_pattern("%^[%Y-%m-%d %H:%M:%S] [%L] %v%$");
    s_ClientLogger = spdlog::stdout_color_mt("APP");
    s_ClientLogger->set_level(spdlog::level::trace);
}