#ifndef WindowSystem_Input_Mouse_IMouseInputDeviceImplementation_H
#define WindowSystem_Input_Mouse_IMouseInputDeviceImplementation_H

// WindowSystem Includes
#include "MouseButton.h"

namespace WindowSystem
{
	namespace Input
	{
		namespace Mouse
		{
			class IMouseInputDeviceImplementation
			{
			public:
				IMouseInputDeviceImplementation() {}
				virtual ~IMouseInputDeviceImplementation() {}

				virtual void PoolEvents() = 0;
			};
		};
	};
};

#endif // WindowSystem_Input_Mouse_IMouseInputDeviceImplementation_H