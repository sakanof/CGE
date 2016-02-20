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
				mySize += this->m_materialList[materialIndex]->Size();

			return mySize;
		}
		std::string GraphicModelResourceData::Type() const { return std::string("GraphicModelResourceData"); }

		SharedMeshNodeResourceData GraphicModelResourceData::GetMeshNode(void) const { return this->m_meshNode; }
		MaterialResourceDataVector GraphicModelResourceData::GetMaterialList(void) const { return this->m_materialList; }
		SharedMaterialResourceData GraphicModelResourceData::GetMaterialByName(const std::string& materialName) const
		{
			SharedMaterialResourceData resultMaterial(nullptr);

			auto myMaterialIterator = this->m_materialList.begin();
			auto myMaterialEnd      = this->m_materialList.end();

			for (; myMaterialIterator != myMaterialEnd && !resultMaterial; ++myMaterialIterator)
			{
				if ((*myMaterialIterator)->GetName() == materialName)
					resultMaterial = (*myMaterialIterator);
			}

			return resultMaterial;
		}
	};
}; 