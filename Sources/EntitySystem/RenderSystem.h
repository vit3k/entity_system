#pragma once

#include "System.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include <SFML\Graphics.hpp>

class RenderSystem : public System
{
	sf::RenderWindow* window;
public:
	RenderSystem(sf::RenderWindow* window) : System(2,TransformComponent::ID,RenderComponent::ID)
	{
		this->window = window;
	};
	void ProcessEntity(EntitySP entity);
	void BeforeProcess();
};
