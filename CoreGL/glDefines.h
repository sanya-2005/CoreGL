#pragma once
#include "glTypes.h"

namespace glPrototypes
{
	typedef void (GL_API glClearColorFunction)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	typedef void (GL_API glViewportFunction)(GLint x, GLint y, GLsizei width, GLsizei height);
	typedef void (GL_API glClearFunction)(GLbitfield mask);
	typedef void (GL_API glGenBuffersFuncion) (GLsizei n, GLuint* buffers);
	typedef GLuint(GL_API glCreateShaderFuncion) (GLenum shaderType);
	typedef void (GL_API glBindBufferFunction) (GLenum target, GLuint buffer);
	typedef void (GL_API glBufferDataFunction) (GLenum target, GLsizeiptr size, const void* data, GLenum usage);
	typedef void (GL_API glShaderSourceFunction) (GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
	typedef void (GL_API glCompileShaderFunction) (GLuint shader);
	typedef GLuint(GL_API glCreateProgramFunction) (void);
	typedef void (GL_API glAttachShaderFunction) (GLuint program, GLuint shader);
	typedef void (GL_API glLinkProgramFunction) (GLuint program);
	typedef void (GL_API glUseProgramFunction) (GLuint program);
	typedef void (GL_API glDeleteShaderFunction) (GLuint shader);
	typedef void (GL_API glGetShaderivFunction) (GLuint shader, GLenum pname, GLint* params);
	typedef void (GL_API glGetShaderInfoLogFunction) (GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
	typedef void (GL_API glGetProgramivFunction) (GLenum target, GLenum pname, GLint* params);
	typedef void (GL_API glGetProgramInfoLogFunction) (GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);

	typedef void (GL_API glVertexAttribPointerFunction) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
	typedef void (GL_API glEnableVertexAttribArrayFunction) (GLuint index);
	typedef void (GL_API glGenVertexArraysFunction) (GLsizei n, GLuint* arrays);
	typedef void (GL_API glBindVertexArrayFunction) (GLuint array);

	typedef void (GL_API glDrawArraysFunction) (GLenum mode, GLint first, GLsizei count);
	typedef void (GL_API glDrawElementsFunction) (GLenum mode, GLsizei count, GLenum type, const void* indices);

		typedef void (GL_API glShaderBinaryFunction) (GLsizei count, const GLuint* shaders, GLenum binaryFormat, const void* binary, GLsizei length);
		typedef void (GL_API glSpecializeShaderFunction) (GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, 
														  const GLuint* pConstantIndex, const GLuint* pConstantValue);
}


struct GLFunctions
{
	glPrototypes::glClearColorFunction glClearColorPtr;
	glPrototypes::glViewportFunction glViewportPtr;
	glPrototypes::glClearFunction glClearPtr;

	glPrototypes::glGenBuffersFuncion glGenBuffersPtr;
	glPrototypes::glBindBufferFunction glBindBufferPtr;
	glPrototypes::glBufferDataFunction glBufferDataPtr;

	glPrototypes::glVertexAttribPointerFunction glVertexAttribPointerPtr;
	glPrototypes::glEnableVertexAttribArrayFunction glEnableVertexAttribArrayPtr;
	glPrototypes::glGenVertexArraysFunction glGenVertexArraysPtr;
	glPrototypes::glBindVertexArrayFunction glBindVertexArrayPtr;

	glPrototypes::glCreateShaderFuncion glCreateShaderPtr;
	glPrototypes::glShaderSourceFunction glShaderSourcePtr;
	glPrototypes::glCompileShaderFunction glCompileShaderPtr;
	glPrototypes::glDeleteShaderFunction glDeleteShaderPtr;
	glPrototypes::glGetShaderivFunction glGetShaderivPtr;
	glPrototypes::glGetShaderInfoLogFunction glGetShaderInfoLogPtr;

	glPrototypes::glCreateProgramFunction glCreateProgramPtr;
	glPrototypes::glAttachShaderFunction glAttachShaderPtr;
	glPrototypes::glLinkProgramFunction glLinkProgramPtr;
	glPrototypes::glGetProgramivFunction glGetProgramivPtr;
	glPrototypes::glGetProgramInfoLogFunction glGetProgramInfoLogPtr;

	glPrototypes::glUseProgramFunction glUseProgramPtr;
	glPrototypes::glDrawArraysFunction glDrawArraysPtr;
	glPrototypes::glDrawElementsFunction glDrawElementsPtr;

	glPrototypes::glShaderBinaryFunction glShaderBinaryPtr;
	glPrototypes::glSpecializeShaderFunction glSpecializeShaderPtr;
};

extern GLFunctions* glFunctions;