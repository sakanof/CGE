#ifndef WindowSystem_Input_IInputEvent_H
#define WindowSystem_Input_IInputEvent_H

// Standard Includes
#include <string>
#include <chrono>

// WindowSystem Includes
#include "WindowSystemSetup.h"

namespace WindowSystem
{
	namespace Input
	{
		using std::chrono::time_point;
		using std::chrono::system_clock;
		using std::chrono::high_resolution_clock;

		using Time = time_point < system_clock > ;

		WINDOW_SYSTEM_EXP_TEMPLATE template class WINDOW_SYSTEM_API std::chrono::duration<std::chrono::system_clock::rep, std::chrono::system_clock::period>;
		WINDOW_SYSTEM_EXP_TEMPLATE template class WINDOW_SYSTEM_API time_point<system_clock>;

		class WINDOW_SYSTEM_API IInputEvent
		{
		protected:
			Time m_time;

		public:
			IInputEvent(Time eventTime) : m_time(eventTime) {}
			virtual ~IInputEvent() {}

			Time GetEventTime() const { return this->m_time; }
			virtual std::string Type() const = 0;
		};
	};
};

#endif // WindowSystem_Input_IInputEvent_H