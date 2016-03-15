#ifndef Utilities_File_H
#define Utilities_File_H

// Standard Includes
#include <sstream>
#include <fstream>
#include <string>

// Utilities Includes
#include "String.h"
#include "Memory.hpp"
#include "FileNotFoundException.h"

namespace Utilities
{
	namespace File
	{
		/** 
		 *	\brief Gets the file extension.
		 *
		 *	\param file filepath.
		 *
		 *	\return A string containing the file extension or blank if the given file does not have extension.
		 **/
		UTILITIES_API std::string	GetFileExtension(const std::string& file);
		
		/** 
		 *	\brief Gets the file name from the filepath.
		 *
		 *	\param filePath absolute path for the file.
		 *
		 *	\return A string containing the filename.
		 **/
		UTILITIES_API std::string	GetFileName(const std::string& filePath);
		
		/** 
		 *	\brief Gets the path for the give filepath.
		 *
		 *	\param filePath absolute filepath.
		 *
		 *	\return A string containing just the path of the file.
		 **/
		UTILITIES_API std::string	GetFileAbsolutePath(const std::string& filePath);
		
		/** 
		 *	\brief Opens a file.
		 *
		 *	\param filePath path for the file.
		 *
		 *	\return A ifstream of the file.
		 **/
		UTILITIES_API std::ifstream* OpenFile(const std::string& filePath);
		
		/** 
		 *	\brief Opens an binary file.
		 *
		 *	\param filePath path for the file.
		 *
		 *	\return A ifstream of the file.
		 **/
		UTILITIES_API std::ifstream* OpenBinaryFile(const std::string& filePath);
		
		/** 
		 *	\brief Gets the file size in bytes.
		 *
		 *	\param filePath path for the file.
		 *
		 *	\return the file size in bytes.
		 **/
		UTILITIES_API std::streamoff	GetFileSize(const std::string& filePath);
		
		/** 
		 *	\brief Loads the file content.
		 *
		 *	\param filePath ppth for the file.
		 * 
		 *	\return the content of the file.
		 **/
		UTILITIES_API std::string	LoadFile(const std::string& filePath);
	};
};
#endif // Utilities_File_H