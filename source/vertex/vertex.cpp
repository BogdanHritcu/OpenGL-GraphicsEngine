#include "vertex.h"

namespace pix
{
	Vertex::Vertex()
	{
		position = glm::vec3(0.0f, 0.0f, 0.0f);
		color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		texCoords = glm::vec2(0.0f, 0.0f);
	}

	Vertex::~Vertex()
	{

	}
}