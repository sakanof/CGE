#include "../Include/ResourceHandle.h"

namespace ResourceEngine
{
	using SharedResourceData = ResourceEngine::Data::SharedResourceData;

	ResourceHandle::ResourceHandle(const Resource& myResource, IResourceData* myResourceData)
		: m_resource(myResource),
		  m_resourceData(std::shared_ptr<IResourceData>(myResourceData)) {}
	ResourceHandle::~ResourceHandle() {}

	Resource ResourceHandle::GetResource() const { return this->m_resource; }
}
