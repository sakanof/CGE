#include "../Include/GraphicsResourceAdapter.h"

namespace ResourceEngineTest
{
	IRenderable* GraphicsResourceAdapter::LoadMesh(const std::string& filepath)
	{
		IndexedMesh* myResultMesh = nullptr;

		auto graphicsResource = ResourceCache::GetInstance()->GetHandle(Resource(filepath))->GetResourceData<GraphicModelResourceData>();
		auto meshResourceList = graphicsResource.lock()->GetMeshNode().lock()->GetChildren()[0].lock()->GetMeshList();

		if (meshResourceList.size() > 0)
		{
			auto meshResource = meshResourceList[0];

			auto vertices = meshResource.lock()->GetVertices();
			auto indices  = meshResource.lock()->GetIndices();
			auto colors   = meshResource.lock()->GetColors();
			auto uvs      = meshResource.lock()->UVs();

			myResultMesh = new IndexedMesh(vertices, 
                                           indices, 
										   (colors.size() > 0) ? colors[0] : std::vector<float>(),
										   (uvs.size() > 0) ? uvs[0] : std::vector<float>());
		}

		return myResultMesh;
	}
};