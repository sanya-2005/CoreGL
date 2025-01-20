#include "Win32wglContext.h"
#include "Win32WindowController.h"
#include "../WindowInternal.h"
#include "Win32Runtime.h"
#include "wgl.h"
#include <iostream>

namespace Win32
{
	using namespace wglPrototypes;

	bool WglContext::Load()
	{
		Win32Runtime* win32Runtime = (Win32Runtime*)runtime;

		wglGetAdressProcPtr = (WglGetAdressProcFunction)GetProcAddress(win32Runtime->GetglLibHandle(), "wglGetProcAddress");

		wglFunctions = new WglFunctions();

		wglFunctions->WglCreateContextPtr = (WglCreateContextFunction)GetProcAddress(win32Runtime->GetglLibHandle(), "wglCreateContext");

		if (wglFunctions->WglCreateContextPtr == nullptr)
		{
			return false;
		}

		wglFunctions->WglMakeCurrentPtr = (WglMakeCurrentFunction)GetProcAddress(win32Runtime->GetglLibHandle(), "wglMakeCurrent");

		if (wglFunctions->WglMakeCurrentPtr == nullptr)
		{
			return false;
		}

		wglFunctions->WglDeleteContextPtr = (WglDeleteContextFunction)GetProcAddress(win32Runtime->GetglLibHandle(), "wglDeleteContext");

		if (wglFunctions->WglDeleteContextPtr == nullptr)
		{
			return false;
		}

		/*
		* Создание OpenGL выше версии 1.1 есть расширения. Их можно загрузить при уже существующем GL-контексте. Поэтому сначала создаем
		* Фейковый 1.1 OpenGL контекст, потом загружаем функции для создания современного контекста, и удалем ненужный временный контекст.
		*/

		HWND fakeWindow = CreateWindowExW(0, win32Runtime->GetWindowClassName().c_str(), L"FakeWindow", WS_OVERLAPPEDWINDOW,
										  CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
										  nullptr, nullptr, win32Runtime->GetHinstance(), nullptr);

		HDC fakeDC = GetDC(fakeWindow);

		PIXELFORMATDESCRIPTOR descriptor;

		descriptor.cColorBits = 32;
		descriptor.cDepthBits = 32;
		descriptor.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER;
		descriptor.iLayerType = PFD_MAIN_PLANE;
		descriptor.iPixelType = PFD_TYPE_RGBA;
		descriptor.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		descriptor.nVersion = 1;

		int pixelFormat = ChoosePixelFormat(fakeDC, &descriptor);

		pixelFormat = SetPixelFormat(fakeDC, pixelFormat, &descriptor);

		HGLRC fakeRC = CreateContext(fakeDC);

		MakeCurrent(fakeDC, fakeRC);

		wglFunctions->WglChoosePixelFormatARBPtr = (wglChoosePixelFormatARBFunction)wglGetAdressProc("wglChoosePixelFormatARB");

		wglFunctions->WglCreateContextAttribsARBPtr = (wglCreateContextAttribsARBFunction)wglGetAdressProc("wglCreateContextAttribsARB");

		MakeCurrent(nullptr, nullptr);
		DeleteContext(fakeRC);

		ReleaseDC(fakeWindow, fakeDC);
		DestroyWindow(fakeWindow);

		return true;
	}

	bool WglContext::Create(Window* window, PixelFormatInfo* pixelInfo, GLContextInfo* contextCreateInfo)
	{
		Win32WindowData* data = (Win32WindowData*)window->platformData;

		int pixelAttribs[] =
		{
			WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
			WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
			WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
			WGL_PIXEL_TYPE_ARB,(int)pixelInfo->pixelType,
			WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
			WGL_COLOR_BITS_ARB, pixelInfo->colorBits,
			WGL_ALPHA_BITS_ARB, pixelInfo->aplhaBits,
			WGL_DEPTH_BITS_ARB, pixelInfo->depthBits,
			WGL_STENCIL_BITS_ARB, pixelInfo->stencilBits,
			WGL_SAMPLE_BUFFERS_ARB, (int)pixelInfo->enableMultisample,
			WGL_SAMPLES_ARB, pixelInfo->multisampleCount,
			0, 0
		};

		int pixelFormatID;
		UINT numFormats;

		bool status = ChoosePixelFormatARB(data->context, pixelAttribs, nullptr, 1, &pixelFormatID, &numFormats);

		if (status != true)
		{
			return false;
		}

		if (numFormats == 0)
		{
			std::cout << "Error choose Pixel Format" << std::endl;
			return false;
		}

		PIXELFORMATDESCRIPTOR PFD;

		DescribePixelFormat(data->context, pixelFormatID, sizeof(PFD), &PFD);
		SetPixelFormat(data->context, pixelFormatID, &PFD);

		int contextAttribs[] =
		{
			WGL_CONTEXT_MAJOR_VERSION_ARB, contextCreateInfo->major,
			WGL_CONTEXT_MINOR_VERSION_ARB, contextCreateInfo->minor,
			WGL_CONTEXT_PROFILE_MASK_ARB, contextCreateInfo->profile,
			WGL_CONTEXT_FLAGS_ARB, contextCreateInfo->flags,
			0, 0
		};

		data->glContext = CreateContextAttribsARB(data->context, 0, contextAttribs);

		if (data->glContext == nullptr)
		{
			std::cout << "WglContext::Create - Error create Wgl Context" << std::endl;
			return false;
		}

		return true;
	}

	bool WglContext::SetCurrent(Window* window)
	{
		Win32WindowData* data = (Win32WindowData*)window->platformData;

		return MakeCurrent(data->context, data->glContext);
	}

	bool WglContext::Reset()
	{
		return MakeCurrent(nullptr, nullptr);
	}

	bool WglContext::Delete(Window* window)
	{
		Win32WindowData* data = (Win32WindowData*)window->platformData;

		if (!DeleteContext(data->glContext))
		{
			return false;
		}

		if (!DeleteDC(data->context))
		{
			return false;
		}

		return true;
	}
}