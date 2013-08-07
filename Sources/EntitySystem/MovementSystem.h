#pragma once

#include "System.h"
#include "TransformComponent.h"
#include "VelocityComponent.h"

class MovementSystem : public System
{
public:
	MovementSystem() : System(2,TransformComponent::ID,VelocityComponent::ID) {}
	void ProcessEntity(EntitySP entity);
};

typedef std::shared_ptr<MovementSystem> MovementSystemSP;