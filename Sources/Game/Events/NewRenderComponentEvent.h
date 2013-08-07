#pragma once
#include "Event.h"

class NewRenderComponentEvent : Event 
{
public:
	static const EventType TYPE;
	std::string ToString()
	{
		std::string ret = std::to_string(TYPE) + " NewRenderComponent";
		return ret;
	};
};

typedef std::shared_ptr<NewRenderComponentEvent> NewRenderComponentEventStrongPtr;