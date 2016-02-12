#include "..\include\MethodNotImplementedException.h"


namespace Utilities
{
	namespace Exception
	{
		MethodNotImplementedException::MethodNotImplementedException(std::string file, int line)
			: BaseException(file, line, "Method not implemented.") {}
		MethodNotImplementedException::MethodNotImplementedException(std::string file, int line, std::string methodName)
			: BaseException(file, line, "Method '" + methodName +"' not implemented.") {}
	};
};