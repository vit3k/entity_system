#pragma once
//#include "Bag.h"
#include "Entity.h"
#include <vector>
#include "../Seq.h"
#include "Systems/System.h"

#include "../Events/Dispatcher.h"

class World
{
private:
	//std::vector<EntitySP> entities;
	EntitySP entities[100];
	Seq<int> entitySeq;
	Seq<int> systemSeq;
	SystemSP systems[20];
	
public:
	EntitySP Get(int id) { return entities[id]; }
	SystemSP AddSystem(SystemSP system);
	EntitySP Create();
	void EntityUpdate(int id);
	void Update();
};