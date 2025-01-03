#include "Window.h"
#include "WindowInternal.h"
#include "PlatformSelector.h"
#include "Runtime.h"
#include "glDefines.h"
#include "glLoader.h"
#include "glContextInternal.h"

#ifdef _WINDOWS
#include "Win32/Win32Window.h"

using namespace Win32;
#endif

bool InitRuntime()
{
	PlatfromSelector::Select();

	return runtime->Init();
}

void DisposeRuntime()
{
	runtime->Dispose();
	delete runtime;

	if (context != nullptr)
	{
		delete context;
	}

	if (loader != nullptr)
	{
		delete loader;
	}

	if (glFunctions != nullptr)
	{
		delete glFunctions;
	}
}

Window* CreateNativeWindow(const char* title, int width, int height)
{
#ifdef _WINDOWS
	return CreateWin32Window(title, width, height);
#endif // _WINDOWS

	return nullptr;
}

Size GetWindowSize(Window* window)
{
#ifdef _WINDOWS
	return Win32GetSize(window);
#endif // _WINDOWS

	return Size();
}

void SwapWindowBuffers(Window* window)
{
#ifdef _WINDOWS
	Win32SwapWindowBuffers(window);
#endif // _WINDOWS
}

void ShowNativeWindow(Window* window)
{
#ifdef _WINDOWS
	Win32ShowWindow(window);
#endif
}

void SetNativeWindowTitle(Window* window, const char* title)
{
#ifdef _WINDOWS
	Win32SetWindowTitle(window, title);
#endif
}

void PollEvents(Window* window)
{
	runtime->SetPollWindow(window);

#ifdef _WINDOWS
	Win32PollEvents(window);
#endif // _WINDOWS
}

bool IsWindowShouldClosed(Window* window)
{
	return window->windowIsClosed;
}

void SetResizeCallback(Window* window, WindowResizeCallback callback)
{
	window->resizeFunction = callback;
}

MousePosition GetGlobalMousePosition()
{
	return MousePosition();
}

MousePosition GetLocalMousePosition(Window* window)
{
	return MousePosition();
}
