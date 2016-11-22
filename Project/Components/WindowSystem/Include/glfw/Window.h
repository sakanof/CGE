#ifndef WindowSystem_GLFW_Window_H
#define WindowSystem_GLFW_Window_H

#include <assert.h>

#include <GL\glew.h>
#include <GL\GL.h>
#include <GLFW\glfw3.h>

#include "../Window.hpp"

namespace WindowSystem
{
	namespace GLFW
	{
		class WINDOW_SYSTEM_API Window : public WindowSystem::Window
		{
		private:
			GLFWwindow* m_windowHandler;
			bool		m_isVisible;

		public:
			Window(int windowId, ComponentSize windowSize = ComponentSize(800, 600), const std::string& title = std::string("My Window"));
			~Window();

		private:
			void Initialize();
			void InitializeGlew();
			void InitializeGLFW();

			void FinalizeGLFW();

		public:
			/**
			*	\brief Update the window's title.
			**/
			void SetTitle(const std::string& title);

			/**
			*	\brief Resize the window.
			*
			*	\param size the new window's size.
			**/
			void Resize(const ComponentSize size);

			/**
			*	\brief True if the window is visible.
			**/
			bool IsVisible() const;

			/**
			*	\brief Hides the window.
			**/
			void Hide();

			/**
			*	\brief Shows the window.
			**/
			void Show();

			/**
			*	\brief True if the window's current state has been updated to close.
			**/
			bool ShouldClose();

			/**
			*	\brief Treat the some events and updates its the display.
			**/
			void Update();

			/**
			*	\brief Destroy the window's dependencies.
			**/
			void Destroy();
		};
	};
};
#endif // WindowSystem_GLFW_Window_H