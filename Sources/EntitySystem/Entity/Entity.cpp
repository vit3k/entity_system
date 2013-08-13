#include "Entity.h"
#include "World.h"
#include "Components/ComponentsBits.h"
#include <cstdarg>

Entity::Entity(World* world,int id)
{
	this->world = world;
	this->ID = id;
}

void Entity::Sync()
{
	world->EntityUpdate(ID);
}

bool Entity::HasComponents(int num,...)
{
	va_list arguments;                     
	va_start ( arguments, num );           
	ComponentsBits cb = ComponentsBits(num,arguments);
	va_end ( arguments );
	return HasComponents(cb);	
}

bool Entity::HasComponents(ComponentsBits cb)
{
	for(unsigned int i=0;i<cb.size();i++)
	{
		if(cb[i] && !componentsBits[i])
			return false;
	}
	return true;
}
void Entity::AddComponent(ComponentSP component)
{
	components[component->GetID()] = component;
	componentsBits.AddComponent(component->GetID());
}