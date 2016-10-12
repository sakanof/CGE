#ifndef WindowSystemSetup_H
#define WindowSystemSetup_H

#if defined(_WIN32) || defined(__WIN32__)
	#ifdef WINDOW_SYSTEM_API_EXPORT
		#define WINDOW_SYSTEM_API __declspec(dllexport)
	#else
		#define WINDOW_SYSTEM_API __declspec(dllimport)
	#endif
#else
	#error platform not supported...
#endif

#endif // WindowSystemSetup_H
