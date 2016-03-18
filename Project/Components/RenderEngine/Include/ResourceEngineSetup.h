#ifndef RenderEngineSetup_H
#define RenderEngineSetup_H

namespace RenderEngine
{
#if defined(_WIN32) || defined(__WIN32__)
	#ifdef _MSC_VER
		#ifdef RENDER_ENGINE_API_EXPORT
			#define RENDER_ENGINE_API __declspec(dllexport)
			#define RENDER_ENGINE_EXP_TEMPLATE
		#else
			#define RENDER_ENGINE_API __declspec(dllimport)
			#define RENDER_ENGINE_EXP_TEMPLATE extern
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

#endif // RenderEngineSetup_H