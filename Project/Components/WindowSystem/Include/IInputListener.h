#ifndef WindowSystem_Input_IInputListener_H
#define WindowSystem_Input_IInputListener_H

// Standard Includes
#include <string>

namespace WindowSystem
{
	namespace Input
	{
		class IInputListener
		{
		public:
			IInputListener() {}
			virtual ~IInputListener() {}

			virtual std::string Type() const = 0;
		};
	};
};

#endif // WindowSystem_Input_IInputListener_H