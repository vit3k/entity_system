#pragma once

namespace Graphics
{
	class IndexBuffer
	{
	private:
		unsigned int iboId;
		int triangleCount;
	public:
		IndexBuffer(void* data, int triangleCount);
		int GetId() { return iboId; }
		int GetTriangleCount() { return triangleCount; }
		void Bind();
		void Unbind();

	};
}