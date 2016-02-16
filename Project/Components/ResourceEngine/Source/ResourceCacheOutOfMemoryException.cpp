#include "../Include/ResourceCacheOutOfMemoryException.h"

namespace ResourceEngine
{
	ResourceCacheOutOfMemoryException::ResourceCacheOutOfMemoryException(std::string file, int line)
		: Utilities::Exception::BaseException(file, line, "Could not load the requested resource, ResourceCache is out of memory.") {}
	ResourceCacheOutOfMemoryException::ResourceCacheOutOfMemoryException(std::string file, int line, std::string resourcePath, __int64 missingCacheSize)
		: Utilities::Exception::BaseException(file, line, "Could not load the rerouce '" + resourcePath + "', ResourceCache is out of memory. Missing " + std::to_string(missingCacheSize) + " bytes to alocate the requested resource.") {}
};