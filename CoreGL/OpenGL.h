#pragma once
#include "glTypes.h"

extern "C"
{
	GL_LOADER_EXPORT void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

	GL_LOADER_EXPORT void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);

	GL_LOADER_EXPORT void glClear(GLbitfield mask);

	GL_LOADER_EXPORT void glGenBuffers(GLsizei n, GLuint* buffers);

	GL_LOADER_EXPORT void glBindBuffer(GLenum target, GLuint buffer);

	GL_LOADER_EXPORT void glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage);

	GL_LOADER_EXPORT GLuint glCreateShader(GLenum shaderType);

	GL_LOADER_EXPORT void glShaderSource(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);

	GL_LOADER_EXPORT void glCompileShader(GLuint shader);

	GL_LOADER_EXPORT GLuint glCreateProgram();

	GL_LOADER_EXPORT void glAttachShader(GLuint program, GLuint shader);

	GL_LOADER_EXPORT void glLinkProgram(GLuint program);

	GL_LOADER_EXPORT void glUseProgram(GLuint program);

	GL_LOADER_EXPORT void glGetProgramiv(GLenum target, GLenum pname, GLint* params);

	GL_LOADER_EXPORT void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);

	GL_LOADER_EXPORT void glDrawArrays(GLenum mode, GLint first, GLsizei count);

	GL_LOADER_EXPORT void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices);

	GL_LOADER_EXPORT void glDeleteShader(GLuint shader);

	GL_LOADER_EXPORT void glGetShaderiv(GLuint shader, GLenum pname, GLint* params);

	GL_LOADER_EXPORT void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);

	GL_LOADER_EXPORT void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);

	GL_LOADER_EXPORT void glEnableVertexAttribArray(GLuint index);

	GL_LOADER_EXPORT void glGenVertexArrays(GLsizei n, GLuint* arrays);

	GL_LOADER_EXPORT void glBindVertexArray(GLuint array);
}