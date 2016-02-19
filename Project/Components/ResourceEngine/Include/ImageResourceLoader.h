#ifndef ResourceEngine_Loader_ImageResourceLoader_H
#define ResourceEngine_Loader_ImageResourceLoader_H

// Standatd Includes
#include <memory>
#include <vector>
#include <algorithm>

// Third Party Includes
#include <FreeImage\Include\FreeImage.h>

// Util Includes
#include <Utilities\include\File.h>

// GameEngine Includes
#include "ImageResourceData.h"
#include "IResourceLoader.h"

namespace ResourceEngine
{
	namespace Loader
	{
		namespace Offline
		{
			class RESOURCE_ENGINE_API ImageResourceLoader : public IResourceLoader
			{
				using IResourceData = Data::IResourceData;
			public:
				ImageResourceLoader(IResourceObserver* resourceObserver);
				~ImageResourceLoader(void);

				std::string  Pattern() const;
				bool IsPatternAccepted(const std::string pattern) const;
				__int64 GetRawResourceSize(const Resource& resource) const;
				IResourceData* Load(const Resource& resource) const;
			};
		};
	}; 
}; 

#endif // ResourceEngine_Loader_ImageResourceLoader_H
