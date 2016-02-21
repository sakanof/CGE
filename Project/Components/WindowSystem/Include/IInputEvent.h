#ifndef WindowSystem_Input_IInputEvent_H
#define WindowSystem_Input_IInputEvent_H

// Standard Includes
#include <string>

namespace WindowSystem
{
	namespace Input
	{
		class IInputEvent
		{
		public:
			IInputEvent() {}
			virtual ~IInputEvent() {}

			virtual std::string Type() const = 0;
		};
	};
};

#endif // WindowSystem_Input_IInputEvent_H