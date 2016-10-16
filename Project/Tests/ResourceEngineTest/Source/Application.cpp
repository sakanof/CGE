#include "../Include/Application.h"

namespace ResourceEngineTest
{
	Application::Application() 
		: m_isStartUp(false) {}
	Application::~Application()
	{
		this->m_resourceCache->Flush();
	}

	void Application::StartUp()
	{
		this->m_resourceCache = std::shared_ptr<ResourceEngine::IResourceCache>(ResourceEngine::SimpleResourceCache::CreateNew(512 * 1024));

		this->m_window = new Window(SME::Vec2(800, 800), "ResourceEngineTest Window");
		this->m_window->Hide();

		this->m_shaderProgram = new ShaderProgram(this->m_resourceCache->GetHandle(Resource("Resources\\Shaders\\simpleVertexShader.vs"))->GetResourceData<GLSLResourceData>().lock()->GetCode(),
												  this->m_resourceCache->GetHandle(Resource("Resources\\Shaders\\simpleFragmentShader.fs"))->GetResourceData<GLSLResourceData>().lock()->GetCode());

		this->m_triangle = new Triangle();

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

			delete this->m_triangle;
			this->m_triangle = nullptr;

			this->m_isStartUp = false;
		}
	}
	void Application::Update()
	{
		this->m_window->Clear();
		this->m_shaderProgram->Use();
		this->m_triangle->Draw();
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
