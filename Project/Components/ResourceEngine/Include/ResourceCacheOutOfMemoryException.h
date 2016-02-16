#ifndef ResourceEngine_ResourceCacheOutOfMemoryException_H
#define ResourceEngine_ResourceCacheOutOfMemoryException_H

// Utilities Includes
#include <Utilities\Include\BaseException.h>

// ResourceEngine Includes
#include "ResourceEngineSetup.h"

namespace ResourceEngine
{
	class RESOURCE_ENGINE_API ResourceCacheOutOfMemoryException : public Utilities::Exception::BaseException
	{
	public:
		ResourceCacheOutOfMemoryException(std::string file, int line);
		ResourceCacheOutOfMemoryException(std::string file, int line, std::string resourcePath, __int64 missingCacheSize);
	};
	#define ThrowResourceCacheOutOfMemoryException(resourcePath, missingCacheSize) throw ResourceCacheOutOfMemoryException(__FILE__, __LINE__, resourcePath, missingCacheSize);
};

#endif // ResourceEngine_ResourceCacheOutOfMemoryException_H