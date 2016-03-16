#include "../Include/GraphicsResourceAdapter.h"

namespace ResourceEngineTest
{
	Mesh* GraphicsResourceAdapter::LoadMesh(const std::string& filepath)
	{
		Mesh* myResultMesh = nullptr;

		auto graphicsResource = ResourceCache::GetInstance()->GetHandle(Resource(filepath))->GetResourceData<GraphicModelResourceData>();
		auto meshResourceList = graphicsResource.lock()->GetMeshNode().lock()->GetMeshList();

		if (meshResourceList.size() > 0)
		{
			auto meshResource = meshResourceList[0];

			auto vertices = meshResource.lock()->GetVertices();
			auto colors   = meshResource.lock()->GetColors();
			auto uvs      = meshResource.lock()->UVs();

			myResultMesh = new Mesh(vertices.size()/3, vertices, colors[0], uvs[0]);
		}

		return myResultMesh;
	}
};