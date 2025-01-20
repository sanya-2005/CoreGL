#include "Window.h"
#include "WindowInternal.h"
#include "PlatformSelector.h"
#include "Runtime.h"
#include "glDefines.h"
#include "glLoader.h"
#include "glContextInternal.h"
#include "WindowController.h"


bool InitRuntime()
{
	PlatfromSelector::Select();

	return runtime->Init();
}

Platforms GetCurrentPlatform()
{
	return runtime->GetPlatform();
}

void DisposeRuntime()
{
	runtime->Dispose();
	delete runtime;

	delete windowController;

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
	return windowController->CreateWindow(title, width, height);
}

Size GetWindowSize(Window* window)
{
	return windowController->GetWindowSize(window);
}

void SwapWindowBuffers(Window* window)
{
	windowController->SwapWindowBuffers(window);
}

void ShowNativeWindow(Window* window)
{
	windowController->ShowWindow(window);
}

void SetNativeWindowTitle(Window* window, const char* title)
{
	windowController->SetWindowTitle(window, title);
}

void SetNativeWindowPosition(Window* window, int x, int y)
{
	windowController->SetWindowPosition(window, x, y);
}

void PollEvents(Window* window)
{
	runtime->SetPollWindow(window);

	windowController->PollEvents(window);
}

bool IsWindowShouldClosed(Window* window)
{
	return window->windowIsClosed;
}

void CloseNativeWindow(Window* window)
{
	window->windowIsClosed = true;
}

void SetResizeCallback(Window* window, WindowResizeCallback callback)
{
	window->resizeFunction = callback;
}

void SetKeyInputCallback(Window* window, KeyInputCallback callback)
{
	window->keyInputFunction = callback;
}

MousePosition GetGlobalMousePosition()
{
	return MousePosition();
}

MousePosition GetLocalMousePosition(Window* window)
{
	return MousePosition();
}

GLCoreVersion GetGLCoreVersion()
{
	return glCoreVersion;
}
