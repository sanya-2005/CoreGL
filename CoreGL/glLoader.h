#pragma once
/*
* Чтоб добавить OpenGL функцию, нужно: 
* Добавить тип функции в glPrototypes в glDefines.h.
* Добавить указатель на функцию в GLFunctions.
* Добавить загрузку указателя на фунцию в LoadCoreGL в glContext.cpp.
* Добавить саму функцию в OpenGL.h
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
