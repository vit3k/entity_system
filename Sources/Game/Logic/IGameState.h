#pragma once
#include "../Application/Clock.h"

/*	Gamestate represents state in which the game is for example main menu, running, init etc. */
class IGameState
{
public:
	//called every frame before entities update
	virtual void Update(Time delta) {}; 
	// called after state is set 
	virtual void Init() {}; 
	// called before state is unset
	virtual void Deinit() {}; 
};

