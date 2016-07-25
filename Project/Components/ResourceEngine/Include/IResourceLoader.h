#ifndef ResourceEngine_IResourceLoader_H
#define ResourceEngine_IResourceLoader_H

// Standard Includes
#include <string>

// ResourceEngine Includes
#include "Resource.h"
#include "IResourceData.h"
#include "IResourceObserver.h"

namespace ResourceEngine
{
	namespace Loader
	{
		using IResourceData = Data::IResourceData;

		class RESOURCE_ENGINE_API IResourceLoader
		{
		protected:
			IResourceObserver* m_resourceObserver;
		public:
			IResourceLoader(IResourceObserver* resourceObserve) : m_resourceObserver(resourceObserve) {}
			virtual ~IResourceLoader() {}

		public:
			/**
			*	\brief Gets the pattern (i.e. file extension, reource type) that the loader accepts.
			*
			*	\return A string describing the pattern accepted by the loader.
			**/
			virtual std::string  Pattern() const = 0;
			
			/**
			*	\brief Verifies if the received pattern is accepted by the loader.
			*
			*	\param pattern The pattern that will be validated.
			*
			*	\return True if the pattern is accepted by the loader and false if not.
			**/
			virtual bool IsPatternAccepted(const std::string pattern) const = 0;
			
			/**
			*	\brief Gets the raw size of the resource content.
			*
			*	\param resource The resource that the raw will be returned.
			*
			*	\return The size of the raw content of the resource.
			**/
			virtual __int64 GetRawResourceSize(const Resource& resource) const = 0;
			
			/**
			*	\brief Loads that resource content into a IResourceData object.
			*
			*	\param resource The resource that will be loaded.
			*
			*	\return A IResourceData object containing the loaded content.
			**/
			virtual IResourceData* Load(const Resource& resource) = 0;
		};

		using ResourceLoaderVector = std::vector < IResourceLoader* >;
		using ResourceLoaderList   = std::vector < IResourceLoader* >;
	}
};

#endif // ResourceEngine_IResourceLoader_H