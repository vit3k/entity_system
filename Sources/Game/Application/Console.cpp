#include "Console.h"
#include "../Events/Dispatcher.h"
#include "../Application/Application.h"


void Console::OnEvent(EventStrongPtr e)
{
	lines.push_back(e->ToString());
}
void Console::Init()
{
	// attach to all events
	EventListenerDelegate listener;
	listener.bind(this,&Console::OnEvent);
	Application::Instance().Dispatcher()->AddListener(0,listener);
}