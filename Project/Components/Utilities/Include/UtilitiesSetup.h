#ifndef UtilitiesSetup_H
#define UtilitiesSetup_H

#include <vector>
#include <string>

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

	/**********************************************************************
	|	Provide the storage class specifier (extern for an .exe file, null
	|	for DLL) and the __declspec specifier (dllimport for .an .exe file,
	|	dllexport for DLL).
	|	You must define UTILITIES_API_EXPORT when compiling the DLL.
	|	You can now use this header file in both the .exe file and DLL - a
	|	much safer means of using common declarations than two different
	|	header files.
	**********************************************************************/
	UTILITIES_EXP_TEMPLATE template class UTILITIES_API std::basic_string<char, std::char_traits<char>, std::allocator<char>>;
};

#endif // UtilitiesSetup_H