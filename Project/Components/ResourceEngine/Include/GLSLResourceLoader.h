#ifndef ResourceEngine_Parser_GLSLResourceParser_H
#define ResourceEngine_Parser_GLSLResourceParser_H

// Standard Includes
#include <memory>
#include <algorithm>

// Util Includes
#include <Utilities\Include\File.h>

// GameEngine Includes
#include "GLSLResourceData.h"
#include "IResourceLoader.h"

namespace ResourceEngine
{
	namespace Loader
	{
		namespace Offline
		{
			class RESOURCE_ENGINE_API GLSLResourceParser : public IResourceLoader
			{
				using IResourceData = Data::IResourceData;
			public:
				GLSLResourceParser(void);
				~GLSLResourceParser(void);

				std::string		GetPattern() const;
				bool			IsPatternAccepted(const std::string pattern) const;
				__int64			GetRawResourceSize(const Resource& resource) const;
				IResourceData*	Load(const Resource& resource);
			};
		}
	};
};

#endif // ResourceEngine_Parser_GLSLResourceParser_H
