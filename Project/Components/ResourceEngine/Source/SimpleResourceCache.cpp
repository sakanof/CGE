#include "../include/SimpleResourceCache.h"

namespace ResourceEngine
{
	SimpleResourceCache::SimpleResourceCache(__int64 sizeInBytes, bool initializeDefaultLoaders)
		: m_cacheSize(sizeInBytes),
		  m_allocatedSize(0)
	{
		if (initializeDefaultLoaders)
			InitializeDefaultLoaders();
	}
	SimpleResourceCache::~SimpleResourceCache(void)
	{
		while (!this->m_resourceLoaders.empty())
		{
			auto loader = this->m_resourceLoaders.back();
			this->m_resourceLoaders.pop_back();
			
			Utilities::Memory::SafeDelete(loader);
		}

		this->Flush();
	}

	SharedResourceHandle SimpleResourceCache::Find(const Resource& resource)
	{
		SharedResourceHandle result(nullptr);

		ResourceHandleStrongMap::iterator it = this->m_resourcesMap.find(resource.GetFilePath());
		if (it != this->m_resourcesMap.end())
			result = it->second;

		return result;
	}

	SharedResourceHandle SimpleResourceCache::Load(const Resource& resource)
	{
		IResourceLoader* loader	= nullptr;

		bool foundLoader = false;
		for (unsigned int index = 0; index < this->m_resourceLoaders.size() && !foundLoader; ++index)
		{
			if (this->m_resourceLoaders[index]->IsPatternAccepted(resource.GetFileExtension()))
			{	
				foundLoader = true;
				loader      = this->m_resourceLoaders[index];
			}
		}


		if (loader == nullptr)
			ThrowResourceLoaderNotFoundException(resource.GetFileExtension())

		auto rawResourceSize = loader->GetRawResourceSize(resource);
		auto myFreeSpace     = (this->m_cacheSize - this->m_allocatedSize);
		if (rawResourceSize > myFreeSpace)
		{
			auto missingSpace = rawResourceSize - myFreeSpace;
			ThrowResourceCacheOutOfMemoryException(resource.GetFilePath(), missingSpace)
		}
		auto resourceData      = loader->Load(resource);
		this->m_allocatedSize += resourceData->Size();
		auto resourceHandle    = std::make_shared<ResourceHandle>(resource, std::move(resourceData));

		this->m_leastRecentlyUsed.push_front(resourceHandle);
		this->m_resourcesMap[resource.GetFilePath()] = resourceHandle;

		return resourceHandle;
	}

	void SimpleResourceCache::Update(SharedResourceHandle resourceHandle)
	{
		this->m_leastRecentlyUsed.remove(resourceHandle);
		this->m_leastRecentlyUsed.push_front(resourceHandle);
	}

	void SimpleResourceCache::Free(SharedResourceHandle gonner)
	{
		this->m_leastRecentlyUsed.remove(gonner);
		this->m_resourcesMap.erase(gonner->GetResource().GetFilePath());	
	}

	bool SimpleResourceCache::MakeRoom(__int64 size)
	{
		if (size > this->m_cacheSize)
		{
			throw Utilities::Exception::BaseException(__FILE__, __LINE__, "Error on SimpleResourceCache::MakeRoom method, trying to make room for a resource that is greater then the cache's size.");
		}
		else
		{
			bool isEmpty = false;
		
			while (size > (this->m_cacheSize - this->m_allocatedSize) && !isEmpty)
			{
				if (this->m_leastRecentlyUsed.empty())
					isEmpty = true;
				else
					FreeOneResource();
			}

			return !isEmpty;
		}
	}

	void SimpleResourceCache::FreeOneResource()
	{
		SharedResourceHandle resourceHandleToDelete = *(--this->m_leastRecentlyUsed.end());
		bool foundResourceToBeFreed					= false;
		auto ResourceHandleStrongListReverseEnd			= this->m_leastRecentlyUsed.rend();
		
		// Searches for the least recently used resource that have the least reference count to it.
		for (auto handleIterator = this->m_leastRecentlyUsed.rbegin(); handleIterator != ResourceHandleStrongListReverseEnd && !foundResourceToBeFreed; ++handleIterator)
		{
			if (handleIterator->unique())
			{
				resourceHandleToDelete = *handleIterator;
				foundResourceToBeFreed = true;
			}
			else if (handleIterator->use_count() < resourceHandleToDelete.use_count())
			{
				resourceHandleToDelete = *handleIterator;
			}
		}

		this->m_leastRecentlyUsed.remove(resourceHandleToDelete);
	}

	void SimpleResourceCache::MemoryHasBeenFreed(__int64 size)
	{
		if (m_allocatedSize >= size)
			this->m_allocatedSize -= size;
		else
			throw Utilities::Exception::BaseException(__FILE__, __LINE__, "Error on SimpleResourceCache::MemoryHasBeenFreed method, the freed size is greater then the cache's size.");
	}
	
	SimpleResourceCache* SimpleResourceCache::CreateNew(__int64 sizeInBytes, bool initializeDefaultLoaders)
	{
		return new SimpleResourceCache(sizeInBytes, initializeDefaultLoaders);
	}

	void SimpleResourceCache::InitializeDefaultLoaders() 
	{
		this->m_resourceLoaders.push_back(new Loader::Offline::GLSLResourceLoader(this));
		this->m_resourceLoaders.push_back(new Loader::Offline::ImageResourceLoader(this));
		this->m_resourceLoaders.push_back(new Loader::Offline::GraphicModelResourceLoader(this, this));
	}
	
	void SimpleResourceCache::RegisterLoader(IResourceLoader* loader) { this->m_resourceLoaders.push_back(loader); }
	
	SharedResourceHandle SimpleResourceCache::GetHandle(const Resource& resource)
	{
		SharedResourceHandle handle(Find(resource));

		if (handle == nullptr)
			handle = Load(resource);
		else
			Update(handle);

		return handle;
	}

	void SimpleResourceCache::Flush()
	{
		while (!this->m_leastRecentlyUsed.empty())
		{
			auto handle = this->m_leastRecentlyUsed.begin();
			Free(*handle);
		}
	}
};
