#include "OpenGL.h"
#include "glDefines.h"

GLFunctions* glFunctions;

void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	glFunctions->glClearColorPtr(red, green, blue, alpha);
}

void glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
	glFunctions->glViewportPtr(x, y, width, height);
}

void glClear(GLbitfield mask)
{
	glFunctions->glClearPtr(mask);
}

void glGenBuffers(GLsizei n, GLuint* buffers)
{
	glFunctions->glGenBuffersPtr(n, buffers);
}

void glBindBuffer(GLenum target, GLuint buffer)
{
	glFunctions->glBindBufferPtr(target, buffer);
}

void glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage)
{
	glFunctions->glBufferDataPtr(target, size, data, usage);
}

GLuint glCreateShader(GLenum shaderType)
{
	return glFunctions->glCreateShaderPtr(shaderType);
}

void glShaderSource(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length)
{
	glFunctions->glShaderSourcePtr(shader, count, string, length);
}

void glCompileShader(GLuint shader)
{
	glFunctions->glCompileShaderPtr(shader);
}

GLuint glCreateProgram()
{
	return glFunctions->glCreateProgramPtr();
}

void glAttachShader(GLuint program, GLuint shader)
{
	glFunctions->glAttachShaderPtr(program, shader);
}

void glLinkProgram(GLuint program)
{
	glFunctions->glLinkProgramPtr(program);
}

void glUseProgram(GLuint program)
{
	glFunctions->glUseProgramPtr(program);
}

void glGetProgramiv(GLenum target, GLenum pname, GLint* params)
{
	glFunctions->glGetProgramivPtr(target, pname, params);
}

void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog)
{
	glFunctions->glGetProgramInfoLogPtr(program, bufSize, length, infoLog);
}

void glDrawArrays(GLenum mode, GLint first, GLsizei count)
{
	glFunctions->glDrawArraysPtr(mode, first, count);
}

void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices)
{
	glFunctions->glDrawElementsPtr(mode, count, type, indices);
}

void glDeleteShader(GLuint shader)
{
	glFunctions->glDeleteShaderPtr(shader);
}

void glGetShaderiv(GLuint shader, GLenum pname, GLint* params)
{
	glFunctions->glGetShaderivPtr(shader, pname, params);
}

void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog)
{
	glFunctions->glGetShaderInfoLogPtr(shader, bufSize, length, infoLog);
}

void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer)
{
	glFunctions->glVertexAttribPointerPtr(index, size, type, normalized, stride, pointer);
}

void glEnableVertexAttribArray(GLuint index)
{
	glFunctions->glEnableVertexAttribArrayPtr(index);
}

void glGenVertexArrays(GLsizei n, GLuint* arrays)
{
	glFunctions->glGenVertexArraysPtr(n, arrays);
}

void glBindVertexArray(GLuint array)
{
	glFunctions->glBindVertexArrayPtr(array);
}
