#ifndef ResourceEngineTest_Mesh_H
#define ResourceEngineTest_Mesh_H

// Standard Includes
#include <vector>

// SME Includes
#include <SME\Include\SME.h>

// OpenGL Includes
#include <Glew\include\glew.h>
#include <GL\GL.h>

// ResouceEngineTest Includes
#include "GLUtil.h"

namespace ResouceEngineTest
{
	using SME::Vec3;
	using SME::Vec2;

	using VerticeList = std::vector < Vec3 > ;
	using ColorList = std::vector < Vec3 >;
	using UVList = std::vector < Vec2 >;

	class Mesh
	{
	private:
		VerticeList m_verticeList;
		ColorList   m_colorList;
		UVList      m_uvList;

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
		Mesh(VerticeList verticeList, ColorList colorList, UVList uvList = UVList());
		~Mesh();

	public:
		void Render();
	};
};

#endif // ResourceEngineTest_Mesh_H