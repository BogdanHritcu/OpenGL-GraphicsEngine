#include "clipping.h"

namespace pix
{
	unsigned int point_rectangle_area_code(const glm::vec2 &point, const glm::vec2 &min, const glm::vec2 &max)
	{
		unsigned int code = 0;

		if (point.x < min.x)
		{
			code |= pixLEFT;
		}

		if (point.x > max.x)
		{
			code |= pixRIGHT;
		}

		if (point.y < min.y)
		{
			code |= pixUP;
		}

		if (point.y > max.y)
		{
			code |= pixDOWN;
		}

		return code;
	}

	glm::vec2 RectangleC::getPoint(unsigned int index)
	{
		glm::vec2 size = max - min;
		switch (index)
		{
		case 0:
			return min;
		
		case 1:
			return min + glm::vec2(size.x, 0.0f);

		case 2:
			return max;
		
		case 3:
			return min + glm::vec2(0.0f, size.y);

		default:
			return glm::vec2(0, 0);
		}
	}
}