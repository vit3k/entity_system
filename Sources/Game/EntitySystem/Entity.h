#pragma once

#include <map>
#include <bitset>
#include "Component.h"

class World;
class EntityManager;


typedef unsigned int EntityId;

class Entity
{
private:
	World* world;
	EntityManager* entityManager;
	EntityId id;
	std::bitset<100> components;
public:
	EntityId GetId() { return id; }
	Entity(EntityId id,World* world);
	template<typename T> void AddComponent(std::shared_ptr<T> component) 
	{
		entityManager->AddComponent(this,component);
		components.set(component->ID);
	}
	template<typename T> std::shared_ptr<T> GetComponent()
	{
		return std::dynamic_pointer_cast<T>(entityManager->components[T::ID][GetId()]);
	}
	bool HasComponents(int num, ...);
	bool HasComponents(std::bitset<100> componentsBits);
};

typedef std::shared_ptr<Entity> EntityStrongPtr;

