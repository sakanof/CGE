#ifndef ResourceEngine_Parser_GLSLResourceLoader_H
#define ResourceEngine_Parser_GLSLResourceLoader_H

// Standard Includes
#include <memory>
#include <algorithm>

// Util Includes
#include <Utilities/Include/File.h>

// GameEngine Includes
#include "GLSLResourceData.h"
#include "IResourceLoader.h"

namespace ResourceEngine
{
	namespace Loader
	{
		namespace Offline
		{
			class RESOURCE_ENGINE_API GLSLResourceLoader : public IResourceLoader
			{
				using IResourceData = Data::IResourceData;
			public:
				GLSLResourceLoader(IResourceObserver* resourceObserver);
				~GLSLResourceLoader(void);

				std::string		Pattern() const;
				bool			IsPatternAccepted(const std::string pattern) const;
				int64_t			GetRawResourceSize(const Resource& resource) const;
				IResourceData*	Load(const Resource& resource);
			};
		}
	};
};

#endif // ResourceEngine_Parser_GLSLResourceLoader_H
