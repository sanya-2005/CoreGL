#pragma once
#include "Window.h"

class IWindowController
{
public:
	virtual Window* CreateWindow(const char* title, int width, int height) = 0;

	virtual Size GetWindowSize(Window* window) = 0;

	virtual void SwapWindowBuffers(Window* window) = 0;

	virtual void ShowWindow(Window* window) = 0;

	virtual void SetWindowPosition(Window* window, int x, int y) = 0;

	virtual void SetWindowTitle(Window* window, const char* title) = 0;

	virtual void PollEvents(Window* window) = 0;
};

extern IWindowController* windowController;