#ifndef UtilitiesSetup_H
#define UtilitiesSetup_H

#include <vector>
#include <string>

namespace Utilities
{
#if defined(_WIN32) || defined(__WIN32__)
	#ifdef _MSC_VER
		#ifdef UTILITIES_API_EXPORT
			#define UTILITIES_API __declspec(dllexport)
			#define UTILITIES_EXP_TEMPLATE
		#else
			#define UTILITIES_API __declspec(dllimport)
			#define UTILITIES_EXP_TEMPLATE extern
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

#endif // UtilitiesSetup_H