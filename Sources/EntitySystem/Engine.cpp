#include "Engine.h"
#include "Entity/World.h"
#include <iostream>
#include "Entity/Components/TransformComponent.h"
#include "Entity/Components/VelocityComponent.h"
#include "Entity/Systems/MovementSystem.h"
#include "Entity/Systems/RenderSystem.h"
#include "Logger.h"
#include <Windows.h>
#include "Events/Dispatcher.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include "Resources/TextureResource.h"

#include <random>
#include "Entity\EntityFactory.h"

void Engine::Init()
{
	dispatcher = std::make_shared<Dispatcher>();
	resources = std::make_shared<Resources>();
	clock = std::make_shared<Clock>();
	resources->Load<TextureResource>("block","block.png");
	resources->Load<TextureResource>("ship","ship.png");

	window.create(sf::VideoMode(800,600),"Title");

	world = std::make_shared<World>();
	world->AddSystem(std::make_shared<MovementSystem>());
	world->AddSystem(std::make_shared<RenderSystem>(&window));
	std::shared_ptr<EntityFactory> entityFactory = std::make_shared<EntityFactory>(world);

	entityFactory->CreateShip();
	/*for(int i = 0;i<100;i++)
		entityFactory->CreateBlock();*/
}
void Engine::Run()
{
	while(window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		dispatcher->Process();
		world->Update(clock->GetDelta());
	}
}