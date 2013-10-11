#include "VertexBuffer.h"
#include <GL\glew.h>

VertexBuffer::VertexBuffer(void* data,int verticesCount, int vertexSize, DataType dataType)
{
	int dataSize = 4;
	switch(dataType)
	{
		case Float:
			dataSize = 4;
			break;
		case Int:
			dataSize = 4;
			break;
	}
	size = verticesCount * vertexSize * dataSize;
	this->verticesCount = verticesCount;
	this->vertexSize = vertexSize;
	this->dataType = dataType;
	this->dataSize = dataSize;
	glGenBuffers (1, &vboId);
	glBindBuffer (GL_ARRAY_BUFFER, vboId);
	glBufferData (GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	glBindBuffer (GL_ARRAY_BUFFER, 0);
};