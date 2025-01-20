#pragma once
#include "Window.h"

struct Window
{
	void* platformData;

	WindowResizeCallback resizeFunction;
	KeyInputCallback keyInputFunction;

	bool windowIsClosed;
};
