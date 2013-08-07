#include "Application.h"
#include <Windows.h>
#include "../Graphics/HumanView.h"
#include "../Graphics/Textures.h"

void Application::Init()
{
	dispatcher = new ::Dispatcher();
	resources = new ::Resources();
	textures = new ::Textures();

	if(!resources->Load("block","block.png"))
		MessageBoxA(NULL,"Error loading block","Error",MB_ICONERROR | MB_OK);
	if(!resources->Load("font","arial.ttf"))
		MessageBoxA(NULL,"Error loading font","Error",MB_ICONERROR | MB_OK);

	console = new ::Console();
	console->Init();
	
	screenResX = 800;
	screenResY = 600;
	windowTitle = "The Game";
	window.create(sf::VideoMode(screenResX,screenResY),windowTitle);
	

	textures->Load("block","block");

	gameLogic = new GameLogic();
	gameLogic->Init();
	clock = new Clock();
	idSequencer = new Sequencer<unsigned long>(0);
	luaManager = new LuaManager();
	
	HumanViewStrongPtr humanView(new HumanView());
	humanView->Init();
	views.push_back(humanView);
	dispatcher->Queue(EventStrongPtr(new Event()));
}

void Application::Loop()
{
	while(window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		Time delta = clock->GetDelta();
		dispatcher->Process();
		gameLogic->Update(delta);
		for(auto it = views.begin(); it != views.end(); it++)
		{
			(*it)->Render(delta);
		}
        
	}
}

