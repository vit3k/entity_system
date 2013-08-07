#pragma once
#include <list>
#include <map>
#include "Event.h"
#include "FastDelegate.h"

typedef fastdelegate::FastDelegate1<EventSP> EventListenerDelegate;

typedef std::list<EventSP> EventsQueue;
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
	bool Queue(const EventSP& event);
	template <typename T>
	bool AddListener(const EventListenerDelegate& listener)
	{
		EventType eventType = T::TYPE;
		if(eventListenersMap.find(eventType)==eventListenersMap.end()) 
		{
			EventListenersList list;
			eventListenersMap[eventType] = list;
		}
		auto listenersList = eventListenersMap[eventType];

		for(auto it = listenersList.begin();it!=listenersList.end();it++)
		{
			if((*it) == listener)
				return false;
		}
		eventListenersMap[eventType].push_back(listener);
		return true;
	}
	bool RemoveListener(const EventType& eventType,const EventListenerDelegate& listener);
};

