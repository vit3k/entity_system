#include "EntityFactory.h"
#include <memory>
#include "Components\TransformComponent.h"
#include "Components\VelocityComponent.h"
#include "Components\RenderComponent.h"

EntityFactory::EntityFactory(std::shared_ptr<World> world):
	distributionX(0,800),distributionY(0,600),distributionVx(-100,100),distributionVy(-100,100),world(world)
{
	
}

EntitySP EntityFactory::CreateBlock()
{
	float x = distributionX(generator);
	float y = distributionY(generator);
	float vx = distributionVx(generator);
	float vy = distributionVy(generator);

	EntitySP entity = world->Create();
	entity->AddComponent(std::make_shared<TransformComponent>(x,y));
	entity->AddComponent(std::make_shared<VelocityComponent>(vx,vy));
	entity->AddComponent(std::make_shared<RenderComponent>("block"));
	entity->Sync();

	return entity;
}