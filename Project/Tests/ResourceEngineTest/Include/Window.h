#ifndef ResourceEngineTest_Window_H
#define ResourceEngineTest_Window_H

// Standard Includes
#include <iostream>
#include <string>

// Utilities Includes
#include <Utilities\Include\BaseException.h>

// SME Includes
#include <SME\Include\SME.h>

// Glew Includes
#include <Glew\include\glew.h>

// GLFW Includes
#include <glfw-3.0.4.bin.WIN32\include\glfw3.h>

namespace ResourceEngineTest
{
	using SME::Vec2;
	using SME::Vec4;

	class Window
	{
	private:
		static bool m_isGLInitialized;
		GLFWwindow* m_glfwWindow;
		
	private:
		Vec2 m_size;
		std::string m_title;

	private: 
		void InitializeGlew();
		void InitializeGLFW();
		void InitializeGL();
		void Initialize();

	public:
		Window(Vec2 size, std::string title);

	public:
		void Update();

		void Clear();
		void ClearColor(Vec4 color);

		bool ShouldClose();
		void Show();
		void Hide();
	};
};

#endif // ResourceEngineTest_Window_H