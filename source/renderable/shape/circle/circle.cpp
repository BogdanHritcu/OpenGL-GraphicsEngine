#include "circle.h"

namespace pix
{
	Circle::Circle(pixIndexType triangles)
	{
		init(triangles);
	}

	Circle::~Circle()
	{

	}

	void Circle::init(pixIndexType sides)
	{
		m_VertexArray.reserve(sides + 1);

		m_IndexArray.reserve(sides * 3);

		pixIndexType i;

		for (i = 1; i <= sides; i++)
		{
			m_IndexArray.push_back(0); //append center
			m_IndexArray.push_back(i); //append the second index of the triangle
			m_IndexArray.push_back(i % sides + 1); //append the last index of the triangle 
		}
	}
}