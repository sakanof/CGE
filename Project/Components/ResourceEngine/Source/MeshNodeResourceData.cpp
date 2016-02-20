#include "../include/MeshNodeResourceData.h"

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

		size_t	MeshNodeResourceData::Size() const
		{
			unsigned int mySize = 0;

			unsigned int index;
			for (index = 0; index < this->m_children.size(); ++index)
				mySize += this->m_children[index]->Size();

			for (index = 0; index < this->m_meshList.size(); ++index)
				mySize += this->m_meshList[index]->Size();

			return mySize;
		}
		std::string	MeshNodeResourceData::Type() const { return std::string("MeshNodeResourceData"); }

		std::string MeshNodeResourceData::GetName() const { return this->m_name; }
		
		MeshResourceDataVector MeshNodeResourceData::GetMeshList() const { return this->m_meshList; }
		
		SharedMeshNodeResourceData MeshNodeResourceData::GetParent() const { return this->m_parent; }
		
		MeshNodeResourceDataVector MeshNodeResourceData::GetChildren() const { return this->m_children; }

		SharedMeshNodeResourceData MeshNodeResourceData::GetChildByName(const std::string& childName) const
		{
			SharedMeshNodeResourceData child(nullptr);

			auto myChildIterator = this->m_children.begin();
			auto myChildEnd      = this->m_children.begin();
			for (; myChildIterator != myChildEnd && !child; ++myChildIterator)
			{
				if ((*myChildIterator)->GetName() == childName)
					child = (*myChildIterator);
			}

			if (!child)
			{
				myChildIterator = this->m_children.begin();
				for (; myChildIterator != myChildEnd && !child; ++myChildIterator)
					child = (*myChildIterator)->GetChildByName(childName);
			}

			return child;
		}

		SharedMeshResourceData MeshNodeResourceData::GetMeshByName(const std::string& meshName) const
		{
			SharedMeshResourceData mesh(nullptr);

			auto myMeshListIterator = this->m_meshList.begin();
			auto myMeshListEnd = this->m_meshList.end();

			for (; myMeshListIterator != myMeshListEnd && !mesh; ++myMeshListIterator)
			{
				if ((*myMeshListIterator)->GetName() == meshName)
					mesh = (*myMeshListIterator);
			}

			if (!mesh)
			{
				auto myChildIterator = this->m_children.begin();
				auto myChildEnd = this->m_children.begin();
				for (; myChildIterator != myChildEnd; ++myChildIterator)
				{
					mesh = (*myChildIterator)->GetMeshByName(meshName);
				}
			}

			return mesh;
		}

		SME::Mat4 MeshNodeResourceData::GetTransformation() const { return this->m_transformation; }

		void MeshNodeResourceData::SetName(std::string name) { this->m_name = name; }
		void MeshNodeResourceData::AddMesh(SharedMeshResourceData mesh) { this->m_meshList.push_back(mesh); }
		void MeshNodeResourceData::SetParent(SharedMeshNodeResourceData parent) { this->m_parent = parent; }
		void MeshNodeResourceData::AddChild(SharedMeshNodeResourceData child) { this->m_children.push_back(child); }
		void MeshNodeResourceData::SetTransformation(SME::Mat4 transformation) { this->m_transformation = transformation; }
	};
};