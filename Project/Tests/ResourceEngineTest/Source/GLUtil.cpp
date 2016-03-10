#include "..\Include\GLUtil.h"


namespace ResouceEngineTest
{
	void GLUtil::GetActiveUniforms(size_t programHandle)
	{
	}

	void GLUtil::GLGenVertexArrays(size_t count, size_t* vao)
	{
		glGenVertexArrays(count, (GLuint*)vao);
	}

	void GLUtil::GLGenBuffers(size_t count, size_t* vbo)
	{
		glGenBuffers(count, (GLuint*)vbo);
	}

	void GLUtil::GLDeleteVertexArrays(size_t count, size_t* vao)
	{
		glDeleteVertexArrays(count, vao);
	}

	void GLUtil::GLDeleteBuffers(size_t count, size_t* vbo)
	{
		glDeleteBuffers(count, vbo);
	}

	void GLUtil::GLBufferData(size_t target, size_t size, const void* data, size_t usage)
	{
		glBufferData(target, size, data, usage);
	}

	void GLUtil::GLBindVertexArray(size_t vao)
	{
		glBindVertexArray(vao);
	}

	void GLUtil::GLBindBuffer(size_t target, size_t vbo)
	{
		glBindBuffer(target, vbo);
	}

	void GLUtil::GLEnableVertexAttribArray(size_t index)
	{
		glEnableVertexAttribArray(index);
	}

	void GLUtil::GLVertexAttribPointer(size_t index, size_t size, short type, bool isNormalized, size_t stride, size_t offset)
	{
		glVertexAttribPointer(index, size, type, isNormalized, stride, (void*)offset);
	}

	void GLUtil::GLGetProgramiv(size_t programHandle, int glInfoLogLength, int* logLength)
	{
		glGetProgramiv(programHandle, glInfoLogLength, logLength);
	}

	int GLUtil::CreateProgram()
	{
		return glCreateProgram();
	}

	int GLUtil::GLType_Byte()			{ return GL_BYTE; }
	int GLUtil::GLType_Short()			{ return GL_SHORT; }
	int GLUtil::GLType_Int()			{ return GL_INT; }
	int GLUtil::GLType_Float()			{ return GL_FLOAT; }
	int GLUtil::GLType_Double()			{ return GL_DOUBLE; }
	int GLUtil::GLType_UnsignedByte()	{ return GL_UNSIGNED_BYTE; }
	int GLUtil::GLType_UnsignedShort()	{ return GL_UNSIGNED_SHORT; }
	int GLUtil::GLType_UnsignedInt()	{ return GL_UNSIGNED_INT; }
};