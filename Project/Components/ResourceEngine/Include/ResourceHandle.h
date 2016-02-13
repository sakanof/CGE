#ifndef ResourceEngine_HandleResource_H
#define ResourceEngine_HandleResource_H

// ResourceEngine Includes
#include "Resource.h"
#include "IResourceData.h"

namespace ResourceEngine
{
	class RESOURCE_ENGINE_API ResourceHandle
	{
		using IResourceData = ResourceEngine::Data::IResourceData;
	private:
		Resource       m_resource;
		IResourceData* m_resourceData;

	public:
		ResourceHandle(const Resource& myResource, IResourceData* myResourceData);

	public:
		Resource GetResource() const;
		
		template<class ResourceDataType>
		ResourceDataType* GetResourceData() const;
	};
};

#endif // ResourceEngine_HandleResource_H