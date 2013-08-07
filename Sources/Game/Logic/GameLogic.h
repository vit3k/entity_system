#pragma once

#include <map>
#include "../EntitySystem/Entity.h"
#include "IGameState.h"
//typedef std::map<int,EntityStrongPtr> EntitiesMap;

class GameLogic
{
private:
	//EntitiesMap entities;
	IGameState* gameState;
public:
	void Init();
	//void AddEntity(EntityStrongPtr entity);
	void Update(Time delta);
	void ChangeState(IGameState* gameState);
};

