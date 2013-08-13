#pragma once
#include "Resources/Resources.h"
#include "Events/Dispatcher.h"
#include "Entity/World.h"
#include <SFML\Graphics.hpp>
#include "Clock.h"

class Engine
{
private:
	std::shared_ptr<Dispatcher> dispatcher;
	std::shared_ptr<World> world;
	std::shared_ptr<Resources> resources;
	std::shared_ptr<Clock> clock;
	Engine() {};
	Engine(const Engine&) {};
	Engine& operator=(const Engine&) {};
    ~Engine() {};
	sf::RenderWindow window;
public:
	void Init();
	void Run();
	std::shared_ptr<Dispatcher> GetDispatcher() { return dispatcher; }
	std::shared_ptr<Resources> GetResources() { return resources; }
	static Engine& Instance()
	{
		static Engine instance;
		return instance;
	}
};