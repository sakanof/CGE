#ifndef UtilitiesSetup_H
#define UtilitiesSetup_H

namespace Utilities
{
#if defined(_WIN32) || defined(__WIN32__)
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
};

#endif // UtilitiesSetup_H