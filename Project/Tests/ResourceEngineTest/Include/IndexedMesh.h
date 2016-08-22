#ifndef ResourceEngineTest_IndexedMesh_H
#define ResourceEngineTest_IndexedMesh_H

// Standard Includes
#include <vector>

// SME Includes
#include <SME\Include\SME.h>

// ResourceEngineTest Includes
#include "GLUtil.h"
#include "IRenderable.h"

namespace ResourceEngineTest
{
	using SME::Vec3;
	using SME::Vec2;

	using VerticeList = std::vector < float >;
	using IndexList   = std::vector < unsigned int >;
	using ColorList   = std::vector < float >;
	using UVList      = std::vector < float >;

	class IndexedMesh : public IRenderable
	{
	private:
		VerticeList  m_verticeList;
		IndexList    m_indexList;
		ColorList    m_colorList;
		UVList       m_uvList;

		// OpenGL Handlers
		unsigned int m_vao;
		unsigned int m_ibo;

	private:
		void Generate();
		void Delete();
		void Bind();
		void Unbind();
		void Setup();

	public:
		IndexedMesh(VerticeList verticeList, IndexList indexList, ColorList colorList = ColorList(), UVList uvList = UVList());
		~IndexedMesh();

	public:
		void Render();
	};
};

#endif // ResourceEngineTest_IndexedMesh_H