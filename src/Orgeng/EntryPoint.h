#include "ogpch.h"

#pragma once
#include "Log.h"

#ifdef OG_PLATFORM_WINDOWS

extern Orgeng::Application* Orgeng::CreateApplication();
#include "Log.h"

int main(int argc, char** argv) {
    Orgeng::Log::Init();

    OG_INFO("Log Initalized");

    auto app = Orgeng::CreateApplication();
    app->Run();
    delete app;
}
#endif
