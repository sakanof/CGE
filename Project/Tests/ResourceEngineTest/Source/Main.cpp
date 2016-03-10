#include <iostream>

// ResourceEngineTest Includes
#include "../Include/Window.h"

using ResourceEngineTest::Window;

int main()
{
	Window myWindow(SME::Vec2(800, 800), "ResourceEngineTest Window");

	while (!myWindow.ShouldClose())
	{
		myWindow.Update();
	}

	return 0;
}