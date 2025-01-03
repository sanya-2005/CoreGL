#include "wgl.h"

namespace Win32
{
	wglPrototypes::WglGetAdressProcFunction wglGetAdressProcPtr;

	WglFunctions* wglFunctions;

	void* wglGetAdressProc(const char* name)
	{
		return wglGetAdressProcPtr(name);
	}

	HGLRC CreateContext(HDC deviceContext)
	{
		return wglFunctions->WglCreateContextPtr(deviceContext);
	}

	bool MakeCurrent(HDC deviceContext, HGLRC glContext)
	{
		return wglFunctions->WglMakeCurrentPtr(deviceContext, glContext);
	}

	bool ChoosePixelFormatARB(HDC deviceContext, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats)
	{
		return wglFunctions->WglChoosePixelFormatARBPtr(deviceContext, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
	}

	HGLRC CreateContextAttribsARB(HDC hDC, HGLRC hShareContext, const int* attribList)
	{
		return wglFunctions->WglCreateContextAttribsARBPtr(hDC, hShareContext, attribList);
	}

	bool DeleteContext(HGLRC glContext)
	{
		return wglFunctions->WglDeleteContextPtr(glContext);
	}
}
