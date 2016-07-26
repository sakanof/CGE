#ifndef WindowSystem_IWindowFactory_H
#define WindowSystem_IWindowFactory_H

#include "Window.hpp"

namespace WindowSystem
{
	class IWindowFactory
	{
	public:
		/**
		*	\brief Basic interface to create Window instances.
		**/
		virtual Window* MakeWindow(ComponentSize size, std::string title) = 0;
	};
};

#endif // WindowSystem_IWindowFactory_H%