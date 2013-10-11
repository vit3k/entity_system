#include "Renderer.h"
#include <GL\glew.h>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

void Renderer::Init()
{
	glewInit();
	glEnable (GL_CULL_FACE); // cull face
	glCullFace (GL_BACK); // cull back face
	glFrontFace (GL_CCW); // GL_CCW for counter clock-wise
	glEnable(GL_DEPTH_TEST); 

	viewMatrix = glm::lookAt(glm::vec3(0.0f,2.0f,4.0f),glm::vec3(0.0f,0.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f));
	projectionMatrix = glm::perspective(68.0f,800.0f/600.0f,0.1f,100.0f);
}

void Renderer::DrawVertexLayout(VertexLayout* vertexLayout,Shader* shader,glm::mat4 modelMatrix)
{
	shader->Use();
	shader->SetMatrix4("view",viewMatrix);
	shader->SetMatrix4("proj",projectionMatrix);
	shader->SetMatrix4("model",modelMatrix);
	vertexLayout->Draw();
}

void Renderer::Clear()
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::SetCameraPosition(glm::vec3 position)
{
	viewMatrix = glm::lookAt(position,glm::vec3(0.0f,0.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f));
}