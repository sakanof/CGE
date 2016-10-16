#ifndef ResourceEngine_IResourceCache_H
#define ResourceEngine_IResourceCache_H

// Standard Includes
#include <memory>

// ResourceEngine Includes
#include "ResourceHandle.h"
#include "IResourceLoader.h"

namespace ResourceEngine
{
	class RESOURCE_ENGINE_API IResourceCache
	{
	public:
		using Ptr		= IResourceCache*;
		using SharedPtr = std::shared_ptr<IResourceCache>;
		using WeakPtr   = std::weak_ptr<IResourceCache>;

	public:
		virtual ~IResourceCache() {}

		/**
		*	\brief Register a new loader in the cache by inserting it into the resource loader list.
		*
		*	\param The loader that will be registered.
		**/
		virtual void RegisterLoader(Loader::IResourceLoader* loader) = 0;
		
		/**
		*	\brief Gets a handle to the received resource. If the resource's already in memory it just return a shared
		*	handle to it, if not the resource will be loaded into memory and than returned in the shared handle.
		*
		*	\param The resource that is needed.
		*
		*	\return A shared resource handle that contains the resource's data.
		**/
		virtual SharedResourceHandle GetHandle(const Resource& resource) = 0;

		/**
		*	\brief Frees all the allocated resources
		**/
		virtual void Flush() = 0;
	};
};

#endif // ResourceEngine_IResourceCache_H
