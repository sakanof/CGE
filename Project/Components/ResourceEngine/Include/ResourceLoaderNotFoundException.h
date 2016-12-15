#ifndef ResourceEngine_ResourceLoaderNotFoundException_H
#define ResourceEngine_ResourceLoaderNotFoundException_H

// Utilities Includes
#include <Utilities/Include/BaseException.h>

// ResourceEngine Includes
#include "ResourceEngineSetup.h"

namespace ResourceEngine
{
	class RESOURCE_ENGINE_API ResourceLoaderNotFoundException : public Utilities::Exception::BaseException
	{
	public:
		ResourceLoaderNotFoundException(std::string file, int line);
		ResourceLoaderNotFoundException(std::string file, int line, std::string resourceLoaderPattern);
	};
	#define ThrowResourceLoaderNotFoundException(resourceLoaderPattern) throw ResourceLoaderNotFoundException(__FILE__, __LINE__, resourceLoaderPattern);
};

#endif // ResourceEngine_ResourceLoaderNotFoundException_H
