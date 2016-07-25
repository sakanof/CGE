#ifndef ResourceEngine_IResourceData_H
#define ResourceEngine_IResourceData_H

// Standard Includes
#include <string>

// ResourceEngine Includes
#include "TypesExport.h"
#include "IResourceObserver.h"

namespace ResourceEngine
{
	namespace Data
	{
		class RESOURCE_ENGINE_API IResourceData
		{
		public:
			typedef std::weak_ptr<IResourceData> WeakPointer;
			typedef std::shared_ptr<IResourceData> StrongPointer;

		protected:
			IResourceObserver* m_observer;
		public:
			IResourceData(IResourceObserver* observer) : m_observer(observer) {}
			virtual ~IResourceData() 
			{
				this->m_observer->MemoryHasBeenFreed(Size());
			}

		public:
			/**
			*	\brief Gets the resource data type.
			*
			*	\return A string that identifies the type of resource data.
			**/
			virtual std::string  Type() const = 0;
			
			/**
			*	\brief Gets the size of the resource data.
			*
			*	\return The size of the resource data.
			**/
			virtual unsigned int Size() const { return 0; };
		};

		using SharedResourceData       = IResourceData::StrongPointer;
		using WeakResourceData         = IResourceData::WeakPointer;
		using SharedResourceDataVector = std::vector < SharedResourceData >;
		using WeakResourceDataVector   = std::vector < WeakResourceData >;
		using SharedResourceDataList   = std::list < SharedResourceData >;
		using WeakResourceDataList     = std::list < WeakResourceData >;
	}
};

#endif // ResourceEngine_IResourceData_H