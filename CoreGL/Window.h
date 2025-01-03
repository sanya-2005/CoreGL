#pragma once
/*
* Файл, содержащий систему окон и инциализацию библиотеки
* -------------------------------------------------------
* Вы хотите добавить платформу - как это сделать?
* Создайте папку с кодом для платформы.
* Создайте среду выполнения через класс ARuntime (Runtime.h).
* создайте функции для работы с окнами - PlatformCreateNativeWindow, PlatformGetWindowSize и т.п.
* Создайте Загрузчик контекста через класс IGLContext (glContextInternal.h) и загрузчик OpenGL через класс IGLLoader (glLoader.h).
* в Window.cpp через #ifdef разместите функции для работы с окнами, а в PlatformSelector разместите логику инициализации вашего контекста, рантайма и загрузчика.
* Смотри Windows-бекенд как эталон.
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
