#include "../Include/Resource.h"

namespace ResourceEngine
{
	Resource::Resource(std::string filePath)
	{
		this->m_filePath		 = filePath;
		this->m_fileAbsolutePath = Utilities::File::GetFileAbsolutePath(filePath);
		this->m_fileName		 = Utilities::File::GetFileName(filePath);
		this->m_fileExtension	 = Utilities::File::GetFileExtension(filePath);
	}

	std::string Resource::GetFileName() const { return this->m_fileName; }
	std::string Resource::GetFilePath() const { return this->m_filePath; }
	std::string Resource::GetAbsolutePath() const{ return this->m_filePath; }
	std::string Resource::GetFileExtension() const{ return this->m_fileExtension;  }
};