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
		std::weak_ptr<ResourceDataType> GetResourceData() const
		{
			return  std::weak_ptr<ResourceDataType>(std::dynamic_pointer_cast<ResourceDataType>(this->m_resourceData));
		}
	};

	using SharedResourceHandle       = std::shared_ptr < ResourceHandle >;
	using WeakResourceHandle         = std::weak_ptr < ResourceHandle >;
	using ResourceHandleStrongVector = std::vector < std::shared_ptr<ResourceHandle> >;
	using ResourceHandleWeakVector   = std::vector < std::weak_ptr<ResourceHandle> >;
	using ResourceHandleStrongList   = std::list < std::shared_ptr<ResourceHandle> >;
	using ResourceHandleWeakList     = std::list < std::weak_ptr<ResourceHandle> >;
	using ResourceHandleStrongMap    = std::map < std::string, std::shared_ptr<ResourceHandle > >;
	using ResourceHandleWeakMap      = std::map < std::string, std::weak_ptr<ResourceHandle > >;
};

#endif // ResourceEngine_HandleResource_H