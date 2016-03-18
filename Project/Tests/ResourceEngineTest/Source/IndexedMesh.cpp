#include "../Include/IndexedMesh.h"

namespace ResourceEngineTest
{
	IndexedMesh::IndexedMesh(VerticeList verticeList, IndexList indexList, ColorList colorList, UVList uvList)
		: m_indexList(indexList),
		  m_verticeList(verticeList),
		  m_colorList(colorList),
		  m_uvList(uvList)
	{
		Setup();
	}

	IndexedMesh::~IndexedMesh()
	{
		Delete();
	}

	void IndexedMesh::Generate()
	{
		GLUtil::GLGenBuffers(1, &this->m_vao);
		GLUtil::GLGenBuffers(1, &this->m_ibo);
	}
	void IndexedMesh::Delete()
	{
		GLUtil::GLDeleteBuffers(1, &this->m_vao);
		GLUtil::GLDeleteBuffers(1, &this->m_ibo);
	}
	void IndexedMesh::Bind()
	{
		GLUtil::GLBindBuffer(GL_ARRAY_BUFFER, this->m_vao);
		GLUtil::GLBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_ibo);
	}
	void IndexedMesh::Unbind()
	{
		GLUtil::GLBindBuffer(GL_ARRAY_BUFFER, 0);
		GLUtil::GLBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	void IndexedMesh::Setup()
	{
		this->Generate();
		this->Bind();

		std::vector<float> vertexData;

		bool hasColors = this->m_colorList.size() > 0;
		bool hasUVs = this->m_uvList.size() > 0;
		for (unsigned int index = 0; index < this->m_verticeList.size(); index += 3)
		{
			vertexData.push_back(this->m_verticeList[index + 0]);
			vertexData.push_back(this->m_verticeList[index + 1]);
			vertexData.push_back(this->m_verticeList[index + 2]);

			if (hasColors)
			{
				vertexData.push_back(this->m_colorList[index + 0]);
				vertexData.push_back(this->m_colorList[index + 1]);
				vertexData.push_back(this->m_colorList[index + 2]);
			}

			if (hasUVs)
			{
				vertexData.push_back(this->m_uvList[index + 0]);
				vertexData.push_back(this->m_uvList[index + 1]);
			}
		}

		unsigned int vertexSize = 3;
		unsigned int vertexByteSize = 3;
		if (hasColors)
			vertexSize += 3;
		if (hasUVs)
			vertexSize += 2;

		// Allocates memory in the GPU and transfer the vertex information to it
		GLUtil::GLBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float), &vertexData[0], GL_STATIC_DRAW);
		GLUtil::GLBufferData(GL_ELEMENT_ARRAY_BUFFER, this->m_indexList.size() * sizeof(unsigned int), &this->m_indexList[0], GL_STATIC_DRAW);

		GLuint verticesPosition = 0;
		GLUtil::GLEnableVertexAttribArray(verticesPosition);
		GLUtil::GLVertexAttribPointer(verticesPosition, 3, GL_FLOAT, GL_TRUE, vertexSize * sizeof(GLfloat), 0);

		if (hasColors)
		{
			GLuint colorPosition = 1;
			GLUtil::GLEnableVertexAttribArray(colorPosition);
			GLUtil::GLVertexAttribPointer(colorPosition, 3, GL_FLOAT, GL_TRUE, vertexSize * sizeof(GLfloat), vertexByteSize * sizeof(GLfloat));
			vertexByteSize += 3;
		}

		if (hasUVs)
		{
			GLuint texCoordPosition = 2;
			GLUtil::GLEnableVertexAttribArray(texCoordPosition);
			GLUtil::GLVertexAttribPointer(texCoordPosition, 2, GL_FLOAT, GL_TRUE, vertexSize * sizeof(GLfloat), vertexByteSize * sizeof(GLfloat));
		}

		this->Unbind();
	}

	void IndexedMesh::Render()
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		Bind();
		glDrawElements(GL_TRIANGLES, this->m_indexList.size(), GL_UNSIGNED_INT, 0);
		Unbind();
	}
};