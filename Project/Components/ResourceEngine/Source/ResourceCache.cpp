#include "../include/ResourceCache.h"

namespace ResourceEngine
{
	ResourceCache* ResourceCache::m_instance = nullptr;
	ResourceCache::ResourceCache(__int64 sizeInBytes, bool initializeDefaultLoaders)
		: m_cacheSize(sizeInBytes),
		  m_allocatedSize(0)
	{
		if (initializeDefaultLoaders)
			InitializeDefaultLoaders();
	}
	ResourceCache::~ResourceCache(void) {}

	SharedResourceHandle ResourceCache::Find(const Resource& resource)
	{
		SharedResourceHandle result(nullptr);

		ResourceHandleStrongMap::iterator it = this->m_resourcesMap.find(resource.GetFilePath());
		if (it != this->m_resourcesMap.end())
			result = it->second;

		return result;
	}

	SharedResourceHandle ResourceCache::Load(const Resource& resource)
	{
		IResourceLoader* loader	= nullptr;

		auto currentLoader    = this->m_resourceLoaders.begin();
		auto endOfLoadersfMap = this->m_resourceLoaders.end();
		auto pattern		  = resource.GetFileExtension();
		for (; currentLoader != endOfLoadersfMap && loader != nullptr; ++currentLoader)
		{
			if ((*currentLoader)->IsPatternAccepted(pattern))
				loader = *currentLoader;
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

	void ResourceCache::Update(SharedResourceHandle resourceHandle)
	{
		this->m_leastRecentlyUsed.remove(resourceHandle);
		this->m_leastRecentlyUsed.push_front(resourceHandle);
	}

	void ResourceCache::Free(SharedResourceHandle gonner)
	{
		this->m_leastRecentlyUsed.remove(gonner);
		this->m_resourcesMap.erase(gonner->GetResource().GetFilePath());	
	}

	bool ResourceCache::MakeRoom(__int64 size)
	{
		if (size > this->m_cacheSize)
		{
			throw Utilities::Exception::BaseException(__FILE__, __LINE__, "Error on ResourceCache::MakeRoom method, trying make room for a resource that is greater then the cache's size.");
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

	void ResourceCache::FreeOneResource()
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

	void ResourceCache::MemoryHasBeenFreed(__int64 size)
	{
		if (m_allocatedSize >= size)
			this->m_allocatedSize -= size;
		else
			throw Utilities::Exception::BaseException(__FILE__, __LINE__, "Error on ResourceCache::MemoryHasBeenFreed method, the freed size is greater then the cache's size.");
	}
	
	ResourceCache* ResourceCache::GetInstance()
	{
		if (nullptr == m_instance)
			throw Utilities::Exception::BaseException(__FILE__, __LINE__, "Error on ResourceCache::GetInstance method, ResourceCache has not been initialized yet.");

		return m_instance;
	}

	void ResourceCache::Initialize(__int64 sizeInBytes, bool initializeDefaultLoaders)
	{
		if (nullptr == m_instance)
			m_instance = new ResourceCache(sizeInBytes, initializeDefaultLoaders);
		else
			throw Utilities::Exception::BaseException(__FILE__, __LINE__, "Error on ResourceCache::Initialize method, ResourceCache already initialized. Finalize the current instance and then iniatilize a new one.");
	}
	
	void ResourceCache::Finalize()
	{
		m_instance->Flush();

		for (unsigned loaderIndex = 0; loaderIndex < m_instance->m_resourceLoaders.size(); ++loaderIndex)
			Utilities::Memory::SafeDelete(m_instance->m_resourceLoaders.at(loaderIndex));

		Utilities::Memory::SafeDelete(m_instance);
	}
	
	void ResourceCache::InitializeDefaultLoaders() 
	{
		this->m_resourceLoaders.push_back(new Loader::Offline::GLSLResourceLoader(this));
		this->m_resourceLoaders.push_back(new Loader::Offline::ImageResourceLoader(this));
		this->m_resourceLoaders.push_back(new Loader::Offline::GraphicModelResourceLoader(this));
	}
	
	void ResourceCache::RegisterLoader(IResourceLoader* loader) { this->m_resourceLoaders.push_back(loader); }
	
	SharedResourceHandle ResourceCache::GetHandle(const Resource& resource)
	{
		SharedResourceHandle handle(Find(resource));

		if (handle == nullptr)
			handle = Load(resource);
		else
			Update(handle);

		return handle;
	}

	void ResourceCache::Flush()
	{
		while (!this->m_leastRecentlyUsed.empty())
		{
			auto handle = this->m_leastRecentlyUsed.begin();
			Free(*handle);
		}
	}
};