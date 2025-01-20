#pragma once
#include "Buffer.h"
#include "Shader.h"

namespace gpu
{
	class Pipeline
	{
	private:
		
	public:
		void BindVertexBuffer(Buffer* buffer);

		void BindIndexBuffer(Buffer* buffer);

		void BindVertexShader(Shader* shader);
		void BindFragmentShader(Shader* shader);
	};
}