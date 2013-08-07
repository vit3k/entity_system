#pragma once
#include <memory>
#include "Component.h"
#include <vector>
#include "ComponentsBits.h"

class World;

class Entity 
{
private:
	World* world;
	ComponentSP components[10];
	ComponentsBits componentsBits;
public:
	int ID;
	Entity(World* world,int id);
	void AddComponent(ComponentSP component);
	bool HasComponents(ComponentsBits cb);
	bool HasComponents(int num,...);
	void Update();
	template<typename T>
	std::shared_ptr<T> GetComponent()
	{
		return std::dynamic_pointer_cast<T>(components[T::ID]);
	}
};

typedef std::shared_ptr<Entity> EntitySP;