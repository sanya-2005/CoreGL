#include "glContext.h"
#include "glContextInternal.h"
#include "glDefines.h"
#include "glLoader.h"
#include "Runtime.h"

#include <iostream>

using namespace glPrototypes;

bool LoadGLContext()
{
	bool result = false;

	result = context->Load();

	runtime->SetContextState(result);

    return result;
}

bool LoadCoreGL()
{
	glFunctions = new GLFunctions();

	glFunctions->glClearColorPtr = GetGLAdressProc<glClearColorFunction>("glClearColor");

	glFunctions->glViewportPtr = GetGLAdressProc<glViewportFunction>("glViewport");
	glFunctions->glClearPtr = GetGLAdressProc<glClearFunction>("glClear");

	glFunctions->glGenBuffersPtr = GetGLAdressProc<glGenBuffersFuncion>("glGenBuffers");
	glFunctions->glBindBufferPtr = GetGLAdressProc<glBindBufferFunction>("glBindBuffer");
	glFunctions->glBufferDataPtr = GetGLAdressProc<glBufferDataFunction>("glBufferData");

	glFunctions->glVertexAttribPointerPtr = GetGLAdressProc<glVertexAttribPointerFunction>("glVertexAttribPointer");
	glFunctions->glEnableVertexAttribArrayPtr = GetGLAdressProc<glEnableVertexAttribArrayFunction>("glEnableVertexAttribArray");
	glFunctions->glGenVertexArraysPtr = GetGLAdressProc<glGenVertexArraysFunction>("glGenVertexArrays");
	glFunctions->glBindVertexArrayPtr = GetGLAdressProc<glBindVertexArrayFunction>("glBindVertexArray");

	glFunctions->glCreateShaderPtr = GetGLAdressProc<glCreateShaderFuncion>("glCreateShader");
	glFunctions->glShaderSourcePtr = GetGLAdressProc<glShaderSourceFunction>("glShaderSource");
	glFunctions->glCompileShaderPtr = GetGLAdressProc<glCompileShaderFunction>("glCompileShader");
	glFunctions->glDeleteShaderPtr = GetGLAdressProc<glDeleteShaderFunction>("glDeleteShader");
	glFunctions->glGetShaderivPtr = GetGLAdressProc<glGetShaderivFunction>("glGetShaderiv");
	glFunctions->glGetShaderInfoLogPtr = GetGLAdressProc<glGetShaderInfoLogFunction>("glGetShaderInfoLog");

	glFunctions->glAttachShaderPtr = GetGLAdressProc<glAttachShaderFunction>("glAttachShader");
	glFunctions->glCreateProgramPtr = GetGLAdressProc<glCreateProgramFunction>("glCreateProgram");
	glFunctions->glLinkProgramPtr = GetGLAdressProc<glLinkProgramFunction>("glLinkProgram");
	glFunctions->glGetProgramivPtr = GetGLAdressProc<glGetProgramivFunction>("glGetProgramiv");
	glFunctions->glGetProgramInfoLogPtr = GetGLAdressProc<glGetProgramInfoLogFunction>("glGetProgramInfoLog");

	glFunctions->glUseProgramPtr = GetGLAdressProc<glUseProgramFunction>("glUseProgram");
	glFunctions->glDrawArraysPtr = GetGLAdressProc<glDrawArraysFunction>("glDrawArrays");
	glFunctions->glDrawElementsPtr = GetGLAdressProc<glDrawElementsFunction>("glDrawElements");

    return true;
}

bool CreateGLContext(Window* window, PixelFormatInfo* pixelInfo, GLContextCreateInfo* contextCreateInfo)
{
	if (runtime->GetContextState() == false)
	{
		std::cout << "CreateGLContext Error: GL context is not initializated" << std::endl;
		return false;
	}

	return context->Create(window, pixelInfo, contextCreateInfo);
}

bool SetCurrentContext(Window* window)
{
	if (runtime->GetContextState() == false)
	{
		std::cout << "SetCurrentContext Error: GL context is not initializated" << std::endl;
		return false;
	}

	return context->SetCurrent(window);
}

bool ResetContext()
{
	return context->Reset();
}

bool DeleteGLContext(Window* window)
{
	if (runtime->GetContextState() == false)
	{
		std::cout << "DeleteGLContext Error: GL context is not initializated" << std::endl;
		return false;
	}

	return context->Delete(window);
}