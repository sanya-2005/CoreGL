#include "WglLoader.h"
#include "wgl.h"

namespace Win32
{
	void* WglLoader::LoadFunction(const char* name)
	{
		return wglGetAdressProc(name);
	}
}
