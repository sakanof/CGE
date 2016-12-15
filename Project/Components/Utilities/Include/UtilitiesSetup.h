#ifndef UtilitiesSetup_H
#define UtilitiesSetup_H

#if defined(_WIN32) || defined(__WIN32__)
	#ifdef UTILITIES_API_EXPORT
		#define UTILITIES_API __declspec(dllexport)
	#else
		#define UTILITIES_API __declspec(dllimport)
	#endif
#elif defined(__linux__)
	#define UTILITIES_API
#else
	#error Platform not supported...
#endif

#endif // UtilitiesSetup_H
