#pragma once
#include "../Window.h"
#include "../WindowInternal.h"
#include <Windows.h>
#include <string>

namespace Win32
{
	struct Win32WindowData
	{
		HWND handle;
		HDC context;
		HGLRC glContext;
	};

	Window* CreateWin32Window(const char* title, int width, int height);

	void Win32ShowWindow(Window* window);

	void Win32SetWindowTitle(Window* window, const char* title);

	Size Win32GetSize(Window* window);

	void Win32SwapWindowBuffers(Window* window);

	void Win32PollEvents(Window* window);
}
