#include "../Include/ResourceHandle.h"

namespace ResourceEngine
{
	using IResourceData = ResourceEngine::Data::IResourceData;

	ResourceHandle::ResourceHandle(const Resource& myResource, IResourceData* myResourceData)
		: m_resource(myResource),
		  m_resourceData(myResourceData) {}

	Resource ResourceHandle::GetResource() const { return this->m_resource; }

	template<class ResourceDataType>
	ResourceDataType* ResourceHandle::GetResourceData() const
	{
		return dynamic_cast<ResourceDataType*>(this->m_resourceData);
	}
}