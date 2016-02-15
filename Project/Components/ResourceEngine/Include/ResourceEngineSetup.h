#ifndef ResourceEngineSetup_H
#define ResourceEngineSetup_H

namespace ResourceEngine
{
#if defined(_WIN32) || defined(__WIN32__)
	#ifdef RESOURCE_ENGINE_API_EXPORT
		#define RESOURCE_ENGINE_API __declspec(dllexport)
		#define RESOURCE_ENGINE_EXP_TEMPLATE
	#else
		#define RESOURCE_ENGINE_API __declspec(dllimport)
		#define RESOURCE_ENGINE_EXP_TEMPLATE extern
	#endif
#else
	#error Platform not supported...
#endif
};

#endif // ResourceEngineSetup_H