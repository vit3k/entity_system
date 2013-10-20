#pragma once
#include "DataType.h"
#include <vector>

namespace Graphics 
{
	enum VertexAttribute
	{
		Position = 0,
		Texcoord = 1,
		//Texcoord = 2
	};

	struct VertexLayout 
	{
		VertexAttribute location;
		DataType dataType;
		int dataSize;
	};


	class VertexBuffer
	{
	private:
		unsigned int vboId;
		int size, verticesCount, vertexSize, dataSize;
		VertexLayout* layout;
		int layoutSize;
	public:
		VertexBuffer(void* data,int verticesCount, VertexLayout* layout, int layoutSize);
		unsigned int GetId() { return vboId; }
		int GetSize() { return size; }
		int GetVerticesCount() { return verticesCount; }
		int GetVertexSize() { return vertexSize; }
		VertexLayout* GetLayout() { return layout; }
		void BindLayout();
		void Bind();
		void Unbind();
	};
}