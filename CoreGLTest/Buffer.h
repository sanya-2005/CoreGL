#pragma once
#include "GLResource.h"

namespace gpu
{
	enum BufferType
	{
		VertexBuffer,
		IndexBuffer,
		UniformBuffer
	};

	enum IndexType
	{
		ShortIndex,
		UIntIndex
	};

	class Buffer : public GLResource
	{
	private:
		BufferType type;
		isize bufferSize;

	public:
		Buffer(int64 id, isize bufferSize);
	};
}