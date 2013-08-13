#pragma once
#include "../Entity.h"
#include "../Components/ComponentsBits.h"
#include "../../Events/EntityUpdatedEvent.h"
#include "../../Clock.h"

class World;

class System
{
private:
	EntitySP entities[1000];
	int entitiesNum;
	bool CheckEntity(EntitySP entity);
	ComponentsBits componentsBits;
	World* world;
public:
	System(ComponentsBits cBits);
	System(int num,...);
	void Init(ComponentsBits cBits);
	void SetWorld(World* w) {world = w; }
	void Process(Time delta);
	void OnEntityUpdated(EventSP e);
	virtual void ProcessEntity(EntitySP entity,Time delta) {};
	virtual void BeforeProcess() {};
	virtual void AfterProcess() {};
	virtual void EntityAdded(EntitySP entity) {};
	
};

typedef std::shared_ptr<System> SystemSP;