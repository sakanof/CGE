#include "../../Include/glfw/WindowFactory.h"

namespace WindowSystem
{
	namespace GLFW
	{
		WindowFactory* WindowFactory::m_instance = nullptr;
		WindowFactory* WindowFactory::Instance()
		{
			if (!m_instance)
				m_instance = new WindowFactory();

			return m_instance;
		}
		Window* WindowFactory::MakeWindow(ComponentSize size, std::string title)
		{
			static int windowCounter = 0;

			windowCounter++;
			return new WindowSystem::GLFW::Window(windowCounter, size, title);
		}
	};
};
