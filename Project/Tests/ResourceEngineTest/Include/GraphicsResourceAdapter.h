#ifndef ResourceEngineTest_GraphicsAdapter_H
#define ResourceEngineTest_GraphicsAdapter_H

// ResourceEngine Includes
#include <ResourceEngine\Include\ResourceCache.h>
#include <ResourceEngine\Include\GraphicModelResourceData.h>

// ResourceEngineTest Includes
#include "Mesh.h"

namespace ResourceEngineTest
{
	using ResourceEngine::Resource;
	using ResourceEngine::ResourceCache;
	using ResourceEngine::Data::MeshResourceData;
	using ResourceEngine::Data::MeshNodeResourceData;
	using ResourceEngine::Data::GraphicModelResourceData;

	class GraphicsResourceAdapter
	{
	public:
		static Mesh* LoadMesh(const std::string& filepath);
	};
};

#endif // ResourceEngineTest_GraphicsAdapter_H