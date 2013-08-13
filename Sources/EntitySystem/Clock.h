#pragma once

#include <SFML/System/Clock.hpp>

typedef unsigned long Time;

class Clock
{
private:
	sf::Clock clock;
	sf::Time lastTime;
	bool paused;
	float multiplier;
	float oldMultiplier;
public:
	Time GetDelta();
	Time GetElapsed();
	void Pause();
	void Restore();
	Clock(void);
	~Clock(void);
};

