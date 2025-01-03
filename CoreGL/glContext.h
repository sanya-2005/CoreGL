#pragma once
/// Для использования библиотеки нужно делать все строго в этом порядке: Создать окно (CreateNativeWindow), загрузить GL-контекст (LoadGLContext)
/// Создать GL-контекст (CreateGLContext), активизировать контекст (SetCurrentContext), загрузить GL-функции (LoadCoreGL).
/// 
/// Все функции, которые должны быть доступны пользователю, обернуты в extern "C". Это необходимо для создания биндингов на других языках (например С#).
/// Читай про Name Mangling, если интересна причина.
/// Пока что нереализована возможность отсекать OpenGL функции по запрашиваемому стандарту, имейте это в виду

#include "Window.h"

enum GLProfile
{
	CoreProfile = 0x00000001,
};

enum GLContextFlags
{
	DebugFlag = 0x00000001
};

struct GLContextCreateInfo
{
	int major;
	int minor;
	GLProfile profile;
	int flags = 0;
};

enum PixelType
{
	RgbaFormat = 0x202B
};

struct PixelFormatInfo
{
	PixelType pixelType;

	int colorBits;
	int aplhaBits = 8;
	int depthBits;
	int stencilBits;

	bool enableMultisample = false;
	int multisampleCount = 1;
};

extern "C"
{
	GL_LOADER_EXPORT bool LoadGLContext();

	GL_LOADER_EXPORT bool CreateGLContext(Window* window, PixelFormatInfo* pixelInfo, GLContextCreateInfo* contextCreateInfo);

	GL_LOADER_EXPORT bool LoadCoreGL();

	GL_LOADER_EXPORT bool SetCurrentContext(Window* window);

	GL_LOADER_EXPORT bool ResetContext();

	GL_LOADER_EXPORT bool DeleteGLContext(Window* window);
}
