#ifndef ResourceEngine_Data_GLSLResourceData_H
#define ResourceEngine_Data_GLSLResourceData_H

// ResourceEngine Includes
#include "IResourceData.h"

namespace ResourceEngine
{
	namespace Data
	{
		class RESOURCE_ENGINE_API GLSLResourceData : public IResourceData
		{
		private:
			std::string m_code;

		public:
			GLSLResourceData(const std::string& code);
			~GLSLResourceData();

			std::string  Type() const;
			unsigned int Size() const;
			std::string  GetCode() const;
		};
	};
}; 

#endif // ResourceEngine_Data_GLSLResourceData_H
