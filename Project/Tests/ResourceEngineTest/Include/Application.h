#ifndef ResourceEngineTest_Application_H
#define ResourceEngineTest_Application_H

// Standard Includes
#include <string>

// ResourceEngine Includes
#include <ResourceEngine/Include/SimpleResourceCache.h>

// ResourceEngineTest Includes
#include "Window.h"
#include "ShaderProgram.h"
#include "Triangle.h"

namespace ResourceEngineTest
{
	using ResourceCache = ResourceEngine::IResourceCache::SharedPtr;

	class Application
	{
		private:
			bool		   m_isStartUp;
			Window*		   m_window;
			ResourceCache  m_resourceCache;
			ShaderProgram* m_shaderProgram;
			Triangle*      m_triangle;
		
		public:
			Application();
			~Application();
		
		public:
			void StartUp();
			void ShutDown();
			void Update();
			void Run();
	};
};

#endif // ResourceEngineTest_Application_H