#pragma once
#include "Entity.h"
#include "ComponentsBits.h"
#include "EntityUpdatedEvent.h"

class World;

class System
{
private:
	EntitySP entities[100];
	int entitiesNum;
	bool CheckEntity(EntitySP entity);
	ComponentsBits componentsBits;
	World* world;
public:
	System(ComponentsBits cBits);
	System(int num,...);
	void Init(ComponentsBits cBits);
	void SetWorld(World* w) {world = w; }
	void Process();
	void OnEntityUpdated(EventSP e);
	virtual void ProcessEntity(EntitySP entity) {};
	virtual void BeforeProcess() {};
	
};

typedef std::shared_ptr<System> SystemSP;