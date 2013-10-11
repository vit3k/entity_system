#pragma once
#include "DataType.h"

class VertexBuffer
{
private:
	unsigned int vboId;
	int size, verticesCount, vertexSize, dataSize;
	DataType dataType;

public:
	VertexBuffer(void* data,int verticesCount, int vertexSize, DataType dataType);
	unsigned int GetId() { return vboId; }
	int GetSize() { return size; }
	int GetVerticesCount() { return verticesCount; }
	int GetVertexSize() { return vertexSize; }
	int GetDataType() { return dataType; }

};