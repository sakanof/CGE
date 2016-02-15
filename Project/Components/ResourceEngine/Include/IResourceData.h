#ifndef ResourceEngine_IResourceData_H
#define ResourceEngine_IResourceData_H

// Standard Includes
#include <string>

// ResourceEngine Includes
#include "TypesExport.h"

namespace ResourceEngine
{
	namespace Data
	{
		#define ExplicitExportDataContainers(DataType)				\
					ExplicitExportSharedPtr(DataType)				\
					ExplicitExportVector(DataType*)					\
					ExplicitExportVector(std::shared_ptr<DataType>)	\
					ExplicitExportList(DataType*)					\
					ExplicitExportList(std::shared_ptr<DataType>)	\
					ExplicitExportMap(std::string, DataType*)		\
					ExplicitExportMap(std::string, std::shared_ptr<DataType>)

		class RESOURCE_ENGINE_API IResourceData
		{
		public:
			IResourceData() {}
			virtual ~IResourceData() {}

		public:
			/**
			*	\brief Gets the resource data type.
			*
			*	\return A string that identifies the type of resource data.
			**/
			virtual std::string  Type() const = 0;
			
			/**
			*	\brief Gets the size of the resource data.
			*
			*	\return The size of the resource data.
			**/
			virtual unsigned int Size() const = 0;
		};
		ExplicitExportDataContainers(IResourceData)

		using SharedResourceData = std::shared_ptr < IResourceData >;
		using ResourceDataVector = std::vector < std::shared_ptr<IResourceData> >;
		using ResourceDataList   = std::list < std::shared_ptr<IResourceData> >;
	}
};

#endif // ResourceEngine_IResourceData_H