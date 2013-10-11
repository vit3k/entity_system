#pragma once
#include "Event.h"

class ThrottleEvent : public Event 
{
private:
	int entityId;
public:
	static const EventType TYPE;
	virtual EventType GetType() { return TYPE; }
	ThrottleEvent() {}
	int GetEntityId() { return entityId; }
	ThrottleEvent(int id):entityId(id) {}
	std::string ToString()
	{
		std::string ret = std::to_string(TYPE) + " ThrottleEvent";
		return ret;
	};
};

typedef std::shared_ptr<ThrottleEvent> ThrottleEventSP;