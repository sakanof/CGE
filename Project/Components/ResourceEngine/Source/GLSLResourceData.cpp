#include "../include/GLSLResourceData.h"


namespace ResourceEngine
{
	namespace Data
	{
		GLSLResourceData::GLSLResourceData(const std::string& code) : m_code(code) {}
		GLSLResourceData::~GLSLResourceData() {}

		unsigned int GLSLResourceData::Size() const { return this->m_code.size() * sizeof(char); }
		std::string  GLSLResourceData::Type() const { return std::string("GLSLResourceData"); }
		std::string  GLSLResourceData::GetCode() const { return this->m_code; }
	}; 
}; 