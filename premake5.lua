workspace "Gabs"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

Includedir = {}
Includedir["GLFW"] = "Gabs/package/GLFW/Include"

include "Gabs/package/GLFW"

project "Gabs"
	location "Gabs"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	pchheader "gpch.h"
	pchsource "Gabs/src/gpch.cpp"

	
	includedirs
	{
		"%{prj.name}/src",
		"Gabs/package/spdlog/include",
		"%{Includedir.GLFW}"
	}
	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GABS_PLATFORM_WINDOWS",
			"GABS_BUILD_DLL"
		}
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GABS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GABS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GABS_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Gabs/package/spdlog/include",
		"Gabs/src"
	}
	
	links
	{
		"Gabs"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GABS_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "GABS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GABS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GABS_DIST"
		optimize "On"

