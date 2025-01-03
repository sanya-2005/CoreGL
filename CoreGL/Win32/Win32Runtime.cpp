#include "Win32Runtime.h"
#include "wgl.h"

#include <iostream>

bool Win32::Win32Runtime::Init()
{
	firstWindowCreate = true;
	// hInstance можно получить таким методом, не прибегая к аргументам из WinMain 
	hinst = GetModuleHandleW(nullptr);
	className = L"";

	glLib = LoadLibraryW(L"opengl32.dll");

	if (glLib == nullptr)
	{
		std::cout << "Win32InitRuntime: Error loading opengl32.dll" << std::endl;
		return false;
	}

	return true;
}

void Win32::Win32Runtime::Dispose()
{
	FreeLibrary(glLib);

	if (wglFunctions != nullptr)
	{
		delete wglFunctions;
	}
}

void Win32::Win32Runtime::SetFirstWindowStatus(bool firstWindowCreation)
{
	firstWindowCreate = firstWindowCreation;
}

bool Win32::Win32Runtime::IsFirstWindowCreate()
{
	return firstWindowCreate;
}

void Win32::Win32Runtime::SetWindowClassName(std::wstring clsName)
{
	className = clsName;
}

std::wstring Win32::Win32Runtime::GetWindowClassName()
{
	return className;
}

HINSTANCE Win32::Win32Runtime::GetHinstance()
{
	return hinst;
}

HMODULE Win32::Win32Runtime::GetglLibHandle()
{
	return glLib;
}
