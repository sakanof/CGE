#ifndef ResourceEngineSetup_H
#define ResourceEngineSetup_H

#if defined(_WIN32) || defined(__WIN32__)
	#ifdef RESOURCE_ENGINE_API_EXPORT
		#define RESOURCE_ENGINE_API __declspec(dllexport)
	#else
		#define RESOURCE_ENGINE_API __declspec(dllimport)
	#endif
#else
	#error platform not supported...
#endif

#endif // ResourceEngineSetup_H
