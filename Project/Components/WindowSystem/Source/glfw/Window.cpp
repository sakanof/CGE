#include "../../Include/glfw/Window.h"

namespace WindowSystem
{
	namespace GLFW
	{
		Window::Window(int windowId, ComponentSize windowSize, const std::string& title)
			: WindowSystem::Window(windowId, windowSize, title),
			  m_isVisible(false)
		{
			Initialize();
		}
		Window::~Window()
		{
			Destroy();
		}

		void Window::Initialize()
		{
			InitializeGLFW();
			InitializeGlew();
		}
		
		void Window::InitializeGlew()
		{
			glewExperimental = GL_TRUE;

			auto glewInitializeFlag = glewInit();
			if (GLEW_OK != glewInitializeFlag)
			{
				const unsigned char* glewErrorString = glewGetErrorString(glewInitializeFlag);
				std::string errorMessage = "Fail to initialze Glew. Error message: ";
				errorMessage += reinterpret_cast<const char*>(glewErrorString);
				
				assert(0 && errorMessage.c_str());
			}

			glEnable(GL_DEPTH_TEST);
			glEnable(GL_LESS);
			glCullFace(GL_BACK);
			glFrontFace(GL_CCW);
		}

		void Window::InitializeGLFW()
		{

			if (!glfwInit())
				assert(0 && "Fail to initialize GLFW.");

			this->m_windowHandler = glfwCreateWindow((int)this->GetSize().x, (int)this->GetSize().y, this->GetTitle().c_str(), NULL, NULL);
			if (nullptr == this->m_windowHandler)
				assert(0 && "Fail to create GLFW window.");

			int majorVersion = 4;
			int minorVersion = 2;
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
			glfwMakeContextCurrent(this->m_windowHandler);
		}
	
		void Window::FinalizeGLFW()
		{
			if(this->m_windowHandler != nullptr)
			{
				glfwDestroyWindow(this->m_windowHandler);
				this->m_windowHandler = nullptr;

				glfwTerminate();
			}
		}

		void Window::SetTitle(const std::string& title)
		{
			this->m_title = std::string(title);
			glfwSetWindowTitle(this->m_windowHandler, this->m_title.c_str());
		}

		void Window::Resize(const ComponentSize size)
		{
			this->m_size = size;
			glfwSetWindowSize(this->m_windowHandler, this->m_size.width, this->m_size.height);
		}

		bool Window::IsVisible() const { return this->m_isVisible; }

		void Window::Hide()
		{
			glfwHideWindow(this->m_windowHandler);
			this->m_isVisible = false;
		}

		void Window::Show()
		{
			glfwFocusWindow(this->m_windowHandler);
			this->m_isVisible = true;
		}

		bool Window::ShouldClose()
		{
			return 1 == glfwWindowShouldClose(this->m_windowHandler);
		}

		void Window::Update()
		{
			glfwPollEvents();
			glfwSwapBuffers(this->m_windowHandler);
		}
		
		void Window::Destroy()
		{
			FinalizeGLFW();
		}
	};
};
