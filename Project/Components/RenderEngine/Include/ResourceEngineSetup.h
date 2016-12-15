#ifndef RenderEngineSetup_H
#define RenderEngineSetup_H

#if defined(_WIN32) || defined(__WIN32__)
	#ifdef RENDER_ENGINE_API_EXPORT
		#define RENDER_ENGINE_API __declspec(dllexport)
	#else
		#define RENDER_ENGINE_API __declspec(dllimport)
	#endif
#elif defined(__linux__)
	#define RENDER_ENGINE_API
#else
	#error Platform not supported...
#endif

#endif // RenderEngineSetup_H
