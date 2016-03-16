#ifndef WindowSystemSetup_H
#define WindowSystemSetup_H

#include <string>
#include <vector>

namespace WINDOW_SYSTEM
{
#if defined(_WIN32) || defined(__WIN32__)
	#ifdef _MSC_VER
		#ifdef WINDOW_SYSTEM_API_EXPORT
			#define WINDOW_SYSTEM_API __declspec(dllexport)
			#define WINDOW_SYSTEM_EXP_TEMPLATE
		#else
			#define WINDOW_SYSTEM_API __declspec(dllimport)
			#define WINDOW_SYSTEM_EXP_TEMPLATE extern
		#endif
	#else
		#error Platform not supported...
	#endif
#elif defined(__APPLE__)
	#define SIMPLE_MATH_ENGINE_API

	#ifdef SIMPLE_MATH_ENGINE_API_EXPORT
		#define SIMPLE_MATH_ENGINE_EXP_TEMPLATE
	#else
		#define SIMPLE_MATH_ENGINE_EXP_TEMPLATE extern
	#endif
#else
	#error Platform not supported...
#endif
};

#endif // WindowSystemSetup_H