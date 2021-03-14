#include "lighting.h"

#include <iostream>

namespace pix
{
	Light::Light(pixIndexType triangles)
	{
		init(triangles);
	}

	Light::~Light()
	{

	}
	
	void Light::setCenter(const glm::vec2 &center)
	{
		m_Center = center;
	}

	void Light::setTexCenter(const glm::vec2 &center)
	{
		m_TexCenter = center;
	}

	void Light::setColor(const glm::vec4 &color)
	{
		m_Color = color;
		m_TriangleFan.setColor(m_Color);
	}

	void Light::setRadius(const float radius)
	{
		m_Radius = radius;
	}
	
	void Light::setTexRadius(const float radius)
	{
		m_TexRadius = radius;
	}

	TriangleFan& Light::getTriangleFan()
	{
		return m_TriangleFan;
	}

	void Light::clip(std::vector<Rectangle> &rectangles)
	{
		int i;
		int j;
		int k;

		std::vector<Rectangle*> int_rectangles;
		int_rectangles.reserve(rectangles.size());

		glm::vec2 aux_vec1;
		glm::vec2 aux_vec2;
		
		//set the center
		m_TriangleFan.setVec2VertexPosition(0, m_Center);
		m_TriangleFan.setVertexTexCoords(0, m_TexCenter);

		//find the rectangles intersecting the circle
		for (i = 0; i < rectangles.size(); i++)
		{
			if (intersecting_circle_rectangle(rectangles[i].getVec2VertexPosition(0), rectangles[i].getVec2VertexPosition(2), m_Center, m_Radius))
			{
				int_rectangles.push_back(&rectangles[i]);
			}
		}

		glm::vec2 curr_point;
		glm::vec2 first_intersection;

		std::vector<glm::vec2> intersections;
		intersections.reserve(int_rectangles.size() * 4);

		IntersectionResult curr_result;
		unsigned int area_code1;
		unsigned int area_code2;

		for (i = 0; i <= m_TriangleCount; i++)
		{
			//find the current point to be set in the triangle fan
			curr_point = glm::vec2(m_Center.x + cosf(i * 2 * pixPI / m_TriangleCount) * m_Radius, m_Center.y + sinf(i * 2 * pixPI / m_TriangleCount) * m_Radius);

			//set the first intersection as the current point
			intersections.push_back(curr_point);

			//for each rectangle find the intersections
			for (j = 0; j < int_rectangles.size(); j++)
			{
				//find the area that contains the center
				area_code1 = point_rectangle_area_code(m_Center, int_rectangles[j]->getVec2VertexPosition(0), int_rectangles[j]->getVec2VertexPosition(2));
				//find the area that contains the current point
				area_code2 = point_rectangle_area_code(curr_point, int_rectangles[j]->getVec2VertexPosition(0), int_rectangles[j]->getVec2VertexPosition(2));

				if (!(area_code1 & area_code2))//if (code1 & code2) != 0 -> segment completely outside the rectangle
				{
					//for each side of the rectangle find the intersections with the current point
					for (k = 0; k < 4; k++)
					{
						curr_result = intersection_segment_segment(m_Center, curr_point, int_rectangles[j]->getVec2VertexPosition(k % 4), int_rectangles[j]->getVec2VertexPosition((k + 1) % 4));

						if (curr_result.count)//if an intersection was found, add it in the resuls vector
						{
							intersections.push_back(curr_result.point[0]);
						}
					}
				}
			}

			//all the intersections were found
			//now find the first one
			first_intersection = intersections[0];
			for (j = 1; j < intersections.size(); j++)
			{
				aux_vec1 = intersections[j] - m_Center;
				aux_vec2 = first_intersection - m_Center;

				//compare by the squared distance from the center of the circle
				if (dot2(aux_vec1, aux_vec1) < dot2(aux_vec2, aux_vec2))
				{
					first_intersection = intersections[j];
				}
			}

			intersections.clear();

			aux_vec1 = first_intersection - m_Center;
			aux_vec2 = curr_point - m_Center;

			glm::vec2 tex_coords;
			//normalize the distance from the center to the intersection
			float scale = dot2(aux_vec1, aux_vec1) / (m_Radius * m_Radius);
			//the normalized vector of the current point
			glm::vec2 norm_curr_point = glm::vec2(aux_vec2.x / m_Radius, aux_vec2.y / m_Radius);
			tex_coords = m_TexCenter + norm_curr_point * (m_TexRadius * scale);

			m_TriangleFan.setVec2VertexPosition(i + 1, first_intersection);

			m_TriangleFan.setVertexTexCoords(i + 1, tex_coords);
		}
	}
	
	void Light::init(pixIndexType triangles)
	{
		m_TriangleCount = triangles;
		m_TriangleFan.reserve(triangles);
	}
}