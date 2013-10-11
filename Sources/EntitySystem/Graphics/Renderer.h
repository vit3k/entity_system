#pragma once

#include <glm.hpp>
#include "VertexLayout.h"
#include "Shader.h"

class Renderer 
{
private:
	glm::mat4 projectionMatrix;
	glm::mat4 viewMatrix;
public:
	void Init();
	void DrawVertexLayout(VertexLayout* vertexLayout,Shader* shader,glm::mat4 modelMatrix);
	void Clear();
	void SetCameraPosition(glm::vec3 position);
};