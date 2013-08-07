#pragma once
#include "Control.h"
#include "../Events/Event.h"
#include <list>

class ConsoleControl :
	public Control
{
private:
	sf::Font font;
public:
	void Render(Time delta,sf::RenderTarget* target);
	void Init();
};

typedef std::shared_ptr<ConsoleControl> ConsoleControlStrongPtr;
