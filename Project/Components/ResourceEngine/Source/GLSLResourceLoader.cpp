#include "../include/GLSLResourceLoader.h"

using ResourceEngine::Data::IResourceData;

namespace ResourceEngine
{
	namespace Loader
	{
		namespace Offline
		{
			GLSLResourceParser::GLSLResourceParser(void) {}
			GLSLResourceParser::~GLSLResourceParser(void) {}
			std::string		GLSLResourceParser::GetPattern() const { return ".glsl .vs .fs .gs .tcs .tes .vert .frag"; }
			bool			GLSLResourceParser::IsPatternAccepted(const std::string pattern) const
			{
				auto temp = pattern;
				std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
				return GetPattern().find(temp) != std::string::npos;
			}
			__int64			GLSLResourceParser::GetRawResourceSize(const Resource& resource) const { return Utilities::File::GetFileSize(resource.GetFilePath()); }
			IResourceData*	GLSLResourceParser::Load(const Resource& resource)
			{
				std::string GLSLData = Utilities::File::LoadFile(resource.GetFilePath());
				bool stop = false;
				do
				{
					auto pos = GLSLData.find("#include");
					if (pos != std::string::npos)
					{
						std::string filename = std::string("");
						auto result = GLSLData.substr(pos + std::string("#include").length(), GLSLData.length() - 2);
						filename = Utilities::String::Split(result, "\"")[0];
						filename = Utilities::String::Trim(filename);

						std::string filePath;
						filePath = std::string(Utilities::File::GetFileAbsolutePath(resource.GetFilePath()));

						GLSLData.erase(pos, std::string("#include").length() + filename.length() + 3);

						std::unique_ptr<std::string> toAppend(new std::string(Utilities::File::LoadFile(filePath + filename)));
						if (toAppend != nullptr)
							GLSLData.insert(pos, *toAppend);
					}
					else
						stop = true;
				} while (!stop);

				return new Data::GLSLResourceData(GLSLData);
			}
		};
	};
}; 