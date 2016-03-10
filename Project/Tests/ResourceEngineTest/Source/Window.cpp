#include "../Include/Window.h"

namespace ResourceEngineTest
{
	bool Window::m_isGLInitialized = false;
	Window::Window(Vec2 size, std::string title)
		: m_size(size), 
		  m_title(title)
	{
		Initialize();
	}

	
	void Window::InitializeGlew()
	{
		glewExperimental = GL_TRUE;
		auto glewInitializeFlag = glewInit();

		if (GLEW_OK != glewInitializeFlag)
		{
			const unsigned char* glewErrorString = glewGetErrorString(glewInitializeFlag);
			std::string msg = "Error on the graphics context creation. Could not initialize Glew. \nMessage: ";
			msg += reinterpret_cast<const char*>(glewErrorString);

			std::cout << msg<<std::endl;

			throw std::exception(msg.c_str());
		}

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LESS);
		glCullFace(GL_BACK);
		// counterclockwise
		glFrontFace(GL_CCW);
	}

	void Window::InitializeGLFW()
	{
		if (!glfwInit())
			std::exception("Error on the glfw initialization...");

		this->m_glfwWindow = glfwCreateWindow((int)this->m_size.x, (int)this->m_size.y, this->m_title.c_str(), NULL, NULL);
		if (!this->m_glfwWindow)
			std::exception("Error on the window creation....");

		int majorVersion = 4;
		int minorVersion = 2;
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
		glfwMakeContextCurrent(this->m_glfwWindow);
	}

	void Window::InitializeGL()
	{
		InitializeGLFW();
		InitializeGlew();

		ClearColor(Vec4(1.0f, 1.0f, 1.0f, 1.0f));
		Clear();

		m_isGLInitialized = true;
	}

	void Window::Initialize()
	{
		InitializeGL();
	}

	void Window::Update()
	{
		glfwPollEvents();

		Clear();
		glfwSwapBuffers(this->m_glfwWindow);
	}

	void Window::Clear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }
	void Window::ClearColor(Vec4 color) { glClearColor(color.x, color.y, color.z, color.w); }

	bool Window::ShouldClose()
	{
		return 1 == glfwWindowShouldClose(this->m_glfwWindow);
	}
	void Window::Show() { glfwShowWindow(this->m_glfwWindow); }
	void Window::Hide() { glfwHideWindow(this->m_glfwWindow); }
};