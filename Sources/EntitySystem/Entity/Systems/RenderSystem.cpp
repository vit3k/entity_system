#include "RenderSystem.h"
#include "../../Logger.h"
#include "../../Engine.h"
#include "../../Resources/TextureResource.h"

void RenderSystem::Process(Time delta)
{
	window->clear();
	for(int i = 0; i < entitiesNum; i++)
	{
		EntitySP entity = entities[i];
		TransformComponentSP transform = entity->GetComponent<TransformComponent>();
		auto test = Engine::Instance().GetResources();
		sf::Sprite sprite = sprites[entity->ID];

		auto position = transform->position;
		
		sprite.setPosition(transform->x,transform->y);
		window->draw(sprite);
	}
	window->display();
}

void RenderSystem::EntityAdded(EntitySP entity)
{
	RenderComponentSP render = entity->GetComponent<RenderComponent>();
	auto texture = Engine::Instance().GetResources()->Get<TextureResource>(render->GetSpriteName());
	sf::Sprite sprite(*(texture->Get()));
	sprites[entity->ID] = sprite;
}