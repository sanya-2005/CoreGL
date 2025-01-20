#pragma once
#include "Types.h"

namespace gpu
{
	class GLResource
	{
	private:
		int64 id;

	public:
		GLResource(int64 id) : id(id)
		{

		}

		int64 GetID()
		{
			return id;
		}
	};
}