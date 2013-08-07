#pragma once

#include "Component.h"
#include <SFML/Graphics.hpp>
#include "../Events/NewRenderComponentEvent.h"
#include "../Application/Application.h"

class RenderComponent : public Component
{
private:
	sf::Sprite sprite;
	
public:
	sf::Sprite Sprite() { return sprite; }
	void Sprite(sf::Sprite s) { sprite = s; }
	static const ComponentId ID;
	/*void Init()
	{
		NewRenderComponentEventStrongPtr e(new NewRenderComponentEvent());
		Application::Instance().Dispatcher()->Queue(e);
	};*/
};

typedef std::shared_ptr<RenderComponent> RenderComponentStrongPtr;