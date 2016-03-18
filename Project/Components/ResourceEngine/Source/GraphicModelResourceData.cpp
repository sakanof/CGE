#include "../include/GraphicModelResourceData.h"

namespace ResourceEngine
{
	namespace Data
	{
		GraphicModelResourceData::GraphicModelResourceData(IResourceObserver* observer, SharedMeshNodeResourceData meshNode, SharedMaterialResourceDataVector materialList)
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
				mySize += this->m_materialList[materialIndex]->Size();
			}

			return mySize;
		}
		std::string GraphicModelResourceData::Type() const { return std::string("GraphicModelResourceData"); }

		WeakMeshNodeResourceData GraphicModelResourceData::GetMeshNode(void) const { return this->m_meshNode; }
		WeakMaterialResourceDataVector GraphicModelResourceData::GetMaterialList(void) const 
		{ 
			WeakMaterialResourceDataVector result;

			for (unsigned int index = 0; index < this->m_materialList.size(); ++index)
				result.push_back(std::dynamic_pointer_cast<MaterialResourceData>(this->m_materialList[index]));

			return result; 
		}
		WeakMaterialResourceData GraphicModelResourceData::GetMaterialByName(const std::string& materialName) const
		{
			WeakMaterialResourceData resultMaterial;

			unsigned int materialIndex;
			for (materialIndex = 0; materialIndex < this->m_materialList.size(); ++materialIndex)
			{
				if (this->m_materialList[materialIndex]->GetName() == materialName)
					resultMaterial = std::dynamic_pointer_cast<MaterialResourceData>(this->m_materialList[materialIndex]);
			}

			return resultMaterial;
		}
	};
}; 