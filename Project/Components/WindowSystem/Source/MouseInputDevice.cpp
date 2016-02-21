#include "../Include/MouseInputDevice.h"

namespace WindowSystem
{
	namespace Input
	{
		namespace Mouse
		{
			MouseInputDevice::MouseInputDevice(IMouseInputDeviceImplementation* deviceImplementation)
				: m_deviceImplementation(deviceImplementation) {}
			MouseInputDevice::~MouseInputDevice()
			{
				Utilities::Memory::SafeDelete(this->m_deviceImplementation);
			}

			std::string MouseInputDevice::Type() const { return std::string("MouseInputDevice"); }
			void MouseInputDevice::PoolEvents()
			{
				this->m_deviceImplementation->PoolEvents();
			}
		};
	};
};