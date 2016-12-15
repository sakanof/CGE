#include "../Include/FileNotFoundException.h"


namespace Utilities
{
	namespace Exception
	{
		FileNotFoundException::FileNotFoundException(std::string file, int line)
			: BaseException(file, line, "File not found.") {}
		FileNotFoundException::FileNotFoundException(std::string file, int line, std::string fileName)
			: BaseException(file, line, "File '" + fileName + "' not found.") {}
	};
};
