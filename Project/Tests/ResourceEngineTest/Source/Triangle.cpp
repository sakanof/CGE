#include "../Include/Triangle.h"

namespace ResourceEngineTest
{
	Triangle::Triangle()
	{
		std::vector<float> vertices = 
		{
			+1.0f, -1.0f, +0.0f,
			+0.0f, +1.0f, +0.0f,
			-1.0f, -1.0f, +0.0f
		};

		std::vector<float> colors =
		{
			+1.0f, +0.0f, +0.0f,
			+0.0f, +1.0f, +0.0f,
			+0.0f, +0.0f, +1.0f
		};

		this->m_mesh = new Mesh(3, vertices, colors);
	}
	Triangle::~Triangle()
	{
		delete this->m_mesh;
		this->m_mesh = nullptr;
	}

	void Triangle::Draw()
	{
		this->m_mesh->Render();
	}
};