#pragma once

#include <glm/glm.hpp>

#include "../clipping/clipping.h"
#include "../intersections/intersections.h"
#include "../renderable/shape/triangle_fan/triangle_fan.h"
#include "../renderable/shape/rectangle/rectangle.h"

namespace pix
{
	class Light
	{
	private:
		glm::vec2 m_Center;
		glm::vec2 m_TexCenter;
		pixIndexType m_TriangleCount;
		float m_Radius;
		float m_TexRadius;
		
		glm::vec4 m_Color;

		TriangleFan m_TriangleFan;

	public:
		Light(pixIndexType triangles);
		~Light();
	
	public:
		void setCenter(const glm::vec2 &center);
		void setTexCenter(const glm::vec2 &center);
		void setColor(const glm::vec4 &color);
		void setRadius(const float radius);
		void setTexRadius(const float radius);

		TriangleFan& getTriangleFan();

		void clip(std::vector<Rectangle> &rectangles);

	private:
		void init(pixIndexType triangles);
	};
}