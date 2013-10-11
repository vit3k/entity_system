#include "EntityFactory.h"
#include <memory>
#include "Components\TransformComponent.h"
#include "Components\VelocityComponent.h"
#include "Components\RenderComponent.h"
#include "Components\Player.h"
#include "Components\Sprite.h"

#define PI 3.14159265

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
	entity->AddComponent(std::make_shared<TransformComponent>(x,y,0.0f));
	entity->AddComponent(std::make_shared<VelocityComponent>(vx,vy));
	entity->AddComponent(std::make_shared<Components::Sprite>("block"));
	entity->AddComponent(std::make_shared<RenderComponent>());
	entity->Sync();
	
	return entity;
}

EntitySP EntityFactory::CreateShip()
{
	EntitySP entity = world->Create();
	TransformComponentSP transform = std::make_shared<TransformComponent>(300.0f,300.0f,0.0f);
	transform->originX = 25;
	transform->originY = 50;
	entity->AddComponent(transform);
	entity->AddComponent(std::make_shared<VelocityComponent>(0.0f,0.0f));
	entity->AddComponent(std::make_shared<Components::Sprite>("ship"));
	entity->AddComponent(std::make_shared<RenderComponent>());
	entity->AddComponent(std::make_shared<Components::Player>());
	entity->Sync();

	return entity;
}

EntitySP EntityFactory::CreateBullet(float x,float y,float rotation)
{
	EntitySP entity = world->Create();
	TransformComponentSP transform = std::make_shared<TransformComponent>(x,y,rotation);
	transform->originX = 5;
	transform->originY = 5;
	entity->AddComponent(transform);
	float vX, vY;
	vX = cos(rotation*PI/180) * 700;
	vY = sin(rotation*PI/180) *700;
	entity->AddComponent(std::make_shared<VelocityComponent>(vX,vY));
	entity->AddComponent(std::make_shared<Components::Sprite>("bullet"));
	entity->AddComponent(std::make_shared<RenderComponent>());
	entity->Sync();

	return entity;
}

