#pragma once
#include "../glLoader.h"

namespace Win32
{
	class WglLoader : public IGLLoader
	{
	public:
		void* LoadFunction(const char* name) override;
	};
}
