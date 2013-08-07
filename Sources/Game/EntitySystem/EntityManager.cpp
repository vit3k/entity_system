#include "EntityManager.h"
#include <cstdarg>
#include <bitset>

EntityList& EntityManager::GetAll(int num,...)
{
	va_list arguments;                     
	std::bitset<100> components;
	va_start ( arguments, num );           
	for ( int x = 0; x < num; x++ )
		components.set(x);
	va_end ( arguments );

	EntityList ents;
	for(auto it = entities.begin();it!=entities.end();it++)
	{
		EntityStrongPtr e =  it->second;
		if(e->HasComponents(components))
			ents[it->first] = it->second;
	}
	return ents;
}
void EntityManager::Add(EntityStrongPtr e)
{
	entities[e->GetId()] = e;

}

void EntityManager::AddComponent(EntityStrongPtr e,ComponentStrongPtr c)
{

}