#include "..\include\BaseException.h"


namespace Utilities
{
	namespace Exception
	{
		BaseException::BaseException(std::string file, int line, std::string message) 
		{
			this->m_message  = "Message: " + message + "\n";
			this->m_message += "File...: " + file + "\n";
			this->m_message += "Line...: " + std::to_string(line);
		}
		const char* BaseException::what() { return this->m_message.c_str(); }
	};
};