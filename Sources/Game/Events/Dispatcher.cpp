#include "Dispatcher.h"
#include "NewRenderComponentEvent.h"

const EventType Event::TYPE = 0;
const EventType NewRenderComponentEvent::TYPE = 0;

void Dispatcher::Process()
{
	EventsQueue& sourceQueue = eventsQueues[activeQueue];
	activeQueue = (activeQueue+1) % 2;
	eventsQueues[activeQueue].clear();
	while(!sourceQueue.empty())
	{
		EventStrongPtr event = sourceQueue.front();
		sourceQueue.pop_front();
		
			auto listeners = eventListenersMap[event->TYPE];
			for(auto it = listeners.begin(); it != listeners.end(); it++)
			{
				auto listener = *it;
				listener(event);
			}
		
		// listeners for every event - special type 0
		if(event->TYPE != 0) 
		{
			auto listeners2 = eventListenersMap[0];
			for(auto it = listeners2.begin(); it != listeners2.end(); it++)
			{
				auto listener = *it;
				listener(event);
			}
		}
	}
}
Dispatcher::Dispatcher()
{
	activeQueue = 0;
}
bool Dispatcher::Queue(const EventStrongPtr& event)
{
	auto listeners = eventListenersMap.find(event->TYPE);
	if(listeners==eventListenersMap.end())
		return false;

	eventsQueues[activeQueue].push_back(event);
	return true;
}

bool Dispatcher::AddListener(const EventType& eventType,const EventListenerDelegate& listener)
{
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

bool Dispatcher::RemoveListener(const EventType& eventType,const EventListenerDelegate& listener)
{
	auto listenersList = eventListenersMap[eventType];
	for(auto it = listenersList.begin();it!=listenersList.end();it++)
	{
		if((*it) == listener) 
		{
			listenersList.remove(listener);
			return true;
		}
	}
	return false;
}