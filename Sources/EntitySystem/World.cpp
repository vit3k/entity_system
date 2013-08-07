#include "World.h"
#include "EntityUpdatedEvent.h"
#include "Logger.h"

EntitySP World::Create()
{
	EntitySP entity(new Entity(this,entitySeq.Next()));
	entities[entity->ID] = entity;
	return entity;
}
void World::EntityUpdate(int id)
{
	Dispatcher::Queue(EntityUpdatedEventSP(new EntityUpdatedEvent(id)));
}
SystemSP World::AddSystem(SystemSP system)
{
	systems[systemSeq.Next()] = system;
	system->SetWorld(this);
	return system;
}

void World::Update()
{
	Logger::Log("World::Update start");
	for(int i = 0;i<=systemSeq.Current();i++)
		systems[i]->Process();
	Logger::Log("World::Update end");
}