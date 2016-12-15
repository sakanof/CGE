#ifndef ResourceEngine_Data_MeshNodeResourceData_H
#define ResourceEngine_Data_MeshNodeResourceData_H

// SME Includes
#include <SME/Include/SME.h>

// GameEngine Includes
#include "MeshResourceData.h"

namespace ResourceEngine
{
	namespace Data
	{
		class RESOURCE_ENGINE_API MeshNodeResourceData;

		using SharedMeshNodeResourceData       = std::shared_ptr < MeshNodeResourceData >;
		using WeakMeshNodeResourceData	       = std::weak_ptr < MeshNodeResourceData >;
		using SharedMeshNodeResourceDataVector = std::vector < std::shared_ptr<MeshNodeResourceData> >;
		using WeakMeshNodeResourceDataVector   = std::vector < std::weak_ptr<MeshNodeResourceData> >;
		using SharedMeshNodeResourceDataList   = std::list < std::shared_ptr<MeshNodeResourceData> >;
		using WeakMeshNodeResourceDataList     = std::list < std::weak_ptr<MeshNodeResourceData> >;

		class RESOURCE_ENGINE_API MeshNodeResourceData : public IResourceData
		{
		public:
			typedef std::weak_ptr<MeshNodeResourceData> WeakPointer;
			typedef std::shared_ptr<MeshNodeResourceData> StrongPointer;

		private:
			std::string                      m_name;
			
			SharedMeshResourceDataVector     m_meshList;
			
			WeakMeshNodeResourceData         m_parent;
			
			SharedMeshNodeResourceDataVector m_children;

			SME::Mat4					     m_transformation;

		public:
			MeshNodeResourceData(IResourceObserver* observer);
			~MeshNodeResourceData();

		public:
			unsigned int Size() const;
			std::string	 Type() const;

			std::string GetName() const;
			
			WeakMeshResourceDataVector GetMeshList() const;
			
			WeakMeshNodeResourceData GetParent() const;
			
			WeakMeshNodeResourceDataVector GetChildren() const;
			
			WeakMeshNodeResourceData GetNodeByName(const std::string& childName) const;

			WeakMeshResourceData GetMeshByName(const std::string& meshName) const;

			SME::Mat4 GetTransformation() const;

			void SetName(std::string name);
			void AddMesh(SharedMeshResourceData mesh);
			void SetParent(SharedMeshNodeResourceData parent);
			void AddChild(SharedMeshNodeResourceData child);
			void SetTransformation(SME::Mat4 transformation);
		};
	};
};

#endif // ResourceEngine_Data_MeshNodeResourceData_H
