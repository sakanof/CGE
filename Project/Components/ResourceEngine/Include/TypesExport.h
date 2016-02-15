#ifndef ResourceEngine_TypesExport_H
#define ResourceEngine_TypesExport_H

// Standard Includes
#include <string>
#include <vector>
#include <list>
#include <memory>

// ResourceEngine Includes
#include "ResourceEngineSetup.h"

namespace ResourceEngine
{
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
	
	#define ExpliticExportType(Type) RESOURCE_ENGINE_EXP_TEMPLATE template class RESOURCE_ENGINE_API Type;

	#define ExplicitExportSharedPtr(Type) ExpliticExportType(std::shared_ptr<Type>)
	#define ExplicitExportVector(VectorType) ExpliticExportType(std::vector<VectorType>)
	#define ExplicitExportList(ListType) ExpliticExportType(std::list<ListType>)

	ExpliticExportType(std::vector<unsigned int>);
	ExpliticExportType(std::vector<unsigned char>)
	ExpliticExportType(std::vector<float>)
	ExpliticExportType(std::vector<std::vector<float>>);

	using FloatVector			= std::vector<float>;
	using UnsignedIntVector		= std::vector<unsigned int>;
	using UnsignedCharVector	= std::vector<unsigned char>;
	using VectorOfFloatVector	= std::vector<std::vector<float>>;
};

#endif // ResourceEngine_TypesExport_H