#pragma once

#include "Entity.h"
#include <random> 
#include "World.h"

class EntityFactory
{
private:
	std::default_random_engine generator;
	std::uniform_real_distribution<float> distributionX;
	std::uniform_real_distribution<float> distributionY;
	std::uniform_real_distribution<float> distributionVy;
	std::uniform_real_distribution<float> distributionVx;
	std::shared_ptr<World> world;
public:
	EntitySP CreateBlock();
	EntitySP CreateShip();
	EntityFactory(std::shared_ptr<World> world);
};