#pragma once
#include <memory>
#include "Components/Component.h"
#include <vector>
#include "Components/ComponentsBits.h"

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
	void Sync();
	template<typename T>
	std::shared_ptr<T> GetComponent()
	{
		return std::dynamic_pointer_cast<T>(components[T::ID]);
	}
};

typedef std::shared_ptr<Entity> EntitySP;