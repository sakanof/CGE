#ifndef ResourceEngine_ResourceCache_H
#define ResourceEngine_ResourceCache_H

// ResourceEngine Includes
#include "Resource.h"
#include "IResourceData.h"
#include "ResourceHandle.h"
#include "IResourceLoader.h"
#include "GraphicModelResourceLoader.h"
#include "GLSLResourceLoader.h"
#include "ImageResourceLoader.h"
#include "ResourceLoaderNotFoundException.h"
#include "ResourceCacheOutOfMemoryException.h"

namespace ResourceEngine
{
	class RESOURCE_ENGINE_API ResourceCache : public IResourceObserver
	{
		using SharedResourceData	= Data::SharedResourceData;
		using IResourceLoader		= Loader::IResourceLoader;
		using ResourceLoaderVector	= Loader::ResourceLoaderVector;

	protected:
		__int64						m_cacheSize;			/** < The cache size in bytes. */
		__int64						m_allocatedSize;		/** < The amount of the cache that has been allocated. */
		ResourceHandleStrongList	m_leastRecentlyUsed;	/** < Track which resources are less frequently used the others. */
		ResourceHandleStrongMap		m_resourcesMap;			/** < Map used to quickly finds resources by their name. */
		ResourceLoaderVector		m_resourceLoaders;		/** < List of the registered resource loaders. */

	protected:
		ResourceCache(__int64 sizeInBytes, bool initializeDefaultLoaders);

	public:
		~ResourceCache(void);

	protected:
		/**
		*	\brief Search the given resource in the cache resource map.
		*
		*	\param resource The resource to find.
		*
		*	\return If the cache resource map contains the given resource return a handle to it, else return nullptr.
		**/
		SharedResourceHandle Find(const Resource& resource);
		
		/**
		*	\brief Loads the given resource into memory and return a handle to it.
		*
		*	\param resource The resource that will be loaded.
		*
		*	\return A handle to the loaded resource.
		**/
		SharedResourceHandle Load(const Resource& resource);
		
		/**
		*	\brief Update the least recently used list by removing the resource handle from it and adding it to the 
		*	front of the list.
		*
		*	\param The ResourceHandle that will be updated.
		**/
		void Update(SharedResourceHandle resourceHandle);
		
		/**
		*	\brief Finds a resource by its handle and removes it from the cache.
		*
		*	\param The resource that will be removed.
		**/
		void Free(SharedResourceHandle gonner);
		
		/**
		*	\brief Free some resources until the cache have enough space to allocate a new resource of the 
		*	given size.
		*
		*	\param size The size that are needed to allocate the new resource into memory.
		*
		*	\return True if it succeeded making room to the new resource or false if it did not succeed.
		**/
		bool MakeRoom(__int64 size);
		
		/**
		*	\brief Frees the least recently used resource.
		**/
		void FreeOneResource();
		
	public:
		/**
		*	\brief An observer method that is called in the ResourceHandle destructor, meaning that the reference count of a
		*	resource handle is now zero and the resource has been deleted so the cache allocated size must be decremented.
		*
		*	\param size The size that must be decremented from the cache allocated size.
		**/
		void MemoryHasBeenFreed(__int64 size);

		/**
		*	\brief Create an instance of ResourceCache.
		*
		*	\param sizeInBytes - size in bytes that the cache can allocate.
		*	\param initializeDefaultLoaders - flag to indicate if the default loaders must be initialized automatically.
		*
		*	\return instance of a ResourceCache object.
		**/
		static ResourceCache* CreateNew(__int64 sizeInBytes, bool initializeDefaultLoaders = true);

		/**
		*	\brief Insert the default loaders in the resouce loader list.
		**/
		void InitializeDefaultLoaders();

		/**
		*	\brief Register a new loader in the cache by inserting it into the resource loader list.
		*
		*	\param The loader that will be registered.
		**/
		void RegisterLoader(IResourceLoader* loader);
		
		/**
		*	\brief Gets a handle to the received resource. If the resource's already in memory it just return a shared
		*	handle to it, if not the resource will be loaded into memory and than returned in the shared handle.
		*
		*	\param The resource that is needed.
		*
		*	\return A shared resource handle that contains the resource's data.
		**/
		SharedResourceHandle GetHandle(const Resource& resource);

		/**
		*	\brief Frees all the allocated resources
		**/
		void Flush();
	};
};

#endif // ResourceEngine_ResourceCache_H
