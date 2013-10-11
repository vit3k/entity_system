#include "PlayerControlSystem.h"
#include "../../Logger.h"
#include "../EntityFactory.h"

#include "../../Math/Utils.h"

void PlayerControlSystem::Process(Time delta)
{
	Logger::Log("PlayerControlSystem::Process");

	if(entitiesNum != 1) // if there is no exactly one player we leave
		return;
	
	EntitySP entity = entities[0];
	auto player = entity->GetComponent<Components::Player>();
	if(input->Attack)
	{
		
	}
	if(input->Forward || input->Backward)
	{
		auto velocity = entity->GetComponent<VelocityComponent>();
		auto transform = entity->GetComponent<TransformComponent>();
		velocity->vX = sin(Math::ToRadians(transform->rotation)) * 100 * player->speed;
		velocity->vY = -cos(Math::ToRadians(transform->rotation)) * 100 * player->speed;
		if(input->Backward)
		{
			velocity->vX = -velocity->vX;
			velocity->vY = -velocity->vY;
		}
	}
	else
	{
		auto velocity = entity->GetComponent<VelocityComponent>();
		velocity->vX = 0;
		velocity->vY = 0;
	}

	if(input->Left) 
	{
		auto transform = entity->GetComponent<TransformComponent>();
		transform->rotation -= delta/1000 * player->rotationSpeed;
	}

	if(input->Right) 
	{
		auto transform = entity->GetComponent<TransformComponent>();
		transform->rotation += delta/1000 * player->rotationSpeed;
	}
}
