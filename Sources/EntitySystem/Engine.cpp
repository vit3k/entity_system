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

void Engine::Init()
{
	dispatcher = std::make_shared<Dispatcher>();
	resources = std::make_shared<Resources>();

	resources->Load<TextureResource>("block","block.png");

	window.create(sf::VideoMode(800,600),"The game");

	world = std::make_shared<World>();
	world->AddSystem(std::make_shared<MovementSystem>());
	world->AddSystem(std::make_shared<RenderSystem>(&window));
	EntitySP entity = world->Create();
	entity->AddComponent(std::make_shared<TransformComponent>(0.f,0.f));
	entity->AddComponent(std::make_shared<VelocityComponent>(1.f,0.f));
	entity->Update();

	EntitySP entity2 = world->Create();
	entity2->AddComponent(std::make_shared<TransformComponent>(10.f,0.f));
	entity2->Update();

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
		world->Update();
	}
}