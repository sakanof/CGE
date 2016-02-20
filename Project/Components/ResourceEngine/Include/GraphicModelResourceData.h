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
			SharedMeshNodeResourceData m_meshNode;
			MaterialResourceDataVector m_materialList;

		public:
			GraphicModelResourceData(IResourceObserver* observer, SharedMeshNodeResourceData m_meshNode, MaterialResourceDataVector m_materialList);
			~GraphicModelResourceData();

		public:
			unsigned int Size() const;
			std::string  Type() const;

			SharedMeshNodeResourceData GetMeshNode(void) const;
			MaterialResourceDataVector GetMaterialList(void) const;
			SharedMaterialResourceData GetMaterialByName(const std::string& materialName) const;
		};
		ExplicitExportDataContainers(GraphicModelResourceData)

		using SharedGraphicModelResourceData = std::shared_ptr < GraphicModelResourceData >;
		using GraphicModelResourceDataVector = std::vector < std::shared_ptr<GraphicModelResourceData> >;
		using GraphicModelResourceDataList   = std::list < std::shared_ptr<GraphicModelResourceData> >;
	}; 
}; 

#endif // ResourceEngine_Data_GraphicModelResourceData_H