#ifndef ResourceEngine_IResourceObserver_H
#define ResourceEngine_IResourceObserver_H

// ResourceEngine Includes
#include "ResourceEngineSetup.h"

namespace ResourceEngine
{
	class RESOURCE_ENGINE_API IResourceObserver
	{
	public:
		IResourceObserver() {}
		virtual ~IResourceObserver() {}

		/**
		*	\brief An observer method that is called in the ResourceHandle destructor, meaning that the reference count of a
		*	resource handle is now zero and the resource has been deleted so observer must know that the resource's allocated 
		*	memory is now free.
		*
		*	\param size The size of the resource that has been deleted.
		**/
		void MemoryHasBeenFreed(__int64 deleteResourceSize);
	};
};

#endif // ResourceEngine_IResourceObserver_H