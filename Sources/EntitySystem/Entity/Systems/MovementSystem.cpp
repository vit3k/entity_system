#include "MovementSystem.h"
#include "../../Logger.h"

void MovementSystem::ProcessEntity(EntitySP entity,Time delta)
{
	Logger::Log("MovementSystem::ProcessEntity "+std::to_string(entity->ID));
	TransformComponentSP transform = entity->GetComponent<TransformComponent>();
	VelocityComponentSP velocity = entity->GetComponent<VelocityComponent>();
	transform->x += (velocity->vX * delta/1000000);
	transform->y += (velocity->vY * delta/1000000);

	if(transform->x < 0 || transform->x > 800)
		velocity->vX = -velocity->vX;
	
	if(transform->y < 0 || transform->y > 600)
		velocity->vY = -velocity->vY;

	if(transform->x < 0)
		transform->x = 0;
	if(transform->x > 800)
		transform->x = 800;
	if(transform->y < 0)
		transform->y = 0;
	if(transform->y > 600)
		transform->y = 600;
}