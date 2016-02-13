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

	/**********************************************************************
	|	Provide the storage class specifier (extern for an .exe file, null
	|	for DLL) and the __declspec specifier (dllimport for .an .exe file,
	|	dllexport for DLL).
	|	You must define UTILITIES_API_EXPORT when compiling the DLL.
	|	You can now use this header file in both the .exe file and DLL - a
	|	much safer means of using common declarations than two different
	|	header files.
	**********************************************************************/
	RESOURCE_ENGINE_EXP_TEMPLATE template class RESOURCE_ENGINE_API std::basic_string<char, std::char_traits<char>, std::allocator<char>>;
};

#endif // ResourceEngineSetup_H