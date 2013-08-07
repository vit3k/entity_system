#pragma once
#include "../Entity.h"
#include "../Components/ComponentsBits.h"
#include "../../Events/EntityUpdatedEvent.h"

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
	virtual void AfterProcess() {};
	
};

typedef std::shared_ptr<System> SystemSP;