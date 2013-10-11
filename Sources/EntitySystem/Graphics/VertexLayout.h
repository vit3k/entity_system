#pragma once
#include "VertexBuffer.h"
#include "DataType.h"
#include "IndexBuffer.h"

class VertexLayout
{
private:
	unsigned int vaoId;
	int size;
	int verticesCount;
	int triangleCount;
public:
	VertexLayout();
	void AddVertexBuffer(VertexBuffer* vb, int position);
	void SetIndexBuffer(IndexBuffer* ib);
	void Draw();
};

