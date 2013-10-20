#pragma once

#include "System.h"
#include "../Components/TransformComponent.h"
#include "../Components/RenderComponent.h"
#include <SFML/Window.hpp>

#include "../../Math/Vector2.h"
#include <glm.hpp>
#include "..\..\Graphics\Renderer.h"

class RenderSystem : public System
{
	sf::Window* window;
	Graphics::Renderer* renderer;
	Graphics::Mesh* mesh;
	float angle;
	float verticalAngle;
public:
	RenderSystem(sf::Window* window) : System(2,TransformComponent::ID,RenderComponent::ID),
		window(window)
	{
	};
	void Process(Time delta);
	void EntityAdded(EntitySP entity);
	void InitBuffers();
	void InitGraphics();

	void Deinit();
};
