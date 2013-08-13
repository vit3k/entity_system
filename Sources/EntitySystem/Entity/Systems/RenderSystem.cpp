#include "RenderSystem.h"
#include "../../Logger.h"
#include "../../Engine.h"
#include "../../Resources/TextureResource.h"

void RenderSystem::ProcessEntity(EntitySP entity,Time delta)
{
	Logger::Log("RenderSystem::ProcessEntity "+std::to_string(entity->ID));
	TransformComponentSP transform = entity->GetComponent<TransformComponent>();
	auto test = Engine::Instance().GetResources();
	//RenderComponentSP render = entity->GetComponent<RenderComponent>();
	sf::Sprite sprite = sprites[entity->ID];
	sprite.setPosition(transform->x,transform->y);
	window->draw(sprite);
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

void RenderSystem::EntityAdded(EntitySP entity)
{
	RenderComponentSP render = entity->GetComponent<RenderComponent>();
	auto texture = Engine::Instance().GetResources()->Get<TextureResource>(render->GetSpriteName());
	sf::Sprite sprite(*(texture->Get()));
	sprites[entity->ID] = sprite;
}