#ifndef ResourceEngineTest_ShaderProgram_H
#define ResourceEngineTest_ShaderProgram_H

// Standard Includes
#include <string>

// ResourceEngineTest Includes
#include "GLUtil.h"

namespace ResourceEngineTest
{
	class ShaderProgram
	{
	private:
		std::string m_vertexShaderCode; 
		std::string m_fragmentShaderCode;

		GLuint	    m_programHandle;
		GLuint	    m_vertexShaderHandle;
		GLuint	    m_fragmentShaderHandle;

	private:
		GLchar*	GetGLInfoLog();
		void CompileShader(GLuint* handle, std::string code, int type);
		void CompileShaders();
		void LinkShaders();
		void Initialize();

	public:
		ShaderProgram(std::string vertexShaderCode, std::string fragmentShaderCode);

	public:
		void Use();
	};
};

#endif // ResourceEngineTest_ShaderProgram_H