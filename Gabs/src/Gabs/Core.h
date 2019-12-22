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

#ifdef GABS_ENABLE_ASSERTS
	#define GAB_ASSERT(x,...) {if(!(x)){ CLIENT_LOGERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak() }}
	#define GAB_CORE_ASSERT(x,...) {if(!(x)){ CORE_LOGERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak() }}
#else
	#define GABS_ASSERT(x,...)
	#define GABS_CORE_ASSERT(x,...)
#endif

#define BIT(X) (1<<X)