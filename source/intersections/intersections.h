#pragma once

#include <glm/glm.hpp>

namespace pix
{
	struct IntersectionResult
	{
		glm::vec2 point[2];
		int count;
	};

	float dot2(const glm::vec2 &a, const glm::vec2 &b);
	float det2(const glm::vec2 &a, const glm::vec2 &b);

	IntersectionResult intersection_ray_segment(const glm::vec2 &start_seg1, const glm::vec2 &end_seg1, const glm::vec2 &start_seg2, const glm::vec2 &end_seg2);
	IntersectionResult intersection_segment_segment(const glm::vec2 &start_seg1, const glm::vec2 &end_seg1, const glm::vec2 &start_seg2, const glm::vec2 &end_seg2);
	IntersectionResult intersection_circle_segment(const glm::vec2 &center, float radius, const glm::vec2 &start, const glm::vec2 &end);
	int intersection_circle_rectangle(glm::vec2 *points, glm::vec2 center, float radius, glm::vec2 *intersections);
	bool intersecting_circle_rectangle(const glm::vec2 &min, const glm::vec2 &max, const glm::vec2 &center, float radius);
}