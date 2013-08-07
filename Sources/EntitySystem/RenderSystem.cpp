#include "RenderSystem.h"
#include "Logger.h"

void RenderSystem::ProcessEntity(EntitySP entity)
{
	Logger::Log("RenderSystem::ProcessEntity "+std::to_string(entity->ID));
	TransformComponentSP transform = entity->GetComponent<TransformComponent>();
	Logger::Log(std::to_string(transform->x)+" "+std::to_string(transform->y));	
}

void RenderSystem::BeforeProcess()
{
	Logger::Log("Render start");

}