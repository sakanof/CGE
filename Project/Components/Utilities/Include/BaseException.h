#ifndef Utilities_BaseException_H
#define Utilities_BaseException_H

// Standard Includes
#include <exception>
#include <string>

// Util Includes
#include "UtilitiesSetup.h"

namespace Utilities
{
	namespace Exception
	{
		class UTILITIES_API BaseException : public std::exception
		{
		protected:
			std::string m_message;

		public:
			BaseException(std::string file, int line, std::string message);

			const char* what() const noexcept;
		};
	};
};

#endif // Utilities_BaseException_H