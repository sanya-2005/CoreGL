#pragma once

namespace gpu
{
	enum ShaderType
	{
		VertexShader,
		FragmentShader
	};

	class Shader
	{
	private:
		ShaderType type;
	};
}