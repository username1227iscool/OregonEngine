workspace "Orgeng"
    architecture "x64"
    startproject "Sandbox"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Orgeng/vendor/GLFW/include"
IncludeDir["Glad"] = "Orgeng/vendor/Glad/include"

include "Orgeng/vendor/GLFW"
include "Orgeng/vendor/Glad"

project "Orgeng"
    location "Orgeng"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/Orgeng")
    objdir ("bin-int/" .. outputdir .. "/Orgeng")

     pchheader "ogpch.h"
    pchsource "src/Orgeng/ogpch.cpp"

        files
        {
            "src/Orgeng/**",
        }

    includedirs
    {
        "Orgeng/vendor/spdlog/include",
        "C:/Orgeng/src",
        "C:/Orgeng/src/Orgeng",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}"
    }

    links
    {
        "GLFW",
        "Glad",
        "opengl32",
        "gdi32",
        "user32",
        "shell32"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "Off"
        systemversion "latest"
        defines
        {
            "OG_PLATFORM_WINDOWS",
            "OG_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }
        postbuildcommands
        {
            ("{MKDIR} ../bin/" .. outputdir .. "/SandBox"),
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
        }

    filter "configurations:Debug"
        defines "OG_DEBUG"
        symbols "On"
        buildoptions "/MDd"

    filter "configurations:Release"
        defines "OG_RELEASE"
        optimize "On"
        buildoptions "/MD"

    filter "configurations:Dist"
        defines "OG_DIST"
        optimize "On"
        buildoptions "/MD"

project "Sandbox"
    location "SandBox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/Sandbox")
    objdir ("bin-int/" .. outputdir .. "/Sandbox")

    files
    {
        "../SandBox/src/**.h",
        "../SandBox/src/**.cpp"
    }

    includedirs
    {
        "Orgeng/vendor/spdlog/include",
        "src"
    }

    links
    {
        "Orgeng"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        defines
        {
            "OG_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "OG_DEBUG"
        symbols "On"
        buildoptions "/MDd"

    filter "configurations:Release"
        defines "OG_RELEASE"
        optimize "On"
        buildoptions "/MD"

    filter "configurations:Dist"
        defines "OG_DIST"
        optimize "On"
        buildoptions "/MD"