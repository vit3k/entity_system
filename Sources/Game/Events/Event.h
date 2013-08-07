#pragma once

#include <memory>
#include <string>
typedef int EventType;

class Event
{
public:
	static const EventType TYPE;
	virtual std::string ToString() 
	{ 
		std::string ret = std::to_string(TYPE);
		return ret;
		
	};
};

typedef std::shared_ptr<Event> EventStrongPtr;