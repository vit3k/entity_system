#include "MovementSystem.h"
#include "Logger.h"

void MovementSystem::ProcessEntity(EntitySP entity)
{
	Logger::Log("MovementSystem::ProcessEntity "+std::to_string(entity->ID));
	TransformComponentSP transform = entity->GetComponent<TransformComponent>();
	VelocityComponentSP velocity = entity->GetComponent<VelocityComponent>();
	transform->x += velocity->vX;
	transform->y += velocity->vY;	
}