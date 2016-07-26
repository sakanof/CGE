#ifndef WindowSystem_IWinwodow_H
#define WindowSystem_IWinwodow_H

#include <string>

#include "WindowSystemSetup.h"

namespace WindowSystem
{
	struct ComponentSize
	{
		union
		{
			struct { unsigned int x; unsigned int y; };
			struct { unsigned int width; unsigned int height; };
		};
		ComponentSize()
			: x(0),
			  y(0) {}
		ComponentSize(unsigned int x, unsigned int y)
			: x(x),
			  y(y) {}
	};
	using ComponentPosition = ComponentSize;

	class Window
	{
	protected:
		int				m_id;		/** < Identifier of the window */
		ComponentSize	m_size;		/** < Size of the window */
		std::string		m_title;	/** < Title of the window */

	protected:
		Window(int windowId, ComponentSize windowSize = ComponentSize(800, 600), const std::string& title = std::string("My Window"))
			: m_id(windowId),
			  m_size(windowSize),
			  m_title(title) {}
		virtual ~Window() {}

	public:
		std::string GetTitle() const { return this->m_title; }
		ComponentSize GetSize() const { return this->m_size; }

		/**
		*	\brief Update the window's title.
		**/
		virtual void SetTitle(const std::string& title) = 0;

		/**
		*	\brief Resize the window.
		*
		*	\param size the new window's size.
		**/
		virtual void Resize(const ComponentSize size) = 0;

		/**
		*	\brief True if the window is visible.
		**/
		virtual bool IsVisible() const = 0;

		/**
		*	\brief Hides the window.
		**/
		virtual void Hide() = 0;
		
		/**
		*	\brief Shows the window.
		**/
		virtual void Show() = 0;
		
		/**
		*	\brief True if the window's current state has been updated to close.
		**/
		virtual bool ShouldClose() = 0;
		
		/**
		*	\brief Treat the some events and updates its the display.
		**/
		virtual void Update() = 0;
		
		/**
		*	\brief Destroy the window's dependencies.
		**/
		virtual void Destroy() = 0;
	};
};

#endif // WindowSystem_IWinwodow_H
