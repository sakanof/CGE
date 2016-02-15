//#include "../include/GraphicModelResourceData.h"
//
//namespace ResourceManager
//{
//	namespace Data
//	{
//		GraphicModelResourceData::GraphicModelResourceData(SharedMeshNodeResourceData m_meshNode, MaterialResourceDataVector   m_materialList)
//		{
//		}
//		GraphicModelResourceData::~GraphicModelResourceData() {}
//		size_t					   GraphicModelResourceData::Size() const 
//		{
//			unsigned int mySize = 0;
//
//			mySize += this->m_meshNode->Size();
//
//			unsigned int materialIndex;
//			for (materialIndex = 0; materialIndex < this->m_materialList.size(); ++materialIndex)
//				mySize += this->m_materialList[materialIndex]->Size();
//
//			return mySize;
//		}
//		string					   GraphicModelResourceData::Type() const { return string("GraphicModelResourceData"); }
//		SharedMeshNodeResourceData GraphicModelResourceData::GetMeshNode(void) const { return this->m_meshNode; }
//		MaterialResourceDataVector   GraphicModelResourceData::GetMaterialList(void) const { return this->m_materialList; }
//
//		void GraphicModelResourceData::SetMeshNode(SharedMeshNodeResourceData node) { this->m_meshNode = node; }
//		void GraphicModelResourceData::SetMaterialList(MaterialResourceDataVector materialList) { this->m_materialList = materialList; }
//	};
//}; 