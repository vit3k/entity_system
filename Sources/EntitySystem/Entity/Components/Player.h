#pragma once
#include "Component.h"
#include "..\..\Clock.h"

namespace Components 
{
	class Player : public Component 
	{
	public:
		static const int ID;
		int GetID() { return ID;};
		Time lastShoot;
		Player():lastShoot(0),speed(5),rotationSpeed(1.5f){};
		float speed;
		float rotationSpeed;
	};

	typedef std::shared_ptr<Player> PlayerSP;
}