#include "Win32Utils.h"

#include <Windows.h>

namespace Win32
{
	std::wstring StringToWstring(const std::string& str)
	{
		int size_needed = MultiByteToWideChar(1251, 0, &str[0], (int)str.size(),
											  nullptr, 0);

		std::wstring strTo(size_needed, 0);
		
		MultiByteToWideChar(1251, 0, &str[0], (int)str.size(),
							&strTo[0], size_needed);
		return strTo;
	}

	Size GetSizeFromRect(RECT& rect)
	{
		Size size;

		size.width = rect.right - rect.left;
		size.height = rect.bottom - rect.top;

		return size;
	}
}