#include "ConsoleControl.h"
#include "../Application/Application.h"
#include <algorithm>

void ConsoleControl::Render(Time delta,sf::RenderTarget* target)
{
	auto lines = Application::Instance().Console()->Lines();
	for(int i = 0;i<std::min<int>(5,lines.size());i++)
	{
		sf::Text text(lines[i], font);
		text.setCharacterSize(10);
		text.setColor(sf::Color::White);
		text.setPosition(5,i*20);
		target->draw(text);
	}
	
	// Create a text
	
}

void ConsoleControl::Init()
{
	auto res = Application::Instance().Resources()->Get("font");
	font.loadFromMemory(res->Buffer(),res->Size());
}