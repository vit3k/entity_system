#include "RenderControl.h"
#include "../EntitySystem/RenderComponent.h"
#include "../EntitySystem/TransformComponent.h"
#include "../Application/Application.h"

void RenderControl::Render(Time delta,sf::RenderTarget* target)
{
	World* world = Application::Instance().GetWorld();
	auto renderEntities = world->GetEntityManager()->GetAll(1,RenderComponent::ID);

	/*for(auto it = renderEntities.begin();it!=renderEntities.end();it++)
	{
		EntityId entityId = it->first;
		
		if(Entity::HasComponent<TransformComponent>(entityId)) 
		{
			RenderComponentStrongPtr render = Entity::GetComponent<RenderComponent>(entityId);
			TransformComponentStrongPtr transform = Entity::GetComponent<TransformComponent>(entityId);
			sf::Sprite sprite = render->Sprite();
			sprite.setPosition(transform->X(),transform->Y());
			target->draw(sprite);
		}
	}*/
	
}