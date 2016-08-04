#ifndef WindowSystem_IEvent_H
#define WindowSystem_IEvent_H

#include <string>

namespace WindowSystem
{
	class IEvent
	{
	public:
		virtual ~IEvent() {}
		virtual std::string Type() const = 0;
	};
};

#endif // WindowSystem_IEvent_H