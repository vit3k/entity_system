#pragma once

#include "Entity.h"
#include "../Application/Sequencer.h"

typedef enum EntityType 
{
	Player
};

class EntityFactory
{
private:
	static Sequencer<EntityId> seq;
public:
	static EntityId Create(EntityType entityType);
};

