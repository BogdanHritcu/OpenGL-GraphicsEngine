#pragma once

#include "../../renderable2d.h"

namespace pix
{
	class Rectangle : public Renderable2D
	{
	public:
		Rectangle();
		~Rectangle();

	public:
		using Renderable2D::getVertex;
		using Renderable2D::getIndex;
		using Renderable2D::getVec2VertexPosition;
		using Renderable2D::getVec3VertexPosition;
		using Renderable2D::getVertexCount;
		using Renderable2D::getIndexCount;

		using Renderable2D::setVec2VertexPosition;
		using Renderable2D::setVec3VertexPosition;
		using Renderable2D::setVertexColor;
		using Renderable2D::setVertexTexCoords;
		using Renderable2D::setVertex;
		using Renderable2D::setColor;

		void setVec2Position(const glm::vec2 &pos);
		void setVec3Position(const glm::vec3 &pos);

		void setSize(const glm::vec2 &size);

		const glm::vec2 getVec2Position() const;
		const glm::vec3 getVec3Position() const;

	private:
		void init();
		void regen();
	};
}