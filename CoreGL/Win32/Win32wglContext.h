#pragma once
#include "../Window.h"
#include "../glContextInternal.h"

namespace Win32
{
	class WglContext : public IGLContext
	{
	public:
		bool Load() override;

		bool Create(Window* window, PixelFormatInfo* pixelInfo, GLContextInfo* contextCreateInfo) override;

		bool SetCurrent(Window* window) override;

		bool Reset() override;

		bool Delete(Window* window) override;
	};
}