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


void RenderSystem::InitBuffers()
{
	float colors2[] =
	{
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f,
		0.5f, 0.5f, 0.0f,
		0.0f, 0.5f, 0.5f,
	};

	float vertices[] =
	{
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, 1.0f,
		-1.0f, -1.0f, 1.0f,
		-1.0f, -1.0f, -1.0f,
		1.0f, 1.0f, -1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, -1.0f
	};

	unsigned int index[] =
	{
		0, 1, 2,
		0, 4, 5,
		4, 0, 3,
		1, 0, 5,
		2, 1, 6,
		1, 5, 6,
		5, 4, 6,
		3, 0, 2,
		4, 7, 6,
		2, 6, 7,
		3, 2, 7,
		7, 4, 3,
	};

	VertexBuffer* pointsBuffer = new VertexBuffer(vertices, 8, 3, DataType::Float);
	VertexBuffer* colorsBuffer = new VertexBuffer(colors2, 8, 3, DataType::Float);

	IndexBuffer* indexBuffer = new IndexBuffer(index, 12);

	vertexLayout = new VertexLayout();
	vertexLayout->AddVertexBuffer(pointsBuffer,0);
	vertexLayout->AddVertexBuffer(colorsBuffer,1);
	vertexLayout->SetIndexBuffer(indexBuffer);

	shader = new Shader("vertex","fragment");
	angle = 0;
	verticalAngle = 0;
	delete pointsBuffer;
	delete colorsBuffer;
}
void RenderSystem::InitGraphics()
{
	renderer = new Renderer();
	
	renderer->Init();
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
	renderer->DrawVertexLayout(vertexLayout,shader,modelMatrix);

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
	delete vertexLayout;
}