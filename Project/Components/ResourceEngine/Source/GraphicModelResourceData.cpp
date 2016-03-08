#include "../include/GraphicModelResourceData.h"

namespace ResourceEngine
{
	namespace Data
	{
		GraphicModelResourceData::GraphicModelResourceData(IResourceObserver* observer, SharedMeshNodeResourceData meshNode, MaterialResourceDataVector materialList)
			: IResourceData(observer), 
			  m_meshNode(meshNode),
			  m_materialList(materialList) {}
		GraphicModelResourceData::~GraphicModelResourceData() { this->m_materialList.clear(); }

		unsigned int GraphicModelResourceData::Size() const 
		{
			unsigned int mySize = 0;

			mySize += this->m_meshNode->Size();

			unsigned int materialIndex;
			for (materialIndex = 0; materialIndex < this->m_materialList.size(); ++materialIndex)
			{
				if (auto material = this->m_materialList[materialIndex].lock())
				mySize += material->Size();
			}

			return mySize;
		}
		std::string GraphicModelResourceData::Type() const { return std::string("GraphicModelResourceData"); }

		SharedMeshNodeResourceData GraphicModelResourceData::GetMeshNode(void) const { return this->m_meshNode; }
		MaterialResourceDataVector GraphicModelResourceData::GetMaterialList(void) const { return this->m_materialList; }
		WeakMaterialResourceData GraphicModelResourceData::GetMaterialByName(const std::string& materialName) const
		{
			WeakMaterialResourceData resultMaterial;

			unsigned int materialIndex;
			for (materialIndex = 0; materialIndex < this->m_materialList.size(); ++materialIndex)
			{
				if (auto currentMaterial = this->m_materialList[materialIndex].lock())
				{
					if (currentMaterial->GetName() == materialName)
						resultMaterial = currentMaterial;
				}
			}

			return resultMaterial;
		}
	};
}; 