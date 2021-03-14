#include "renderable2d.h"

namespace pix
{
	Renderable2D::Renderable2D()
	{
		
	}

	Renderable2D::~Renderable2D()
	{

	}

	const Vertex& Renderable2D::getVertex(unsigned int index) const
	{
		return m_VertexArray[index];
	}

	unsigned int Renderable2D::getVertexCount() const
	{
		return m_VertexArray.size();
	}

	pixIndexType Renderable2D::getIndex(unsigned int index) const
	{
		return m_IndexArray[index];
	}

	unsigned int Renderable2D::getIndexCount() const
	{
		return m_IndexArray.size();
	}

	const glm::vec2 Renderable2D::getVec2VertexPosition(unsigned int index) const
	{
		return glm::vec2(m_VertexArray[index].position.x, m_VertexArray[index].position.y);
		
	}

	const glm::vec3 Renderable2D::getVec3VertexPosition(unsigned int index) const
	{
		return m_VertexArray[index].position;
	}

	void Renderable2D::setVec2VertexPosition(unsigned int index, const glm::vec2 &point)
	{
		if (index < m_VertexArray.size())
		{
			m_VertexArray[index].position.x = point.x;
			m_VertexArray[index].position.y = point.y;
		}
	}

	void Renderable2D::setVec3VertexPosition(unsigned int index, const glm::vec3 &point)
	{
		if (index < m_VertexArray.size())
		{
			m_VertexArray[index].position = point;
		}
	}

	void Renderable2D::setVertexColor(unsigned int index, const glm::vec4 &color)
	{
		if (index < m_VertexArray.size())
		{
			m_VertexArray[index].color = color;
		}
	}

	void Renderable2D::setVertexTexCoords(unsigned int index, const glm::vec2 &tex_coords)
	{
		if (index < m_VertexArray.size())
		{
			m_VertexArray[index].texCoords = tex_coords;
		}
	}

	void Renderable2D::setVertex(unsigned int index, const Vertex &vertex)
	{
		if (index < m_VertexArray.size())
		{
			m_VertexArray[index] = vertex;
		}
	}

	void Renderable2D::setColor(const glm::vec4 &color)
	{
		std::vector<Vertex>::iterator it;

		for (it = m_VertexArray.begin(); it != m_VertexArray.end(); it++)
		{
			(*it).color = color;
		}
	}

	void Renderable2D::appendVertex(const Vertex &vertex)
	{
		m_VertexArray.push_back(vertex);
		//m_IndexArray.push_back(m_IndexArray.back() + 1);
	}

	void Renderable2D::appendIndex(pixIndexType element_index)
	{
		if (element_index < m_VertexArray.size())
		{
			m_IndexArray.push_back(element_index);
		}
	}

	void Renderable2D::setIndex(pixIndexType index, pixIndexType element_index)
	{
		if (index < m_IndexArray.size() && element_index < m_VertexArray.size())
		{
			m_IndexArray[index] = element_index;
		}
	}

	void Renderable2D::resizeCapacity(unsigned int size)
	{
		m_VertexArray.resize(size);
	}

	void Renderable2D::clearAll()
	{
		m_VertexArray.clear();
		m_IndexArray.clear();
	}

	void Renderable2D::clearVertices()
	{
		m_VertexArray.clear();
		//m_IndexArray.clear();
	}

	void Renderable2D::clearIndices()
	{
		//m_VertexArray.clear();
		m_IndexArray.clear();
	}
}