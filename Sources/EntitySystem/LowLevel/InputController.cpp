#include "InputController.h"
#include <SFML/Window.hpp>
#include "../Engine.h"
#include "../Events/ThrottleEvent.h"

void InputController::ProcessInput()
{
	Forward = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	Backward = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	Left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	Right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	Attack = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
	Target = Math::Vector2i(localPosition.x,localPosition.y);
	
}