#include "VertexArray.h"
#include <GL\glew.h>

namespace Graphics
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays (1, &vaoId);
		size = 0;
	}

	void VertexArray::AddVertexBuffer(VertexBuffer* vb)
	{
		//auto dataType = vb->GetDataType();
		auto sizeOfVertex = vb->GetVertexSize();
	
		glBindVertexArray(0);
	}

	void VertexArray::SetIndexBuffer(IndexBuffer* ib)
	{
	
		triangleCount = ib->GetTriangleCount();
		glBindVertexArray(vaoId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib->GetId());
		glBindVertexArray(0);
	}

	void VertexArray::SetBuffers(VertexBuffer** vbos, int vbosCount, IndexBuffer* ib)
	{
		glBindVertexArray(vaoId);
	
		for(int i = 0; i < vbosCount; i++) {
			vbos[i]->Bind();
		}
	
		ib->Bind();
		glBindVertexArray(0);
		triangleCount = ib->GetTriangleCount();
	}
	void VertexArray::Draw()
	{
		glBindVertexArray (vaoId);
		glDrawElements(GL_TRIANGLES, triangleCount*3, GL_UNSIGNED_INT, (GLvoid*)0);
		//glDrawArrays(GL_TRIANGLES,0,3);
		glBindVertexArray(0);
	}
}