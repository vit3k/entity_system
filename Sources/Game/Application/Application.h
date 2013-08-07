#pragma once

#include <SFML/Graphics.hpp>
#include "../Logic/GameLogic.h"
#include "Sequencer.h"
#include "LuaManager.h"
#include "Resources.h"
#include "../Graphics/Textures.h"
#include "list"
#include "../Graphics/IView.h"
#include "../Events/Dispatcher.h"
#include "Console.h"
#include "../EntitySystem/World.h"

typedef std::list<IViewStrongPtr> ViewList;
/* This is singleton */
class Application 
{
	private:
		sf::RenderWindow window;
		int screenResX;
		int screenResY;
		char* windowTitle;
		GameLogic* gameLogic;
		Clock* clock;
		Sequencer<unsigned long>* idSequencer;
		LuaManager* luaManager;
		Resources* resources;
		Textures* textures;
		Dispatcher* dispatcher;
		Console* console;
		World* world;
		ViewList views;
		/* Constructor and destructor hidden because it's singleton */
		Application()
		{
		};
		~Application()
		{
		};
	public:
		void Init();
		void Loop();
		
		Sequencer<unsigned long>* IdSequencer() { return idSequencer; }
		Resources* Resources() { return resources; }
		Textures* Textures() { return textures; }
		Dispatcher* Dispatcher(){ return dispatcher; }
		Console* Console(){ return console; }
		World* GetWorld() { return world; }
		sf::RenderWindow* Window() { return &window; } 
		static Application& Instance()
		{
			static Application instance;
			return instance;
		};
};
