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

struct GLContextInfo
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
	int stencilBits = 8;

	bool enableMultisample = false;
	int multisampleCount = 0;
};

#ifdef __cplusplus
extern "C"
{
#endif // _cplusplus


	GL_LOADER_EXPORT bool LoadGLContext();

	GL_LOADER_EXPORT bool CreateGLContext(Window* window, PixelFormatInfo* pixelInfo, GLContextInfo* contextCreateInfo);

	GL_LOADER_EXPORT bool LoadCoreGL();

	GL_LOADER_EXPORT bool SetCurrentContext(Window* window);

	GL_LOADER_EXPORT bool ResetContext();

	GL_LOADER_EXPORT bool DeleteGLContext(Window* window);


#ifdef __cplusplus
}
#endif // _cplusplus

