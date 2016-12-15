#ifndef SME_SimpleMathEngineSetup_H
#define SME_SimpleMathEngineSetup_H


#if defined(_WIN32) || defined(__WIN32__)
	#ifdef SIMPLE_MATH_ENGINE_API_EXPORT
		#define SIMPLE_MATH_ENGINE_API __declspec(dllexport)
	#else
		#define SIMPLE_MATH_ENGINE_API __declspec(dllimport)
	#endif
#elif defined(__linux__)
	#define SIMPLE_MATH_ENGINE_API
#else
	#error Platform not supported...
#endif

#endif // SME_SimpleMathEngineSetup_H
