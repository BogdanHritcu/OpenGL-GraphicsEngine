#pragma once
#define pixVERTEX_H

#include <glm/gtc/matrix_transform.hpp>

#include "../defines/defines.h"

namespace pix
{
	struct Vertex
	{
	public:
		glm::vec3 position;
		glm::vec4 color;
		glm::vec2 texCoords;

	public:
		Vertex();
		~Vertex();
	};
}