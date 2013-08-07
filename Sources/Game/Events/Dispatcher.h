#pragma once
#include <list>
#include <map>
#include "Event.h"
#include "FastDelegate.h"

typedef fastdelegate::FastDelegate1<EventStrongPtr> EventListenerDelegate;

typedef std::list<EventStrongPtr> EventsQueue;
typedef std::list<EventListenerDelegate> EventListenersList;
typedef std::map<EventType,EventListenersList> EventListenersMap;

class Dispatcher
{
	EventsQueue eventsQueues[2]; 
	EventListenersMap eventListenersMap;
	int activeQueue;
public:
	Dispatcher();
	void Process();
	bool Queue(const EventStrongPtr& event);
	bool AddListener(const EventType& eventType, const EventListenerDelegate& listener); 
	bool RemoveListener(const EventType& eventType,const EventListenerDelegate& listener);
};

