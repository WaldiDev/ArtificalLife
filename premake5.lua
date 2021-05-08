workspace "ArtificalLife"
	architecture "x64"
	startproject "AntColonyOptimization"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["SFML"] = "Vendor/SFML-2.5.1/include"

LibraryDir = {}
LibraryDir["SFML"] = "Vendor/SFML-2.5.1/lib"

project "AntColonyOptimization"
	location "AntColonyOptimization"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/Source",
		"%{IncludeDir.SFML}"
	}

	libdirs
	{
		"%{LibraryDir.SFML}"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"SFML_STATIC"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		buildoptions "/MDd"

		links
		{
			"sfml-system-s-d.lib",
			"sfml-window-s-d.lib",
			"sfml-graphics-s-d.lib",
			"opengl32.lib",
			"winmm.lib",
			"gdi32.lib",
			"freetype.lib"
		}
	
	filter "configurations:Release"
		runtime "Debug"
		optimize "on"
		buildoptions "/MD"

		links
		{
			"sfml-system-s.lib",
			"sfml-window-s.lib",
			"sfml-graphics-s.lib",
			"opengl32.lib",
			"winmm.lib",
			"gdi32.lib",
			"freetype.lib"
		}
