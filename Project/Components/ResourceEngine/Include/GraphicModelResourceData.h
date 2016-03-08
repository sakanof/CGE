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
		private:
			WeakMeshNodeResourceData m_meshNode;
			WeakMaterialResourceDataVector m_materialList;

		public:
			GraphicModelResourceData(IResourceObserver* observer, WeakMeshNodeResourceData m_meshNode, WeakMaterialResourceDataVector m_materialList);
			~GraphicModelResourceData();

		public:
			unsigned int Size() const;
			std::string  Type() const;

			WeakMeshNodeResourceData GetMeshNode(void) const;
			WeakMaterialResourceDataVector GetMaterialList(void) const;
			WeakMaterialResourceData GetMaterialByName(const std::string& materialName) const;
		};
		ExplicitExportDataContainers(GraphicModelResourceData)

		using SharedGraphicModelResourceData       = std::shared_ptr < GraphicModelResourceData >;
		using WeakGraphicModelResourceData         = std::weak_ptr < GraphicModelResourceData >;
		using SharedGraphicModelResourceDataVector = std::vector < std::shared_ptr<GraphicModelResourceData> >;
		using WeakGraphicModelResourceDataVector   = std::vector < std::weak_ptr<GraphicModelResourceData> >;
		using SharedGraphicModelResourceDataList   = std::list < std::shared_ptr<GraphicModelResourceData> >;
		using WeakGraphicModelResourceDataList     = std::list < std::weak_ptr<GraphicModelResourceData> >;
	};
}; 

#endif // ResourceEngine_Data_GraphicModelResourceData_H