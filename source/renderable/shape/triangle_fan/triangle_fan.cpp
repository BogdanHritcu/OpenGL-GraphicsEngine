#include "triangle_fan.h"

namespace pix
{
	TriangleFan::TriangleFan()
	{
		//init(10); //reserve default space for the triangle fan
	}

	TriangleFan::TriangleFan(pixIndexType triangles)
	{
		init(triangles);
	}

	TriangleFan::~TriangleFan()
	{

	}

	void TriangleFan::reserve(pixIndexType triangles)
	{
		init(triangles);
	}

	void TriangleFan::init(pixIndexType triangles)
	{
		pixIndexType points = triangles + 2;

		m_VertexArray.reserve(points);

		m_IndexArray.reserve(triangles * 3);
	
		pixIndexType i;
		
		Vertex vertex;
		vertex.position = glm::vec3(0.0f, 0.0f, 0.0f);

		for (i = 0; i < points; i++)
		{
			m_VertexArray.push_back(vertex);
		}
		
		for (i = 1; i <= triangles; i++)
		{
			m_IndexArray.push_back(0); //append center
			m_IndexArray.push_back(i); //append the second index of the triangle
			m_IndexArray.push_back(i + 1); //append the last index of the triangle 
		}
	}
}