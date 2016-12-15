#ifndef WindowSystem_Input_Mouse_MouseInputDevice_H
#define WindowSystem_Input_Mouse_MouseInputDevice_H

// Utilities Includes
#include <Utilities/Include/Memory.hpp>

// WindowSystem Includes
#include "WindowSystemSetup.h"
#include "IInputDevice.h"
#include "IMouseInputDeviceImplementation.h"

namespace WindowSystem
{
	namespace Input
	{
		namespace Mouse
		{
			class WINDOW_SYSTEM_API MouseInputDevice : public Input::IInputDevice
			{
			private:
				IMouseInputDeviceImplementation* m_deviceImplementation;

			public:
				MouseInputDevice(IMouseInputDeviceImplementation* deviceImplementation);
				~MouseInputDevice();

			public:
				std::string Type() const;
				void PoolEvents();
			};
		};
	};
};

#endif // WindowSystem_Input_Mouse_MouseInputDevice_H
