#include "../Include/MeshNodeResourceData.h"

namespace ResourceEngine
{
	namespace Data
	{
		MeshNodeResourceData::MeshNodeResourceData(IResourceObserver* observer) : IResourceData(observer) {}
		MeshNodeResourceData::~MeshNodeResourceData() 
		{
			this->m_meshList.clear();
			this->m_children.clear();
		}

		unsigned int MeshNodeResourceData::Size() const
		{
			unsigned int mySize = 0;

			unsigned int index;
			for (index = 0; index < this->m_children.size(); ++index)
			{
				mySize += this->m_children[index]->Size();
			}

			for (index = 0; index < this->m_meshList.size(); ++index)
			{
				mySize += this->m_meshList[index]->Size();
			}

			return mySize;
		}
		std::string	MeshNodeResourceData::Type() const { return std::string("MeshNodeResourceData"); }

		std::string MeshNodeResourceData::GetName() const { return this->m_name; }
		
		WeakMeshResourceDataVector MeshNodeResourceData::GetMeshList() const 
		{
			WeakMeshResourceDataVector result;

			for (unsigned int index = 0; index < this->m_meshList.size(); ++index)
				result.push_back(std::dynamic_pointer_cast<MeshResourceData>(this->m_meshList[index]));
	
			return result;
		}
		
		WeakMeshNodeResourceData MeshNodeResourceData::GetParent() const { return this->m_parent; }
		
		WeakMeshNodeResourceDataVector MeshNodeResourceData::GetChildren() const 
		{ 
			WeakMeshNodeResourceDataVector result; 

			for (unsigned int index = 0; index < this->m_children.size(); ++index)
				result.push_back(std::dynamic_pointer_cast<MeshNodeResourceData>(this->m_children[index]));

			return result;
		}

		WeakMeshNodeResourceData MeshNodeResourceData::GetNodeByName(const std::string& childName) const
		{
			WeakMeshNodeResourceData child;

			unsigned int childIndex;
			for (childIndex = 0; childIndex < this->m_children.size(); ++childIndex)
			{
				auto currentChild = this->m_children[childIndex];

				if (currentChild->GetName() == childName)
					child = std::dynamic_pointer_cast<MeshNodeResourceData>(currentChild);
				
			}

			if (child.expired())
			{
				
				for (childIndex = 0; childIndex < this->m_children.size(); ++childIndex)
				{
					auto currentChild = this->m_children[childIndex];

						child = currentChild->GetNodeByName(childName);
				}
			}

			return child;
		}

		WeakMeshResourceData MeshNodeResourceData::GetMeshByName(const std::string& meshName) const
		{
			WeakMeshResourceData mesh;

			unsigned int meshIndex;
			for (meshIndex = 0; meshIndex < this->m_meshList.size(); ++meshIndex)
			{
				auto currentMesh = this->m_meshList[meshIndex];

				if (currentMesh->GetName() == meshName)
					mesh = std::dynamic_pointer_cast<MeshResourceData>(currentMesh);
			}

			if (mesh.expired())
			{

				for (meshIndex = 0; meshIndex < this->m_children.size(); ++meshIndex)
				{
					auto currentChild = this->m_children[meshIndex];

					mesh = currentChild->GetMeshByName(meshName);
				}
			}

			return mesh;
		}

		SME::Mat4 MeshNodeResourceData::GetTransformation() const { return this->m_transformation; }

		void MeshNodeResourceData::SetName(std::string name) { this->m_name = name; }
		void MeshNodeResourceData::AddMesh(SharedMeshResourceData mesh) 
		{
			this->m_meshList.push_back(mesh);
		}
		void MeshNodeResourceData::SetParent(SharedMeshNodeResourceData parent) 
		{
			this->m_parent = parent;
		}
		void MeshNodeResourceData::AddChild(SharedMeshNodeResourceData child) 
		{
			this->m_children.push_back(child);
		}
		void MeshNodeResourceData::SetTransformation(SME::Mat4 transformation) { this->m_transformation = transformation; }
	};
};
