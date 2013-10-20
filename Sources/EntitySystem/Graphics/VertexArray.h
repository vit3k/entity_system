#pragma once
#include "VertexBuffer.h"
#include "DataType.h"
#include "IndexBuffer.h"

namespace Graphics
{
	class VertexArray
	{
	private:
		unsigned int vaoId;
		int size;
		int verticesCount;
		int triangleCount;
	public:
		VertexArray();
		void AddVertexBuffer(VertexBuffer* vb);
		void SetIndexBuffer(IndexBuffer* ib);
		void SetBuffers(VertexBuffer** vbos, int vbosCount, IndexBuffer* ib);
		void Draw();
	};

}