#include "Win32Window.h"
#include "../Runtime.h"
#include "Win32Runtime.h"
#include "wgl.h"
#include "Win32Utils.h"

#include <iostream>

namespace Win32
{
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	static ATOM RegisterWindowClass(std::wstring className)
	{
		Win32Runtime* win32Runtime = (Win32Runtime*)runtime;

		WNDCLASSEXW wcex{};

		wcex.cbSize = sizeof(WNDCLASSEX);

		wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wcex.lpfnWndProc = WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = win32Runtime->GetHinstance();
		wcex.hIcon = nullptr;
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = nullptr;
		wcex.lpszClassName = className.c_str();
		wcex.hIconSm = nullptr;

		win32Runtime->SetWindowClassName(className);

		return RegisterClassExW(&wcex);
	}



	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		Window* pollWindow = runtime->GetPollWindow();

		switch (message)
		{
		case WM_CLOSE:
			PostQuitMessage(0);
			pollWindow->windowIsClosed = true;
			break;
		case WM_SIZE:

			if (pollWindow != nullptr)
			{
				Win32WindowData* data = (Win32WindowData*)pollWindow->platformData;

				if (hWnd != data->handle)
				{
					std::cout << "Error: handles don`t equals" << std::endl;
				}

				UINT width = LOWORD(lParam);
				UINT height = HIWORD(lParam);

				if (pollWindow->resizeFunction != nullptr)
				{
					pollWindow->resizeFunction(width, height);
				}
			}

			break;
		default:
			return DefWindowProcW(hWnd, message, wParam, lParam);
		}
		return 0;
	}

	Window* CreateWin32Window(const char* title, int width, int height)
	{
		Win32Runtime* win32Runtime = (Win32Runtime*)runtime;

		std::wstring wtitle = StringToWstring(title);

		if (win32Runtime->GetWindowClassName() == L"")
		{
			RegisterWindowClass(wtitle + L"Class");
		}

		Win32WindowData* data = new Win32WindowData();

		data->handle = CreateWindowExW(0, win32Runtime->GetWindowClassName().c_str(), wtitle.c_str(), WS_OVERLAPPEDWINDOW,
									   CW_USEDEFAULT, CW_USEDEFAULT, width, height, nullptr, nullptr,
									   win32Runtime->GetHinstance(), nullptr);

		if (data->handle == nullptr)
		{
			std::cout << "CreateWin32Window: Error creating window" << std::endl;
			return nullptr;
		}

		UpdateWindow(data->handle);

		data->context = GetDC(data->handle);

		Window* win = new Window();

		win->platformData = data;

		return win;
	}

	void Win32ShowWindow(Window* window)
	{
		Win32WindowData* data = (Win32WindowData*)window->platformData;
		Win32Runtime* win32Runtime = (Win32Runtime*)runtime;

		int showCommand = SW_SHOWNA;

		//при первом создании окна требуется аргумент nCmdShow из WinMain. Это можно обойти таким способом.
		if (win32Runtime->IsFirstWindowCreate())
		{
			STARTUPINFOW si = { sizeof(si) };

			GetStartupInfoW(&si);

			if (si.dwFlags & STARTF_USESHOWWINDOW)
			{
				showCommand = si.wShowWindow;
			}

			win32Runtime->SetFirstWindowStatus(false);
		}

		ShowWindow(data->handle, showCommand);
	}

	void Win32SetWindowTitle(Window* window, const char* title)
	{
		Win32WindowData* data = (Win32WindowData*)window->platformData;

		std::wstring wtitle = StringToWstring(title);

		SetWindowTextW(data->handle, wtitle.c_str());
	}

	Size Win32GetSize(Window* window)
	{
		Size size{};

		RECT rect;

		Win32WindowData* data = (Win32WindowData*)window->platformData;

		GetClientRect(data->handle, &rect);

		size = GetSizeFromRect(rect);

		return size;
	}

	void Win32SwapWindowBuffers(Window* window)
	{
		Win32WindowData* data = (Win32WindowData*)window->platformData;

		SwapBuffers(data->context);
	}

	void Win32PollEvents(Window* window)
	{
		Win32WindowData* data = (Win32WindowData*)window->platformData;

		MSG message;

		while (PeekMessageW(&message, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessageW(&message);
		}
	}
}
