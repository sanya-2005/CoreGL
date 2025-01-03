#pragma once
/*
* ���� �������� OpenGL �������, �����: 
* �������� ��� ������� � glPrototypes � glDefines.h.
* �������� ��������� �� ������� � GLFunctions.
* �������� �������� ��������� �� ������ � LoadCoreGL � glContext.cpp.
* �������� ���� ������� � OpenGL.h
*/

class IGLLoader
{
public:
	virtual void* LoadFunction(const char* name) = 0;
};

extern IGLLoader* loader;

template<typename T>
T GetGLAdressProc(const char* name)
{
	return (T)loader->LoadFunction(name);
}
