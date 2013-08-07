#include "EntityFactory.h"
#include "TransformComponent.h"
#include "../Application/Application.h"
#include "../EntitySystem/RenderComponent.h"

Sequencer<EntityId> EntityFactory::seq(1);

EntityId EntityFactory::Create(EntityType entityType)
{
	EntityId entityId = seq.Next();
	switch(entityType)
	{
	case Player:
		TransformComponentStrongPtr transform(new TransformComponent());
		RenderComponentStrongPtr render(new RenderComponent());
		transform->X(0);
		transform->Y(0);
		TextureStrongPtr tex = Application::Instance().Textures()->Get("block");
		sf::Sprite sprite(*tex);
		render->Sprite(sprite);
		World* world = Application::Instance().GetWorld();
		EntityStrongPtr e = world->Create();
		e->AddComponent(transform);
		e->AddComponent(render);
		//Entity::AddComponent<TransformComponent>(entityId,transform);
		//Entity::AddComponent<RenderComponent>(entityId,render);
		break;
	}
	return entityId;
}
