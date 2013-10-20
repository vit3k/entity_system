#include "Mesh.h"
#include "Vertex.h"
#include "Textures.h"
#include "Shaders.h"

/*int ReadLineFromBuffer(char* buffer, int pos, int size)
{
	int i = 0;
	/*std::string line = "";
	while(buffer[i] != '\n')
	{
		char c = buffer[i];
		line.append(c);
	}
	
}*/
namespace Graphics
{
	Mesh::Mesh()
	{
		Vertex vertices[] =
		{
			{ 1.0f, -1.0f, -1.0f, 1.0f, 1.0f},
			{ 1.0f, -1.0f,  1.0f, 0.0f, 1.0f},
			{-1.0f, -1.0f,  1.0f, 1.0f, 1.0f},
			{-1.0f, -1.0f, -1.0f, 0.0f, 1.0f},
			{ 1.0f,  1.0f, -1.0f, 0.0f, 0.0f},
			{ 1.0f,  1.0f,  1.0f, 1.0f, 0.0f},
			{-1.0f,  1.0f,  1.0f, 0.0f, 0.0f},
			{-1.0f,  1.0f, -1.0f, 1.0f, 0.0f}
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
		Graphics::VertexLayout layout[] = 
		{
			{Graphics::VertexAttribute::Position, Graphics::DataType::Float, 3},
			{Graphics::VertexAttribute::Texcoord, Graphics::DataType::Float, 2}
		};
	
		Graphics::VertexBuffer* vertexBuffer = new Graphics::VertexBuffer(vertices, 8, layout, 2);
		Graphics::IndexBuffer* indexBuffer = new Graphics::IndexBuffer(index, 12);

		vertexArray = new Graphics::VertexArray();
		vertexArray->SetBuffers(&vertexBuffer, 1, indexBuffer);

		delete vertexBuffer;
		delete indexBuffer;

		shader = Shaders::Get("shader");
		texture = Textures::Get("texture");
	}
	void Mesh::LoadFromMemory(void* buffer, int size)
	{
		
	}
	ShaderSP Mesh::UseShader()
	{
		shader->Use();
		return shader;
	}
	void Mesh::Draw()
	{
		texture->Use();
		vertexArray->Draw();
	}

	Mesh::~Mesh()
	{
		delete vertexArray;
	}
}