#pragma once
#include <memory>
#include <map>
#include "Entity.h"

typedef std::map<EntityId,ComponentStrongPtr> EntityComponentList;
typedef std::map<ComponentId,EntityComponentList> ComponentList;
typedef std::map<EntityId,EntityStrongPtr> EntityList;

class EntityManager
{
private:
	ComponentList components;	
	EntityList entities;
	
public:
	EntityList& GetAll(int num,...);
	void Add(EntityStrongPtr e);
	void AddComponent(EntityStrongPtr e,ComponentStrongPtr c);
	template <typename T> EntityList GetAll()
	{
		return components[T::ID];
	}
	template<typename T> bool HasComponent(EntityId entity) 
	{
		return components[T::ID].find(entity) != components[T::ID].end();
	};
};