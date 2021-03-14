#include "rectangle.h"

namespace pix
{
	Rectangle::Rectangle()
	{
		init();
	}

	Rectangle::~Rectangle()
	{

	}

	void Rectangle::setVec2Position(const glm::vec2 &pos)
	{

	}

	void Rectangle::setVec3Position(const glm::vec3 &pos)
	{

	}

	void Rectangle::setSize(const glm::vec2 &size)
	{

	}

	const glm::vec2 Rectangle::getVec2Position() const
	{
		return glm::vec2(m_VertexArray.front().position.x, m_VertexArray.front().position.y);
	}

	const glm::vec3 Rectangle::getVec3Position() const
	{
		return m_VertexArray.front().position;
	}

	void Rectangle::init()
	{
		m_VertexArray.resize(4);

		m_IndexArray.reserve(6);

		m_IndexArray.push_back(0);
		m_IndexArray.push_back(1);
		m_IndexArray.push_back(2);
		m_IndexArray.push_back(2);
		m_IndexArray.push_back(3);
		m_IndexArray.push_back(0);

		m_IndexArray.shrink_to_fit();
	}

	void Rectangle::regen()
	{

	}
}