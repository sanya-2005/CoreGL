#pragma once
/*
* ����, ���������� ������� ���� � ������������ ����������
* -------------------------------------------------------
* �� ������ �������� ��������� - ��� ��� �������?
* �������� ����� � ����� ��� ���������.
* �������� ����� ���������� ����� ����� ARuntime (Runtime.h).
* ���������� ����� ���������� ������ WindowController (WindowController.h).
* �������� ��������� ��������� ����� ����� IGLContext (glContextInternal.h) � ��������� OpenGL ����� ����� IGLLoader (glLoader.h).
* � PlatformSelector ���������� ���������� ������������� ������� ���������� ����������.
* ������ Windows-������ ��� ������.
*/

#include "Types.h"
#include "Input.h"

typedef void (*WindowResizeCallback)(int width, int height);

struct Window;

enum Platforms
{
	Windows
};

struct GLCoreVersion
{
	int major;
	int minor;
};

struct Size
{
	int width;
	int height;
};

struct MousePosition
{
	int x;
	int y;
};

#ifdef __cplusplus
extern "C"
{
#endif // _cplusplus


	GL_LOADER_EXPORT bool InitRuntime();

	GL_LOADER_EXPORT Platforms GetCurrentPlatform();

	GL_LOADER_EXPORT void DisposeRuntime();

	GL_LOADER_EXPORT Window* CreateNativeWindow(const char* title, int width, int height);

	GL_LOADER_EXPORT Size GetWindowSize(Window* window);

	GL_LOADER_EXPORT void SwapWindowBuffers(Window* window);

	GL_LOADER_EXPORT void ShowNativeWindow(Window* window);

	GL_LOADER_EXPORT void SetNativeWindowTitle(Window* window, const char* title);

	GL_LOADER_EXPORT void SetNativeWindowPosition(Window* window, int x, int y);

	GL_LOADER_EXPORT void PollEvents(Window* window);

	GL_LOADER_EXPORT bool IsWindowShouldClosed(Window* window);
	GL_LOADER_EXPORT void CloseNativeWindow(Window* window);

	GL_LOADER_EXPORT void SetResizeCallback(Window* window, WindowResizeCallback callback);
	GL_LOADER_EXPORT void SetKeyInputCallback(Window* window, KeyInputCallback callback);

	GL_LOADER_EXPORT MousePosition GetGlobalMousePosition();

	GL_LOADER_EXPORT MousePosition GetLocalMousePosition(Window* window);

	GL_LOADER_EXPORT GLCoreVersion GetGLCoreVersion();

#ifdef __cplusplus
}
#endif // _cplusplus
