// Utilities Includes
#include <Utilities/Include/File.h>
#include <Utilities/Include/BaseException.h>
#include <Utilities/Include/FileNotFoundException.h>

// Google Test Includes
#include <gtest/gtest.h>

TEST(Utilities_File, GetFileExtension)
{
	std::string filePath  = "C:/CGE/Project/Resources/myFile.txt";
	std::string extension = "txt";
	std::string result    = Utilities::File::GetFileExtension(filePath);

	EXPECT_EQ(extension, result);
}

TEST(Utilities_File, GetFileName)
{
	std::string filePath = "C:/CGE/Project/Resources/myFile.txt";
	std::string filename = "myFile.txt";
	std::string result   = Utilities::File::GetFileName(filePath);

	EXPECT_EQ(filename, result);
}

TEST(Utilities_File, GetFileAbsolutePath)
{
	std::string filePath     = "C:/CGE/Project/Resources/myFile.txt";
	std::string absolutePath = "C:/CGE/Project/Resources";
	std::string result       = Utilities::File::GetFileAbsolutePath(filePath);

	EXPECT_EQ(absolutePath, result);
}
