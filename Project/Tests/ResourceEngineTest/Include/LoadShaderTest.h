#ifndef ResourceEngineTest_ShaderLoader_H
#define ResourceEngineTest_ShaderLoader_H

// Standard Includes
#include <string>

// ResourceEngine Includes
#include <ResourceEngine/Include/ResourceCache.h>

namespace ResourceEngineTest
{
	using ResourceEngine::Resource;
	using ResourceEngine::ResourceCache;
	using ResourceEngine::Data::GLSLResourceData;
	
	class ShaderLoader
	{
		public:
			static std::string LoadShader(const std::string path);
	};
};

#endif // ResourceEngineTest_ShaderLoader_H