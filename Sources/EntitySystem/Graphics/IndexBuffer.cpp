#include "IndexBuffer.h"
#include <GL\glew.h>

namespace Graphics
{
	IndexBuffer::IndexBuffer(void* data, int triangleCount)
	{
		glGenBuffers(1, &iboId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, triangleCount * 3 * sizeof(unsigned int), data, GL_STATIC_DRAW);
		this->triangleCount = triangleCount;
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void IndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId);
	}

	void IndexBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}