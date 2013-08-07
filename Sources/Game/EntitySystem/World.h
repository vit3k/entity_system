#pragma once
#include "EntityManager.h"
#include "../Application/Sequencer.h"

class World
{
private:
	EntityManager* entityManager;
	Sequencer<int> idSequencer;
public:
	EntityStrongPtr Create();
	EntityManager* GetEntityManager() { return entityManager; }
};