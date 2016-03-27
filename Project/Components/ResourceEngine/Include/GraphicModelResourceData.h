#ifndef ResourceEngine_Data_GraphicModelResourceData_H
#define ResourceEngine_Data_GraphicModelResourceData_H

// Standard Includes
#include <memory>

// GameEngine Includes
#include "IResourceData.h"
#include "MeshNodeResourceData.h"
#include "MaterialResourceData.h"

namespace ResourceEngine
{
	namespace Data
	{
		class RESOURCE_ENGINE_API GraphicModelResourceData : public IResourceData
		{
		public:
			typedef std::weak_ptr<GraphicModelResourceData> WeakPointer;
			typedef std::shared_ptr<GraphicModelResourceData> StrongPointer;

		private:
			SharedMeshNodeResourceData       m_meshNode;
			SharedMaterialResourceDataVector m_materialList;

		public:
			GraphicModelResourceData(IResourceObserver* observer, SharedMeshNodeResourceData m_meshNode, SharedMaterialResourceDataVector m_materialList);
			~GraphicModelResourceData();

		public:
			unsigned int Size() const;
			std::string  Type() const;

			WeakMeshNodeResourceData GetMeshNode(void) const;
			WeakMaterialResourceDataVector GetMaterialList(void) const;
			WeakMaterialResourceData GetMaterialByName(const std::string& materialName) const;
		};
		ExplicitExportDataContainers(GraphicModelResourceData)

		using SharedGraphicModelResourceData       = GraphicModelResourceData::WeakPointer;
		using WeakGraphicModelResourceData         = GraphicModelResourceData::WeakPointer;
		using SharedGraphicModelResourceDataVector = std::vector < SharedGraphicModelResourceData >;
		using WeakGraphicModelResourceDataVector   = std::vector < WeakGraphicModelResourceData >;
		using SharedGraphicModelResourceDataList   = std::list < SharedGraphicModelResourceData >;
		using WeakGraphicModelResourceDataList     = std::list < WeakGraphicModelResourceData >;
	};
}; 

#endif // ResourceEngine_Data_GraphicModelResourceData_H