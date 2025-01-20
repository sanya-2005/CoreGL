#pragma once

#ifdef _WINDOWS

#ifdef COREGL_PROJECT
	#define GL_LOADER_EXPORT __declspec(dllexport)
#else
	#define GL_LOADER_EXPORT __declspec(dllimport)
#endif

#else
	#define GL_LOADER_EXPORT
#endif

