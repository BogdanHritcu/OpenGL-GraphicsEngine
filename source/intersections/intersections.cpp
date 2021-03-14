#include "intersections.h"

namespace pix
{
	float dot2(const glm::vec2 &a, const glm::vec2 &b)
	{
		return a.x * b.x + a.y * b.y;
	}

	float det2(const glm::vec2 &a, const glm::vec2 &b)
	{
		return a.x * b.y - a.y * b.x;
	}

	glm::vec2 clamp_vec2(const glm::vec2 &vec, const glm::vec2 &min, const glm::vec2 &max)
	{
		glm::vec2 result = vec;

		if (vec.x < min.x)
		{
			result.x = min.x;
		}

		if (vec.x > max.x)
		{
			result.x = max.x;
		}

		if (vec.y < min.y)
		{
			result.y = min.y;
		}

		if (vec.y > max.y)
		{
			result.y = max.y;
		}

		return result;
	}

	IntersectionResult intersection_ray_segment(const glm::vec2 &start_seg1, const glm::vec2 &end_seg1, const glm::vec2 &start_seg2, const glm::vec2 &end_seg2)
	{
		IntersectionResult result;
		result.point[0] = glm::vec2(0.0f, 0.0f);
		result.point[1] = glm::vec2(0.0f, 0.0f);

		glm::vec2 a = end_seg1 - start_seg1;

		glm::vec2 b = start_seg2 - end_seg2;

		glm::vec2 d = start_seg2 - start_seg1;

		float det = a.x * b.y - a.y * b.x;

		if (det == 0)
		{
			//parallel or coliniar
		}
		else
		{
			float r = det2(d, b) / det;
			float s = det2(a, d) / det;

			if (r >= 0 && r <= 1 && s >= 0 && s <= 1)
			{
				result.point[0] = start_seg1 + r * a;
				result.count = 1;
			}
		}

		return result;
	}

	IntersectionResult intersection_segment_segment(const glm::vec2 &start_seg1, const glm::vec2 &end_seg1, const glm::vec2 &start_seg2, const glm::vec2 &end_seg2)
	{
		IntersectionResult result;
		result.point[0] = glm::vec2(0.0f, 0.0f);
		result.point[1] = glm::vec2(0.0f, 0.0f);
		result.count = 0;

		float t1;
		float t2;

		glm::vec2 vec1 = end_seg1 - start_seg1;
		glm::vec2 vec2 = end_seg2 - start_seg2;

		glm::vec2 dif = start_seg2 - start_seg1;
		float det = det2(vec1, vec2);

		if (det == 0)
		{
			if (det2(dif, vec1) == 0)
			{
				t1 = dot2(dif, vec1) / dot2(vec1, vec1);
				t2 = t1 + dot2(vec2, vec1) / dot2(vec1, vec1);

				if (dot2(vec1, vec2) >= 0)
				{
					if (t1 <= 1 && t2 >= 0)
					{
						result.point[0] = start_seg1 + t1 * vec1;
						result.count = 1;
					}
				}
				else
				{
					if (t2 <= 1 && t1 >= 0)
					{
						result.point[0] = start_seg1 + t1 * vec1;
						result.count = 1;
					}
				}
			}
		}
		else
		{
			t1 = det2(dif, vec2) / det;
			t2 = det2(dif, vec1) / det;

			if (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1)
			{
				result.point[0] = start_seg1 + t1 * vec1;
				result.count = 1;
			}
		}

		return result;
	}

	IntersectionResult intersection_circle_segment(const glm::vec2 &center, float radius, const glm::vec2 &start, const glm::vec2 &end)
	{
		glm::vec2 seg = end - start;
		glm::vec2 ray = start - center;

		float a = dot2(seg, seg);
		float b = 2 * dot2(ray, seg);
		float c = dot2(ray, ray) - radius * radius;

		float delta = b * b - 4 * a * c;

		IntersectionResult result;

		if (delta < 0)
		{
			//
		}
		else
			if (delta == 0)
			{
				result.count = 1;

				delta = sqrtf(delta);

				float t1 = -b / (2 * a);

				if (t1 >= 0 && t1 <= 1)
				{
					result.point[0] = start + t1 * seg;
				}

				if (t1 < 0)
				{
					result.point[0] = start;
				}

				if (t1 > 1)
				{
					result.point[0] = end;
				}
			}
			else
			{
				delta = sqrtf(delta);

				float t1 = (-b - delta) / (2 * a);
				float t2 = (-b + delta) / (2 * a);

				if (t1 >= 0 && t1 <= 1)
				{
					//first intersection
					result.point[0] = start + t1 * seg;
					result.count++;
				}

				if (t1 < 0)
				{
					result.point[0] = start;
					result.count++;
				}

				if (t2 >= 0 && t2 <= 1)
				{
					//second intersection
					result.point[1] = start + t2 * seg;
					result.count++;
				}

				if (t2 > 1)
				{
					result.point[1] = end;
					result.count++;
				}
			}

		return result;
	}

	int intersection_circle_rectangle(glm::vec2 *points, glm::vec2 center, float radius, glm::vec2 *intersections)
	{
		int i;
		int j;
		int count = 0;
		IntersectionResult result;

		for (i = 0; i < 4; i++)
		{
			result = intersection_circle_segment(center, radius, points[i], points[(i + 1) % 4]);

			for (j = 0; j < result.count; j++)
			{
				intersections[count++] = result.point[j];
			}
		}

		return count;
	}

	bool intersecting_circle_rectangle(const glm::vec2 &min, const glm::vec2 &max, const glm::vec2 &center, float radius)
	{
		glm::vec2 closest = clamp_vec2(center, min, max);
		glm::vec2 d = center - closest;

		return (d.x * d.x + d.y * d.y < radius * radius);
	}
}

