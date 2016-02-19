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
		using SharedResourceData = ResourceEngine::Data::SharedResourceData;
	private:
		Resource			m_resource;
		SharedResourceData	m_resourceData;
		
	public:
		ResourceHandle(const Resource& myResource, IResourceData* myResourceData);
		~ResourceHandle();
	public:
		Resource GetResource() const;
		
		template<class ResourceDataType>
		std::shared_ptr<ResourceDataType> GetResourceData() const
		{
			return  std::dynamic_pointer_cast<ResourceDataType>(this->m_resourceData);
		}
	};
	ExplicitExportDataContainers(ResourceHandle)

	using SharedResourceHandle = std::shared_ptr < ResourceHandle >;
	using ResourceHandleVector = std::vector < std::shared_ptr<ResourceHandle> >;
	using ResourceHandleList   = std::list < std::shared_ptr<ResourceHandle> >;
	using ResourceHandleMap = std::map < std::string, std::shared_ptr<ResourceHandle > >;
};

#endif // ResourceEngine_HandleResource_H