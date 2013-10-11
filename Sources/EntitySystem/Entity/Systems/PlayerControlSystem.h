#pragma once

#include "System.h"
#include "../Components/Player.h"
#include "../Components/VelocityComponent.h"
#include "../../Clock.h"
#include "../../Engine.h"
#include "../../Events/ThrottleEvent.h"
#include "../Components/TransformComponent.h"

class PlayerControlSystem : public System
{
private:
	InputControllerSP input;
public:
	PlayerControlSystem(InputControllerSP inputController) : System(3,Components::Player::ID,VelocityComponent::ID,TransformComponent::ID)
	{
		this->input = inputController;
		//Engine::Instance().GetDispatcher()->AddListener<ThrottleEvent>(EventListenerDelegate(this,&PlayerControlSystem::OnThrottle));
	}
	void Process(Time delta);
	
};

typedef std::shared_ptr<PlayerControlSystem> PlayerControlSystemSP;