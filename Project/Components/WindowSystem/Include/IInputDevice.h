#ifndef WindowSystem_Input_IInputDevice_H
#define WindowSystem_Input_IInputDevice_H

// Standard Includes
#include <string>

namespace WindowSystem
{
	namespace Input
	{
		class IInputDevice
		{
		public:
			IInputDevice() {}
			virtual ~IInputDevice() {}

			virtual std::string Type() const = 0;
			virtual void PoolEvents() = 0;
		};
	};
};

#endif // WindowSystem_Input_IInputDevice_H