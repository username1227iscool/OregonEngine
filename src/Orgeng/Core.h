#pragma once

#ifdef OG_PLATFORM_WINDOWS
	#if OG_BUILD_DLL
		#define	ORGENG_API __declspec(dllexport)
	#else 
		#define	ORGENG_API __declspec(dllimport)
	#endif
#else 
	#error Orgeng only supports windows
#endif

#define BIT(x) (1 << x)