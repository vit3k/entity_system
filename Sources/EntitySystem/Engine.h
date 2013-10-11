#pragma once
#include "Resources/Resources.h"
#include "Events/Dispatcher.h"
#include "Entity/World.h"
#include <SFML\Window.hpp>
#include "Clock.h"
#include "LowLevel\InputController.h"
#include "Entity/EntityFactory.h"
#include "Entity\Systems\RenderSystem.h"

class Engine
{
private:
	std::shared_ptr<Dispatcher> dispatcher;
	std::shared_ptr<World> world;
	std::shared_ptr<Resources> resources;
	std::shared_ptr<Clock> clock;
	std::shared_ptr<InputController> inputController;
	std::shared_ptr<EntityFactory> entityFactory;
	std::shared_ptr<RenderSystem> renderSystem;
	Engine() {};
	Engine(const Engine&) {};
	Engine& operator=(const Engine&) {};
    ~Engine() {};
	sf::Window window;
public:
	void Init();
	void Run();
	void Deinit();
	std::shared_ptr<Dispatcher> GetDispatcher() { return dispatcher; }
	std::shared_ptr<Resources> GetResources() { return resources; }
	std::shared_ptr<EntityFactory> GetEntityFactory() { return entityFactory; }
	std::shared_ptr<Clock> GetClock() { return clock; }
	static Engine& Instance()
	{
		static Engine instance;
		return instance;
	}
};