#ifndef ResourceEngineTest_GLUtil_H
#define ResourceEngineTest_GLUtil_H

// Third Party Include
#include <Glew\include\glew.h>
#include <GL\GL.h>

namespace ResourceEngineTest
{
	class GLUtil
	{
	public:
		static void GetActiveUniforms(size_t programHandle);

		static void GLGenVertexArrays(size_t count, size_t* vao);

		static void GLGenBuffers(size_t count, size_t* vbo);

		static void GLDeleteVertexArrays(size_t count, size_t* vao);

		static void GLDeleteBuffers(size_t count, size_t* vbo);

		static void GLBufferData(size_t target, size_t size, const void* data, size_t usage);

		static void GLBindVertexArray(size_t vao);

		static void GLBindBuffer(size_t target, size_t vbo);

		static void GLEnableVertexAttribArray(size_t index);

		static void GLVertexAttribPointer(size_t index, size_t size, short type, bool isNormalized, size_t stride, size_t offset);

		static void GLGetProgramiv(size_t programHandle, int glInfoLogLength, int* logLength);

		static int CreateProgram();

		static int GLType_Byte();
		static int GLType_Short();
		static int GLType_Int();
		static int GLType_Float();
		static int GLType_Double();
		static int GLType_UnsignedByte();
		static int GLType_UnsignedShort();
		static int GLType_UnsignedInt();
	};
};
#endif // ResourceEngineTest_GLUtil_H
