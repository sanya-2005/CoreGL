#pragma once
#include "Window.h"

class ARuntime
{
protected:
	bool isContextInitializated;
	// ����, � ������ ������ ������������ � ��������� �������
	Window* pollWindow;

public:
	virtual bool Init() = 0;

	virtual void Dispose() = 0;

	void SetContextState(bool state);
	bool GetContextState();

	void SetPollWindow(Window* window);
	Window* GetPollWindow();
};

extern ARuntime* runtime;
