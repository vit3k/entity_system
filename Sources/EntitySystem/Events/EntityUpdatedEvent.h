#pragma once
#include "Event.h"

class EntityUpdatedEvent : public Event 
{
private:
	int entityId;
public:
	static const EventType TYPE;
	virtual EventType GetType() { return TYPE; }

	int GetEntityId() { return entityId; }
	EntityUpdatedEvent(int id):entityId(id) {}
	std::string ToString()
	{
		std::string ret = std::to_string(TYPE) + " EntityUpdatedEvent";
		return ret;
	};
};

typedef std::shared_ptr<EntityUpdatedEvent> EntityUpdatedEventSP;