#pragma once
#include "Buffer.h"
#include "Shader.h"

namespace gpu
{
	class GPUObjectFactory
	{
	public:
		Buffer* CreateBuffer();
		Shader* CreateShader();
	};
}