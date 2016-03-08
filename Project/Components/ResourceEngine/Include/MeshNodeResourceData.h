#ifndef ResourceEngine_Data_MeshNodeResourceData_H
#define ResourceEngine_Data_MeshNodeResourceData_H

// SME Includes
#include <SME\Include\SME.h>

// GameEngine Includes
#include "MeshResourceData.h"

namespace ResourceEngine
{
	namespace Data
	{
		class RESOURCE_ENGINE_API MeshNodeResourceData;

		ExplicitExportDataContainers(MeshNodeResourceData)

		using SharedMeshNodeResourceData = std::shared_ptr < MeshNodeResourceData >;
		using MeshNodeResourceDataVector = std::vector < std::shared_ptr<MeshNodeResourceData> >;
		using MeshNodeResourceDataList   = std::list < std::shared_ptr<MeshNodeResourceData> >;

		class RESOURCE_ENGINE_API MeshNodeResourceData : public IResourceData
		{
		private:
			std::string					m_name;
			
			MeshResourceDataVector		m_meshList;
			
			SharedMeshNodeResourceData	m_parent;
			
			MeshNodeResourceDataVector	m_children;

			SME::Mat4					m_transformation;

		public:
			MeshNodeResourceData(IResourceObserver* observer);
			~MeshNodeResourceData();

		public:
			unsigned int Size() const;
			std::string	 Type() const;

			std::string GetName() const;
			
			MeshResourceDataVector GetMeshList() const;
			
			SharedMeshNodeResourceData GetParent() const;
			
			MeshNodeResourceDataVector GetChildren() const;
			
			SharedMeshNodeResourceData GetNodeByName(const std::string& childName) const;

			WeakMeshResourceData GetMeshByName(const std::string& meshName) const;

			SME::Mat4 GetTransformation() const;

			void SetName(std::string name);
			void AddMesh(WeakMeshResourceData mesh);
			void SetParent(SharedMeshNodeResourceData parent);
			void AddChild(SharedMeshNodeResourceData child);
			void SetTransformation(SME::Mat4 transformation);
		};
	};
};

#endif // ResourceEngine_Data_MeshNodeResourceData_H