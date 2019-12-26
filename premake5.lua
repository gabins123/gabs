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
Includedir["Glad"] = "Gabs/package/Glad/Include"
Includedir["Glad"] = "Gabs/package/Glad/Include"

include "Gabs/package/GLFW"
include "Gabs/package/Glad"

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
		"%{Includedir.GLFW}",
		"%{Includedir.Glad}"
	}
	links
	{
		"Glad",
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
			"GABS_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GABS_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "GABS_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "GABS_DIST"
		buildoptions "/MD"
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
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "GABS_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "GABS_DIST"
		buildoptions "/MD"
		optimize "On"

