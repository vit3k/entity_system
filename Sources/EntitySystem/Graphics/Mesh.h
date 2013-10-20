#pragma once

#include "VertexArray.h"
#include "Texture.h"
#include "Shader.h"

namespace Graphics
{
	class Mesh
	{
	private:
		VertexArray* vertexArray;		
		TextureSP texture;
		ShaderSP shader;
	public:
		Mesh();
		~Mesh();
		void LoadFromMemory(void* buffer, int size);
		void Draw();
		ShaderSP UseShader();
	};
}