#include "../Include/Mesh.h"

namespace ResourceEngineTest
{
	Mesh::Mesh(VerticeList verticeList, ColorList colorList, UVList uvList)
		: m_verticeList(verticeList), 
		  m_colorList(colorList),
		  m_uvList(uvList) 
	{
		Setup();
	}

	Mesh::~Mesh()
	{
		Delete();
	}

	void Mesh::Generate()
	{
		GLUtil::GLGenVertexArrays(1, &this->m_vao);
		GLUtil::GLGenBuffers(1, &this->m_vbo);
	}
	void Mesh::Delete()
	{
		GLUtil::GLDeleteVertexArrays(1, &this->m_vao);
		GLUtil::GLDeleteBuffers(1, &this->m_vbo);
	}
	void Mesh::Bind()
	{
		GLUtil::GLBindVertexArray(this->m_vao);
		GLUtil::GLBindBuffer(GL_ARRAY_BUFFER, this->m_vbo);
	}
	void Mesh::Unbind()
	{
		GLUtil::GLBindBuffer(GL_ARRAY_BUFFER, 0);
		GLUtil::GLBindVertexArray(0);
	}
	void Mesh::Setup()
	{
		this->Generate();
		this->Bind();

		std::vector<float> vertexData;

		bool hasColors = this->m_colorList.size() > 0;
		bool hasUVs = this->m_uvList.size() > 0;
		for (unsigned int index = 0; index < this->m_verticeList.size(); index++)
		{
			vertexData.push_back(this->m_verticeList[index].x);
			vertexData.push_back(this->m_verticeList[index].y);
			vertexData.push_back(this->m_verticeList[index].z);

			if (hasColors)
			{
				vertexData.push_back(this->m_colorList[index].r);
				vertexData.push_back(this->m_colorList[index].g);
				vertexData.push_back(this->m_colorList[index].b);
			}

			if (hasUVs)
			{
				vertexData.push_back(this->m_uvList[index].s);
				vertexData.push_back(this->m_uvList[index].t);
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

	void Mesh::Render()
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		Bind();
		glDrawArrays(GL_TRIANGLES, 0, this->m_verticeList.size());
		Unbind();
	}
};