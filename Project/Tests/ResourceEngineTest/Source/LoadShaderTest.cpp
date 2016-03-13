#include "../Include/LoadShaderTest.h"

namespace ResourceEngineTest
{
	std::string ShaderLoader::LoadShader(const std::string path)
	{		
		std::string shaderCode = "";

		if (auto shaderResource = ResourceCache::GetInstance()->GetHandle(Resource(path))->GetResourceData<GLSLResourceData>().lock())
			shaderCode = shaderResource->GetCode();

		return shaderCode;
	}
};