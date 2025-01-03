#pragma once
#include "wglTypes.h"
#include "../glTypes.h"
#include <Windows.h>

namespace Win32
{
	namespace wglPrototypes
	{
		typedef void* (GL_API WglGetAdressProcFunction)(const char*);

		typedef HGLRC(GL_API WglCreateContextFunction)(HDC);
		typedef BOOL(GL_API WglDeleteContextFunction)(HGLRC);
		typedef BOOL(GL_API WglMakeCurrentFunction)(HDC, HGLRC);

		typedef BOOL(GL_API wglChoosePixelFormatARBFunction) (HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats);
		typedef HGLRC(GL_API wglCreateContextAttribsARBFunction) (HDC hDC, HGLRC hShareContext, const int* attribList);
	}

	extern wglPrototypes::WglGetAdressProcFunction wglGetAdressProcPtr;

	void* wglGetAdressProc(const char* name);

	struct WglFunctions
	{
		wglPrototypes::WglCreateContextFunction WglCreateContextPtr;
		wglPrototypes::WglMakeCurrentFunction WglMakeCurrentPtr;
		wglPrototypes::WglDeleteContextFunction WglDeleteContextPtr;

		wglPrototypes::wglChoosePixelFormatARBFunction WglChoosePixelFormatARBPtr;
		wglPrototypes::wglCreateContextAttribsARBFunction WglCreateContextAttribsARBPtr;
	};

	extern WglFunctions* wglFunctions;

	HGLRC CreateContext(HDC deviceContext);

	bool MakeCurrent(HDC deviceContext, HGLRC glContext);

	bool ChoosePixelFormatARB(HDC deviceContext, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats);

	HGLRC CreateContextAttribsARB(HDC hDC, HGLRC hShareContext, const int* attribList);

	bool DeleteContext(HGLRC glContext);
}