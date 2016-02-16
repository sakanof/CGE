#include "../Include/ResourceLoaderNotFoundException.h"

namespace ResourceEngine
{
	ResourceLoaderNotFoundException::ResourceLoaderNotFoundException(std::string file, int line)
		: Utilities::Exception::BaseException(file, line, "Resource loader not found.") {}
	ResourceLoaderNotFoundException::ResourceLoaderNotFoundException(std::string file, int line, std::string resourceLoaderPattern)
		: Utilities::Exception::BaseException(file, line, "Resource loader for the pattern '" + resourceLoaderPattern + "'not found.") {}
};