#include "RenderSystem.h"
#include "../../Logger.h"
#include "../../Engine.h"
#include "../../Resources/TextureResource.h"
#include "../Components/Sprite.h"
#include "../../Resources/ShaderResource.h"
#include <GL\glew.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "../../Graphics/DataType.h"
#include "../../Graphics/Textures.h"
#include "../../Graphics/Shaders.h"

void RenderSystem::InitBuffers()
{	
	mesh = new Graphics::Mesh();
		
	angle = 0;
	verticalAngle = 0;
}
void RenderSystem::InitGraphics()
{
	renderer = new Graphics::Renderer();	
	renderer->Init();
	Graphics::Textures::LoadFromFile("texture","texture.png");
	Graphics::Shaders::LoadFromFiles("shader","vertex.glsl","fragment.glsl");
}
void RenderSystem::Process(Time delta)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		angle+=0.5;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		angle-=0.5;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		verticalAngle-=0.5;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		verticalAngle+=0.5;

	renderer->Clear();
	glm::mat4 modelMatrix = glm::rotate(glm::mat4(1.0f),angle,glm::vec3(0.0f,1.0f,0.0f));
	modelMatrix = glm::rotate(modelMatrix,verticalAngle,glm::vec3(0.0f,0.0f,1.0f));
	
	renderer->DrawMesh(mesh,modelMatrix);

	window->display();
}

void RenderSystem::EntityAdded(EntitySP entity)
{
	/*RenderComponentSP render = entity->GetComponent<RenderComponent>();
	Components::SpriteSP sprite = entity->GetComponent<Components::Sprite>();
	auto texture = Engine::Instance().GetResources()->Get<TextureResource>(sprite->GetSpriteName());
	sf::Sprite sfSprite(*(texture->Get()));
	sprites[entity->ID] = sfSprite;*/
}

void RenderSystem::Deinit()
{
	delete mesh;
}