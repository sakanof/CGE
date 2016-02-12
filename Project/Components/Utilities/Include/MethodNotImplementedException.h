#ifndef Utilities_Exception_MethodNotImplementedException_H
#define Utilities_Exception_MethodNotImplementedException_H

// Util Includes
#include "BaseException.h"

namespace Utilities
{
	namespace Exception
	{
		class UTILITIES_API MethodNotImplementedException : public BaseException
		{
		public:
			MethodNotImplementedException(std::string file, int line);
			MethodNotImplementedException(std::string file, int line, std::string methodName);
		};
		#define ThrowMethodNotImplementedException(method) throw MethodNotImplementedException(__FILE__, __LINE__, method)
	};
};

#endif // Utilities_Exception_MethodNotImplementedException_H