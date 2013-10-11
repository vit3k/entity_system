#pragma once
#include <memory>
#include "../Math/Vector2.h"
#include <SFML/Graphics.hpp>

class InputController 
{
public:
	void ProcessInput();
	bool Forward;
	bool Left;
	bool Right;
	bool Attack;
	bool Backward;
	Math::Vector2i Target;
	sf::Window* window;
	InputController(sf::Window* window): Forward(false),Left(false),Right(false),Attack(false),Target(0,0),Backward(false),window(window) {};
};

typedef std::shared_ptr<InputController> InputControllerSP;