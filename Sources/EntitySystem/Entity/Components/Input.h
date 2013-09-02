#pragma once

#include "Component.h"

namespace Components 
{
	class Input : public Component
	{
	public:
		static const int ID;
		int GetID() { return ID;}
		bool Throttle;
		bool Break;
		bool LeftSteer;
		bool RightSteer;
		bool Shoot;
		Input(): Throttle(false),Break(false),LeftSteer(false),RightSteer(false),Shoot(false) {};
	};
}