#include "VertexBuffer.h"
#include <GL\glew.h>

namespace Graphics
{
	VertexBuffer::VertexBuffer(void* data,int verticesCount, VertexLayout* layout, int layoutSize)
	{
		this->layout = layout;
		this->verticesCount = verticesCount;
		this->layoutSize = layoutSize;

		glGenBuffers (1, &vboId);
		glBindBuffer (GL_ARRAY_BUFFER, vboId);
		int dataSize = 0;
		vertexSize = 0;
		for(int i = 0; i < layoutSize; i++)
		{
			int ds = 4;
			switch(layout[i].dataType)
			{
				case Float:
					ds = 4;
					break;
				case Int:
					ds = 4;
					break;
			}
			vertexSize += (layout[i].dataSize * ds);
		}
		int size = vertexSize * verticesCount;
		this->size = size;
		glBufferData (GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	
		glBindBuffer (GL_ARRAY_BUFFER, 0);
	
	};

	void VertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, vboId);
		auto error = glGetError();
		int offset = 0;
		for(int i = 0; i < layoutSize; i++)
		{
			int ds = 0;
			VertexLayout l = layout[i];
			auto dt = GL_FLOAT;
		
			switch(layout[i].dataType)
			{
				case Float:
					dt = GL_FLOAT;
					ds = 4;
					break;
				case Int:
					dt = GL_INT;
					ds = 4;
					break;
			}
			glVertexAttribPointer (static_cast<int>(l.location), l.dataSize, dt, GL_FALSE, vertexSize, (GLubyte*)offset);
			error = glGetError();
			glEnableVertexAttribArray (l.location);
			error = glGetError();
			offset += ds * l.dataSize;
		}
	}

	void VertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}