#include "PlatformSelector.h"
#include "Runtime.h"
#include "glLoader.h"
#include "glContextInternal.h"
#include "WindowController.h"

#include <iostream>

ARuntime* runtime;
IGLLoader* loader;
IGLContext* context;
IWindowController* windowController;

#ifdef _WINDOWS
#include "Win32/Win32Runtime.h"
#include "Win32/Win32wglContext.h"
#include "Win32/WglLoader.h"
#include "Win32/Win32WindowController.h"

using namespace Win32;

static void Win32Select()
{
	runtime = new Win32Runtime();
	context = new WglContext();
	loader = new WglLoader();
	windowController = new Win32WindowController();
}
#endif // _WINDOWS



void PlatfromSelector::Select()
{
#ifdef _WINDOWS
	Win32Select();
#else
	std::cout << "Error: no platform to select" << std::endl;
#endif
}
