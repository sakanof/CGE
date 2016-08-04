#ifndef WindowSystem_IEventDispatcher_H
#define WindowSystem_IEventDispatcher_H

#include "IEventHandler.h"

namespace WindowSystem
{
	class IEventDispatcher
	{
	public:
		virtual ~IEventDispatcher() {}
		
		virtual void RegisterHandler(std::string eventType, std::shared_ptr<IEventHandler>) = 0;
		virtual void RegisterEvent(std::shared_ptr<IEvent>) = 0;
		virtual void DispatchEvents() = 0;
	};
};

#endif // WindowSystem_IEventDispatcher_H