#ifndef Utilities_String_H
#define Utilities_String_H

// Standard Includes
#include <string>
#include <vector>

// Util Includes
#include "UtilitiesSetup.h"

namespace Utilities
{
	namespace String
	{
		using std::string;
		using std::vector;

		/**
		*	\brief Returns a std::vector containing all the substrings spplited by the delimiter.
		*
		*	\param str string to be spplited.
		*	\param delimiter char delimiter.
		*
		*	\return An std::vector with the spplited content of the str.
		**/
		UTILITIES_API vector<string> Split(const string& str, char delimiter);

		/**
		*	\brief Returns a std::vector containing all the substrings spplited by the delimiter.
		*
		*	\param str string to be spplited.
		*	\param delimiter string delimiter
		*
		*	\return An std::vector with the spplited content of the str.
		**/
		UTILITIES_API vector<string> Split(const string& str, const string& delimiter);

		/**
		*	\brief Generates a string with the characterToReplace replaced by newcharacter.
		*
		*	\param str string that will be used as initial value.
		*	\param characterToReplace character that will be replaced in the string.
		*	\param newCharacter character that will be placed in the string.
		*
		*	\return A string with the replaced characters.
		**/
		UTILITIES_API string Replace(const string& str, char characterToReplace, char newCharacter);

		/**
		*	\brief Remove blank chracters from end of the string.
		*
		*	\param str string that will be used as initial value.
		*
		*	\return string without blanck characters in the end.
		**/
		UTILITIES_API string TrimBack(const string& str);

		/**
		*	\brief Remove blank chracters from the beginning of the string.
		*
		*	\param str string that will be used as initial value.
		*
		*	\return string without blanck characters in the beginnning.
		**/
		UTILITIES_API string TrimFront(const string& str);

		/**
		*	\brief Remove blank chracters from the beginning and the end of the string.
		*
		*	\param str string that will be used as initial value.
		*
		*	\return string without blanck characters in the beginnning and in the end.
		**/
		UTILITIES_API string Trim(const string& str);
	};
};
#endif // Utilities_String_H