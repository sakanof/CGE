#ifndef WindowSystem_Input_IInputEventArgument_H
#define WindowSystem_Input_IInputEventArgument_H

// Standard Includes
#include <string>

namespace WindowSystem
{
	namespace Input
	{
		class IInputEventArgument
		{
		public:
			IInputEventArgument() {}
			virtual ~IInputEventArgument() {}

			virtual std::string Type() const = 0;
		};
	};
};

#endif // WindowSystem_Input_IInputEventArgument_H