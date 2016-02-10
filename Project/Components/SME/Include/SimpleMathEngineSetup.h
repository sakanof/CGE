#ifndef SME_SimpleMathEngineSetup_H
#define SME_SimpleMathEngineSetup_H


// Simple Math Engine namespace
namespace SME
{
#if defined(_WIN32) || defined(__WIN32__)
	#ifdef SIMPLE_MATH_ENGINE_API_EXPORT
		#define SIMPLE_MATH_ENGINE_API __declspec(dllexport)
		#define SIMPLE_MATH_ENGINE_EXP_TEMPLATE
	#else
		#define SIMPLE_MATH_ENGINE_API __declspec(dllimport)
		#define SIMPLE_MATH_ENGINE_EXP_TEMPLATE extern
	#endif
#else
	#error Platform not supported...
#endif
};

#endif // SME_SimpleMathEngineSetup_H
