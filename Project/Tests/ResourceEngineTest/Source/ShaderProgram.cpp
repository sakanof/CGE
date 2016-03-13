#include "../Include/ShaderProgram.h"

namespace ResourceEngineTest
{
	ShaderProgram::ShaderProgram(std::string vertexShaderCode, std::string fragmentShaderCode)
		: m_vertexShaderCode(vertexShaderCode),
		m_fragmentShaderCode(fragmentShaderCode)
	{
		Initialize();
	}

	GLchar*	ShaderProgram::GetGLInfoLog()
	{
		GLint logLength;
		GLchar *log;

		GLUtil::GLGetProgramiv(this->m_programHandle, GL_INFO_LOG_LENGTH, &logLength);
		if (logLength > 0)
		{
			log = (GLchar *)malloc(logLength);

			GLsizei written;
			glGetProgramInfoLog(this->m_programHandle, logLength, &written, log);
		}
		else
		{
			log = "\0";
		}

		return log;
	}

	void ShaderProgram::CompileShader(GLuint* handle, std::string code, int type)
	{
		*handle = glCreateShader(type);

		if (*handle == 0)
			throw std::exception("Error compiling the shader");


		const GLchar *codeArray[] = { code.c_str() };

		//Copia o codigo fonte para a memoria interna do opengl
		glShaderSource(*handle, 1, codeArray, NULL);
		glCompileShader(*handle);


		GLint result;
		glGetShaderiv(*handle, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint logLength;
			GLchar *log;

			glGetShaderiv(*handle, GL_INFO_LOG_LENGTH, &logLength);
			if (logLength > 0)
			{
				log = (GLchar *)malloc(logLength);

				GLsizei written;
				glGetShaderInfoLog(*handle, logLength, &written, log);
			}
			else
			{
				log = "\0";
			}
			std::string logString = std::string(log);
			free(log);

			throw new std::exception(logString.c_str());
		}
	}

	void ShaderProgram::CompileShaders()
	{
		CompileShader(&this->m_vertexShaderHandle, this->m_vertexShaderCode, GL_VERTEX_SHADER);
		CompileShader(&this->m_fragmentShaderHandle, this->m_vertexShaderCode, GL_FRAGMENT_SHADER);
	}
	
	void ShaderProgram::LinkShaders()
	{
		this->m_programHandle = GLUtil::CreateProgram();

		if (this->m_programHandle == 0)
			throw new std::exception(GetGLInfoLog());

		glAttachShader(this->m_programHandle, this->m_vertexShaderHandle);
		glAttachShader(this->m_programHandle, this->m_fragmentShaderHandle);

		glLinkProgram(this->m_programHandle);

		GLint status;
		glGetProgramiv(this->m_programHandle, GL_LINK_STATUS, &status);

		if (status == GL_FALSE)
			throw new std::exception(GetGLInfoLog());
		else 
			glUseProgram(this->m_programHandle);
	}

	void ShaderProgram::Initialize()
	{
		CompileShaders();
		LinkShaders();
	}

	void ShaderProgram::Use()
	{
		if (this->m_programHandle <= 0)
			return;

		glUseProgram(this->m_programHandle);
	}
};