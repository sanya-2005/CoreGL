#pragma once
#include "glContext.h"

class IGLContext
{
public:
	virtual  bool Load() = 0;

	virtual bool Create(Window* window, PixelFormatInfo* pixelInfo, GLContextCreateInfo* contextCreateInfo) = 0;

	virtual bool SetCurrent(Window* window) = 0;

	virtual bool Reset() = 0;

	virtual bool Delete(Window* window) = 0;
};

extern IGLContext* context;