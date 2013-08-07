#include "System.h"
#include "../World.h"
#include "../../Logger.h"
#include <cstdarg>
#include "../../Engine.h"

void System::OnEntityUpdated(EventSP e)
{
	Logger::Log("System::OnEntityUpdated");
	EntityUpdatedEventSP updateEvent = std::dynamic_pointer_cast<EntityUpdatedEvent>(e);
	EntitySP entity = world->Get(updateEvent->GetEntityId());
	if(CheckEntity(entity)) {
		entities[entitiesNum] = entity;
		entitiesNum++;
	}
}
bool System::CheckEntity(EntitySP entity)
{
	return entity->HasComponents(componentsBits);
}
void System::Init(ComponentsBits cBits)
{
	componentsBits = cBits;
	entitiesNum = 0;
	
	Engine::Instance().GetDispatcher()->AddListener<EntityUpdatedEvent>(EventListenerDelegate(this,&System::OnEntityUpdated));
}
System::System(ComponentsBits cBits)
{
	Init(cBits);
}

void System::Process()
{
	BeforeProcess();
	for(int i = 0; i < entitiesNum; i++)
	{
		ProcessEntity(entities[i]);
	}
	AfterProcess();
}

System::System(int num,...)
{
	va_list arguments;                     
	va_start ( arguments, num );           
	ComponentsBits cb = ComponentsBits(num,arguments);
	va_end ( arguments );
	Init(cb);
}