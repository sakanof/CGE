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
			GLSLResourceData(IResourceObserver* observer, const std::string& code);
			~GLSLResourceData();

			std::string  Type() const;
			unsigned int Size() const;
			std::string  GetCode() const;
		};
		ExplicitExportDataContainers(GLSLResourceData)

		using SharedGLSLResourceData = std::shared_ptr < GLSLResourceData >;
		using WeakGLSLResourceData   = std::weak_ptr < GLSLResourceData >;
		using GLSLResourceDataVector = std::vector < std::weak_ptr<GLSLResourceData> >;
		using GLSLResourceDataList   = std::list < std::weak_ptr<GLSLResourceData> >;
	};
}; 

#endif // ResourceEngine_Data_GLSLResourceData_H
