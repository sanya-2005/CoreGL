#pragma once
#include "../WindowController.h"

#include <Windows.h>

#undef CreateWindow

namespace Win32
{
	struct Win32WindowData
	{
		HWND handle;
		HDC context;
		HGLRC glContext;
	};

	class Win32WindowController : public IWindowController
	{
	public:

		Window* CreateWindow(const char* title, int width, int height) override;

		Size GetWindowSize(Window* window) override;

		void SwapWindowBuffers(Window* window) override;

		void ShowWindow(Window* window) override;

		void SetWindowTitle(Window* window, const char* title) override;

		void SetWindowPosition(Window* window, int x, int y) override;

		void PollEvents(Window* window) override;
	};
}