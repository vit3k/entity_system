#pragma once

#include "System.h"
#include "../Components/TransformComponent.h"
#include "../Components/RenderComponent.h"
#include <SFML\Graphics.hpp>
#include "../../Math/Point2.h"

class RenderSystem : public System
{
	sf::RenderWindow* window;
	sf::Sprite sprites[1000];
	float scale;
	Math::Point2f center; 
public:
	RenderSystem(sf::RenderWindow* window) : System(2,TransformComponent::ID,RenderComponent::ID),
		center(400,300),
		scale(10),
		window(window)
	{
	};
	void Process(Time delta);
	void EntityAdded(EntitySP entity);
};
