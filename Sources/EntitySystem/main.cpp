#include "World.h"
#include <iostream>
#include "TransformComponent.h"
#include "VelocityComponent.h"
#include "MovementSystem.h"
#include "RenderSystem.h"
#include "Logger.h"
#include <Windows.h>
#include "Dispatcher.h"
#include <memory>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(800,600),"The game");

	auto world = std::make_shared<World>();
	world->AddSystem(std::make_shared<MovementSystem>());
	world->AddSystem(std::make_shared<RenderSystem>(&window));
	EntitySP entity = world->Create();
	entity->AddComponent(std::make_shared<TransformComponent>(0.f,0.f));
	entity->AddComponent(std::make_shared<VelocityComponent>(1.f,0.f));
	entity->Update();

	EntitySP entity2 = world->Create();
	entity2->AddComponent(std::make_shared<TransformComponent>(10.f,0.f));
	entity2->Update();

	

	while(window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		/*for(auto it = views.begin(); it != views.end(); it++)
		{
			(*it)->Render(delta);
		}*/
		Dispatcher::Process();
		world->Update();
	}

	return 0;
}