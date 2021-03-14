#pragma once

#include <glm/glm.hpp>

#include "../defines/defines.h"

namespace pix
{
	unsigned int point_rectangle_area_code(const glm::vec2 &point, const glm::vec2 &min, const glm::vec2 &max);

	struct RectangleC //provizoriu
	{
		glm::vec2 min;
		glm::vec2 max;

		glm::vec2 getPoint(unsigned int index);
	};
}