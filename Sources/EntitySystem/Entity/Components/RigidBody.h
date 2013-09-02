#pragma once
#include "Component.h"
#include <SFML/System/Vector2.hpp>

namespace Components
{
	class RigidBody : public Component
	{
	public:
		float mass;
		float a;
		sf::Vector2f force;
		sf::Vector2f velocity;
	};
}