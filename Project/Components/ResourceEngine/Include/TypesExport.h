#ifndef ResourceEngine_TypesExport_H
#define ResourceEngine_TypesExport_H

// Standard Includes
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <map>

// ResourceEngine Includes
#include "ResourceEngineSetup.h"

namespace ResourceEngine
{
	using FloatVector			= std::vector<float>;
	using UnsignedIntVector		= std::vector<unsigned int>;
	using UnsignedCharVector	= std::vector<unsigned char>;
	using VectorOfFloatVector	= std::vector<std::vector<float>>;
};

#endif // ResourceEngine_TypesExport_H