#ifndef WindowSystem_IEventHandler_H
#define WindowSystem_IEventHandler_H

#include <memory>

#include "IEvent.h"

namespace WindowSystem
{
	class IEventHandler
	{
	public:
		virtual ~IEventHandler() {}
		
		virtual void HandleEvent(std::weak_ptr<IEvent>) = 0;
	};
};

#endif // WindowSystem_IEventHandler_H