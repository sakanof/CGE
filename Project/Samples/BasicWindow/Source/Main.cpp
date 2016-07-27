#include <iostream>

#include <WindowSystem/Include/glfw/WindowFactory.h>

int main()
{
	auto myWindow = WindowSystem::GLFW::WindowFactory::Instance()->MakeWindow(WindowSystem::ComponentSize(800, 800), "Basic Window Sample");

	while(!myWindow->ShouldClose())
	{
		myWindow->Update();
	}

	delete myWindow;
	myWindow = nullptr;

	return 0;
}