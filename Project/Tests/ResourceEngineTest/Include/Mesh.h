#ifndef ResourceEngineTest_Mesh_H
#define ResourceEngineTest_Mesh_H

// Standard Includes
#include <vector>

// SME Includes
#include <SME\Include\SME.h>

// OpenGL Includes
#include <Glew\include\glew.h>
#include <GL\GL.h>

// ResourceEngineTest Includes
#include "GLUtil.h"

namespace ResourceEngineTest
{
	using SME::Vec3;
	using SME::Vec2;

	using VerticeList = std::vector < float > ;
	using ColorList = std::vector < float >;
	using UVList = std::vector < float >;

	class Mesh
	{
	private:
		unsigned int m_vertexCount;
		VerticeList  m_verticeList;
		ColorList    m_colorList;
		UVList       m_uvList;

		// OpenGL Handlers
		unsigned int m_vao;
		unsigned int m_vbo;
		
	private:
		void Generate();
		void Delete();
		void Bind();
		void Unbind();
		void Setup();

	public:
		Mesh(unsigned int vertexCount, VerticeList verticeList, ColorList colorList = ColorList(), UVList uvList = UVList());
		~Mesh();

	public:
		void Render();
	};
};

#endif // ResourceEngineTest_Mesh_H