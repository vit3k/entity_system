#pragma once

#include <glm.hpp>
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"

namespace Graphics
{
	class Renderer 
	{
	private:
		glm::mat4 projectionMatrix;
		glm::mat4 viewMatrix;
	public:
		void Init();
		void DrawVertexArray(VertexArray* vertexLayout,Shader* shader,glm::mat4 modelMatrix);
		void Clear();
		void SetCameraPosition(glm::vec3 position);
		void SetTexture(TextureSP texture);
		void DrawMesh(Mesh* mesh,glm::mat4 modelMatrix);
	};
}