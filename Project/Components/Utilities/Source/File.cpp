#include "..\include\File.h"

namespace Utilities
{
	namespace File
	{
		std::string		GetFileExtension(const std::string& file)
		{
			auto values = String::Split(file, '.');

			return values[values.size()-1];
		}
		std::string		GetFileName(const std::string& filePath)
		{
			auto values = String::Split(filePath, '\\');

			return values[values.size() - 1];
		}
		std::string		GetFileAbsolutePath(const std::string& filePath)
		{
			auto values = String::Split(filePath, '\\');

			return filePath.substr(0, filePath.length() - values[values.size() - 1].length() - 1);
		}
		std::ifstream*	OpenFile(const std::string& path)
		{
			auto file = new std::ifstream();
			file->open(path);
			
			if(file->good())
				return file;
			else
				throw Utilities::Exception::FileNotFoundException(__FILE__, __LINE__, path);
		}
		std::ifstream*	OpenBinaryFile(const std::string& path)
		{
			auto file = new std::ifstream(path.c_str(), std::ios::binary);
			
			if(file->good())
				return file;
			else
				throw Exception::FileNotFoundException(__FILE__, __LINE__, path);
		}
		std::streamoff	GetFileSize(const std::string& filepath)
		{
			auto file = OpenFile(filepath);
			std::streamoff size = -1;

			file->seekg(0, file->end);
			size = file->tellg(); 
			file->close();

			delete file;

			return size;
		}
		std::string		LoadFile(const std::string& path)
		{
			std::string fileBuffer = nullptr;
			std::ifstream* file = OpenFile(path);
			
			if(file->good())
			{
				std::ostringstream data;
				while(file->good()) 
				{
					int c = file->get();
					if(!file->eof())
						data << (char) c;
				}

				fileBuffer = std::string(data.str());
			}

			return fileBuffer;
		}
	};
};