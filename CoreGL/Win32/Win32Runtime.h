#pragma once
#include "../Runtime.h"

#include <Windows.h>
#include <string>

namespace Win32
{
	class Win32Runtime : public ARuntime
	{
	private:
		bool firstWindowCreate;

		std::wstring className;

		HINSTANCE hinst;

		HMODULE glLib;

	public:
		bool Init() override;

		Platforms GetPlatform() override;

		void Dispose() override;

		void SetFirstWindowStatus(bool firstWindowCreation);
		bool IsFirstWindowCreate();

		void SetWindowClassName(std::wstring clsName);
		std::wstring GetWindowClassName();

		HINSTANCE GetHinstance();

		HMODULE GetglLibHandle();
	};
}
