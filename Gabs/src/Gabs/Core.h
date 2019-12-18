#pragma once

#ifdef GABS_PLATFORM_WINDOWS
	#ifdef GABS_BUILD_DLL
		#define GABS_API __declspec(dllexport)
	#else 
		#define GABS_API __declspec(dllimport)
	#endif
#else 
	#error This engine only supports windows
#endif // DEBUG
