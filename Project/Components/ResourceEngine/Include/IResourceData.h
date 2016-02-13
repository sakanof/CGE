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
			virtual std::string  Type() const = 0;
			virtual unsigned int Size() const = 0;
		};
	}
};

#endif // ResourceEngine_IResourceData_H