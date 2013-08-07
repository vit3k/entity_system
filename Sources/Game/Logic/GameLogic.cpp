#include "GameLogic.h"
#include "../EntitySystem/EntityFactory.h"

void GameLogic::Init()
{
	/*	for now it's empty gamestate 
		in fact we should not instantiate interface :/
	*/
	gameState = new IGameState();
	gameState->Init();

	EntityFactory::Create(Player);

}

/*void GameLogic::AddEntity(EntityStrongPtr entity)
{
	if(entities.find(entity->Id())!=entities.end()) // this entity already is in game logic
		return;
	entities[entity->Id()] = entity;
}*/

void GameLogic::Update(Time delta)
{
	gameState->Update(delta);

	/* iterate over all entities and update them */
	/*EntitiesMap::iterator it;
	for(it=entities.begin();it!=entities.end();it++)
	{
		(*it).second->Update(delta);
	}*/
	
}

void GameLogic::ChangeState(IGameState* gameState)
{
	/* deinit previous gamestate and init new one */
	this->gameState->Deinit();
	this->gameState = gameState;
	this->gameState->Init();
}