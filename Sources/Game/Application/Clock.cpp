#include "Clock.h"


Clock::Clock(void)
{
	clock.restart();
	lastTime = clock.getElapsedTime();
	paused = false;
}


Clock::~Clock(void)
{
}

Time Clock::GetElapsed() 
{
	sf::Time currentTime = clock.getElapsedTime();
	return currentTime.asMicroseconds();
}
Time Clock::GetDelta()
{
	sf::Time currentTime = clock.getElapsedTime();

	return (currentTime - lastTime).asMicroseconds() * multiplier;
}

void Clock::Pause()
{
	paused = true;
	oldMultiplier = multiplier;
	multiplier = 0;
}

void Clock::Restore()
{
	multiplier = oldMultiplier;
	paused = false;
}