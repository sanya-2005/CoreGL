#pragma once
#include "../Window.h"

#include <Windows.h>
#include <string>

namespace Win32
{
	std::wstring StringToWstring(const std::string& str);

	Size GetSizeFromRect(RECT& rect);
}