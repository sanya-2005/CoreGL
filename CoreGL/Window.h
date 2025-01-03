#pragma once
/*
* ����, ���������� ������� ���� � ������������ ����������
* -------------------------------------------------------
* �� ������ �������� ��������� - ��� ��� �������?
* �������� ����� � ����� ��� ���������.
* �������� ����� ���������� ����� ����� ARuntime (Runtime.h).
* �������� ������� ��� ������ � ������ - PlatformCreateNativeWindow, PlatformGetWindowSize � �.�.
* �������� ��������� ��������� ����� ����� IGLContext (glContextInternal.h) � ��������� OpenGL ����� ����� IGLLoader (glLoader.h).
* � Window.cpp ����� #ifdef ���������� ������� ��� ������ � ������, � � PlatformSelector ���������� ������ ������������� ������ ���������, �������� � ����������.
* ������ Windows-������ ��� ������.
*/

#include "Types.h"

typedef void (*WindowResizeCallback)(int width, int height);

struct Window;

struct Size
{
	uint width;
	uint height;
};

struct MousePosition
{
	int x;
	int y;
};

extern "C"
{
	GL_LOADER_EXPORT bool InitRuntime();

	GL_LOADER_EXPORT void DisposeRuntime();

	GL_LOADER_EXPORT Window* CreateNativeWindow(const char* title, int width, int height);

	GL_LOADER_EXPORT Size GetWindowSize(Window* window);

	GL_LOADER_EXPORT void SwapWindowBuffers(Window* window);

	GL_LOADER_EXPORT void ShowNativeWindow(Window* window);

	GL_LOADER_EXPORT void SetNativeWindowTitle(Window* window, const char* title);

	GL_LOADER_EXPORT void PollEvents(Window* window);

	GL_LOADER_EXPORT bool IsWindowShouldClosed(Window* window);

	GL_LOADER_EXPORT void SetResizeCallback(Window* window, WindowResizeCallback callback);

	GL_LOADER_EXPORT MousePosition GetGlobalMousePosition();

	GL_LOADER_EXPORT MousePosition GetLocalMousePosition(Window* window);
}
