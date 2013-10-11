#include "VertexLayout.h"
#include <GL\glew.h>

VertexLayout::VertexLayout()
{
	glGenVertexArrays (1, &vaoId);
	size = 0;
}

void VertexLayout::AddVertexBuffer(VertexBuffer* vb, int position)
{
	auto dataType = vb->GetDataType();
	auto sizeOfVertex = vb->GetVertexSize();
	glBindVertexArray (vaoId);
	glBindBuffer (GL_ARRAY_BUFFER, vb->GetId());
	int dt = GL_FLOAT;
	switch(dataType)
	{
		case Float:
			dt = GL_FLOAT;
			break;
		case Int:
			dt = GL_INT;
			break;
	}
	glVertexAttribPointer (position, sizeOfVertex, dt, GL_FALSE, 0, (GLubyte*)0);
	glEnableVertexAttribArray (position);
	if(vb->GetSize() > size)
		size = vb->GetSize();
	if(vb->GetVerticesCount() > verticesCount)
		verticesCount = vb->GetVerticesCount();
	glBindVertexArray(0);
}

void VertexLayout::SetIndexBuffer(IndexBuffer* ib)
{
	
	triangleCount = ib->GetTriangleCount();
	glBindVertexArray(vaoId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib->GetId());
	glBindVertexArray(0);
}
void VertexLayout::Draw()
{
	glBindVertexArray (vaoId);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexBuffer->GetId());
	glDrawElements(GL_TRIANGLES, triangleCount*3, GL_UNSIGNED_INT, (GLvoid*)0);
	
	//glDrawArrays (GL_TRIANGLES, 0, verticesCount);
	glBindVertexArray(0);
}