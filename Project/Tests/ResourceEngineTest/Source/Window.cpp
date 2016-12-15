#include "../Include/Window.h"

namespace ResourceEngineTest
{
	class BasicException : public std::exception
	{
	private:
		std::string m_message;

	public:
		BasicException(std::string message) : m_message(message) {}
		const char* what() const noexcept { return m_message.c_str(); ;}
	};
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

			throw BasicException(msg);
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
			throw BasicException("Error on the glfw initialization...");

		this->m_glfwWindow = glfwCreateWindow((int)this->m_size.x, (int)this->m_size.y, this->m_title.c_str(), NULL, NULL);
		if (!this->m_glfwWindow)
			throw BasicException("Error on the window creation....");

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
