#ifndef ResourceEngine_IResourceData_H
#define ResourceEngine_IResourceData_H

// Standard Includes
#include <string>

// ResourceEngine Includes
#include "ResourceEngineSetup.h"

namespace ResourceEngine
{
	namespace Data
	{
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
	}
};

#endif // ResourceEngine_IResourceData_H