#include "Entity.h"
#include <cstdarg>
#include "World.h"
Entity::Entity(EntityId id,World* world)
{
	this->world = world;
	this->entityManager = world->GetEntityManager();
	this->id = id;
}

bool Entity::HasComponents(int num, ...)
{
	va_list arguments;                     

	va_start ( arguments, num );           
	for ( int x = 0; x < num; x++ )
	{
		if(!components[x])
			return false;
	}
	va_end ( arguments );
	return true;
}

bool Entity::HasComponents(std::bitset<100> componentsBits)
{
	return componentsBits == components;
}