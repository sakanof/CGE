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
		public:
			typedef std::weak_ptr<IResourceData> WeakPointer;
			typedef std::shared_ptr<IResourceData> StrongPointer;

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

		using SharedGLSLResourceData       = GLSLResourceData::StrongPointer;
		using WeakGLSLResourceData         = GLSLResourceData::WeakPointer;
		using SharedGLSLResourceDataVector = std::vector < SharedGLSLResourceData >;
		using WeakGLSLResourceDataVector   = std::vector < WeakGLSLResourceData >;
		using SharedGLSLResourceDataList   = std::list < SharedGLSLResourceData >;
		using WeakGLSLResourceDataList     = std::list < WeakGLSLResourceData >;
	};
}; 

#endif // ResourceEngine_Data_GLSLResourceData_H
