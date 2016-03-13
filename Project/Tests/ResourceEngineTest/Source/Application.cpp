#include "../Include/Application.h"

namespace ResourceEngineTest
{
	Application::Application() 
		: m_isStartUp(false) 
	{
		ResourceCache::Initialize(2048 * 1024 * 1024, true);
	}
	Application::~Application()
	{
	}

	void Application::StartUp()
	{
		this->m_window = new Window(SME::Vec2(800, 800), "ResourceEngineTest Window");
		this->m_window->Hide();

		this->m_shaderProgram = new ShaderProgram(ShaderLoader::LoadShader("Resources\\Shaders\\simpleVertexShader.vs"), ShaderLoader::LoadShader("Resources\\Shaders\\simpleFragmentShader.fs"));
	
		this->m_isStartUp = true;
	}
	void Application::ShutDown()
	{
		if (this->m_isStartUp)
		{
			delete this->m_window;
			this->m_window = nullptr;

			delete this->m_shaderProgram;
			this->m_shaderProgram = nullptr;

			this->m_isStartUp = false;
		}
	}
	void Application::Update()
	{
		this->m_window->Update();
	}
	void Application::Run()
	{
		if (!this->m_isStartUp)
			StartUp();

		this->m_window->Show();
		while (!this->m_window->ShouldClose())
		{
			Update();
		}
	}
};