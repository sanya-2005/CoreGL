#pragma once
#include "GPUObjectFactory.h"
#include "Buffer.h"
#include "Pipeline.h"

struct Window;

namespace gpu
{
	class Device
	{
	private:
		GPUObjectFactory* factory;
		Pipeline* pipeline;

	public:
		bool Init(Window* window);
		void Dispose();

		Buffer* CreateBuffer();

		void BindPipeline(Pipeline* pipeline);

		void DrawIndexed();

		void SwapBuffers(Window* window);
	};
}
