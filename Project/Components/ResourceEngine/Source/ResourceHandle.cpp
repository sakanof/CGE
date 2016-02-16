#include "../Include/ResourceHandle.h"

namespace ResourceEngine
{
	using IResourceData = ResourceEngine::Data::IResourceData;

	ResourceHandle::ResourceHandle(const Resource& myResource, IResourceData* myResourceData, IResourceObserver* observer)
		: m_resource(myResource),
		  m_resourceData(myResourceData), 
		  m_observer(observer) {}
	ResourceHandle::~ResourceHandle()
	{
		this->m_observer->MemoryHasBeenFreed(this->m_resourceData->Size());
	}

	Resource ResourceHandle::GetResource() const { return this->m_resource; }
}