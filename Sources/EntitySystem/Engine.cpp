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
#include <SFML/OpenGL.hpp>
#include "Resources/TextureResource.h"
#include "Entity\Systems\PlayerControlSystem.h"
#include "LowLevel\InputController.h"

#include <random>
#include "Entity\EntityFactory.h"
#include "Resources\ShaderResource.h"

void Engine::Init()
{
	window.create(sf::VideoMode(800,600),"Title");
	
	dispatcher = std::make_shared<Dispatcher>();
	resources = std::make_shared<Resources>();
	clock = std::make_shared<Clock>();
	
	resources->Load<ShaderResource>("vertex","vertex.glsl");
	resources->Load<ShaderResource>("fragment","fragment.glsl");

	inputController = std::make_shared<InputController>(&window);

	world = std::make_shared<World>();
	world->AddSystem(std::make_shared<PlayerControlSystem>(inputController));
	world->AddSystem(std::make_shared<MovementSystem>());
	
	renderSystem = std::make_shared<RenderSystem>(&window);
	renderSystem->InitGraphics();
	renderSystem->InitBuffers();
	world->AddSystem(renderSystem);
	
	entityFactory = std::make_shared<EntityFactory>(world);

	//entityFactory->CreateShip();
	
}
void Engine::Run()
{
	while(window.isOpen()) 
	{
		inputController->ProcessInput();
		dispatcher->Process();
		world->Update(clock->GetDelta());

		sf::Event event;
		while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
			{
                window.close();
			}
        }
	}

}

void Engine::Deinit()
{
	renderSystem->Deinit();
}