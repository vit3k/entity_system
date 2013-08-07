#include "Dispatcher.h"
#include "EntityUpdatedEvent.h"
#include "../Logger.h"

const EventType Event::TYPE = 0;
const EventType EntityUpdatedEvent::TYPE = 1;

/*int Dispatcher::activeQueue = 0;
EventListenersMap Dispatcher::eventListenersMap;
EventsQueue Dispatcher::eventsQueues[2]; 
*/
void Dispatcher::Process()
{
	Logger::Log("Dispatcher::Process: start");
	EventsQueue& sourceQueue = eventsQueues[activeQueue];
	activeQueue = (activeQueue+1) % 2;
	eventsQueues[activeQueue].clear();
	while(!sourceQueue.empty())
	{
		EventSP event = sourceQueue.front();
		sourceQueue.pop_front();
		
			auto listeners = eventListenersMap[event->GetType()];
			for(auto it = listeners.begin(); it != listeners.end(); it++)
			{
				auto listener = *it;
				Logger::Log("Dispatcher::Process: "+event->ToString());
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
	Logger::Log("Dispatcher::Process: end");
}
Dispatcher::Dispatcher()
{
	activeQueue = 0;
}
bool Dispatcher::Queue(const EventSP& event)
{
	EventType et = event->GetType();
	auto listeners = eventListenersMap.find(et);
	if(listeners==eventListenersMap.end())
		return false;

	eventsQueues[activeQueue].push_back(event);
	Logger::Log("Dispatcher::Queue: "+event->ToString());
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