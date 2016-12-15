#ifndef ResourceEngine_Resource_H
#define ResourceEngine_Resource_H

// Standard Includes
#include <string>

// Utilities Includes
#include <Utilities/Include/File.h>

// ResourceEngine Includes
#include "ResourceEngineSetup.h"

namespace ResourceEngine
{
	class RESOURCE_ENGINE_API Resource
	{
	private:
		std::string m_fileName;
		std::string m_filePath;
		std::string m_fileAbsolutePath;
		std::string m_fileExtension;

	public:
		Resource(std::string filePath);

	public:
		std::string GetFileName() const;
		std::string GetFilePath() const;
		std::string GetAbsolutePath() const;
		std::string GetFileExtension() const;
	};
};

#endif // ResourceEngine_Resource_H
