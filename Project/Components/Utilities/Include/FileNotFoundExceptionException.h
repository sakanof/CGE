#ifndef Utilities_Exception_FileNotFoundExceptionException_H
#define Utilities_Exception_FileNotFoundExceptionException_H

// Util Includes
#include "BaseException.h"

namespace Utilities
{
	namespace Exception
	{
		class UTILITIES_API FileNotFoundException : public BaseException
		{
		public:
			FileNotFoundException(std::string file, int line);
			FileNotFoundException(std::string file, int line, std::string fileName);
		};
		#define ThrowFileNotFoundException(file) throw FileNotFoundException(__FILE__, __LINE__, file)
	};
};

#endif // Utilities_Exception_FileNotFoundExceptionException_H