// Utilities Includes
#include <Utilities/Include/String.h>

// Google Test Includes
#include <gtest/gtest.h>

TEST(Utilities_String, TrimBack)
{
	std::string multipleBlankSpacesString         = "       My Test String";
	std::string multipleBlankSpacesExpectedString = "My Test String";
	std::string multipleBlankSpacesResultString   = Utilities::String::TrimBack(multipleBlankSpacesString);

	EXPECT_EQ(multipleBlankSpacesExpectedString, multipleBlankSpacesResultString);
}

TEST(Utilities_String, TrimFront)
{
	std::string multipleBlankSpacesString         = "My Test String       ";
	std::string multipleBlankSpacesExpectedString = "My Test String";
	std::string multipleBlankSpacesResultString   = Utilities::String::TrimFront(multipleBlankSpacesString);

	EXPECT_EQ(multipleBlankSpacesExpectedString, multipleBlankSpacesResultString);
}

TEST(Utilities_String, Trim)
{
	std::string testString     = "        My Test String       ";
	std::string expectedString = "My Test String";
	std::string resultString   = Utilities::String::Trim(testString);

	EXPECT_EQ(expectedString, resultString);
}

TEST(Utilities_String, ReplaceChar)
{
	std::string testString     = "My Replace Test";
	std::string expectedString = "My*Replace*Test";
	std::string resultString   = Utilities::String::Replace(testString, ' ', '*');

	EXPECT_EQ(expectedString, resultString);
}

TEST(Utilities_String, SplitChar)
{
	std::string testString       = "My Test String";
	std::string expectedString[] = { "My", "Test", "String" };
	
	auto result = Utilities::String::Split(testString, ' ');
	
	EXPECT_EQ(3, result.size());
	EXPECT_EQ(expectedString[0], result[0]);
	EXPECT_EQ(expectedString[1], result[1]);
	EXPECT_EQ(expectedString[2], result[2]);
}

TEST(Utilities_String, SplitString)
{
	std::string testString       = "My<-->Test<-->String";
	std::string expectedString[] = { "My", "Test", "String" };

	auto result = Utilities::String::Split(testString, "<-->");

	EXPECT_EQ(3, result.size());
	EXPECT_EQ(expectedString[0], result[0]);
	EXPECT_EQ(expectedString[1], result[1]);
	EXPECT_EQ(expectedString[2], result[2]);
}
