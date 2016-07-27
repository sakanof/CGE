#ifndef WindowSystem_GLFW_WindowFactory_H
#define WindowSystem_GLFW_WindowFactory_H

#include "../IWindowFactory.h"
#include "Window.h"

namespace WindowSystem
{
	namespace GLFW
	{
		class WINDOW_SYSTEM_API WindowFactory : public WindowSystem::IWindowFactory
		{
		private:
			static WindowFactory* m_instance;

		public:
			static WindowFactory* Instance();
			/**
			*	\brief Basic interface to create Window instances.
			**/
			Window* MakeWindow(ComponentSize size, std::string title);
		};
	};
};
#endif // WindowSystem_GLFW_WindowFactory_H