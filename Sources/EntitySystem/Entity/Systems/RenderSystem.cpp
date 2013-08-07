#include "RenderSystem.h"
#include "../../Logger.h"

void RenderSystem::ProcessEntity(EntitySP entity)
{
	Logger::Log("RenderSystem::ProcessEntity "+std::to_string(entity->ID));
	TransformComponentSP transform = entity->GetComponent<TransformComponent>();
	
}

void RenderSystem::BeforeProcess()
{
	Logger::Log("Render start");
	window->clear();
}

void RenderSystem::AfterProcess()
{
	Logger::Log("Render flush");
	window->display();
}