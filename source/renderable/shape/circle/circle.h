#pragma once

#include "../../renderable2d.h"

namespace pix
{
	class Circle : public Renderable2D
	{
	public:
		Circle(pixIndexType triangles);
		~Circle();

	public:
		using Renderable2D::getVertex;
		using Renderable2D::getIndex;
		using Renderable2D::getVec2VertexPosition;
		using Renderable2D::getVec3VertexPosition;
		using Renderable2D::getVertexCount;
		using Renderable2D::getIndexCount;

		//using Renderable2D::setVec2VertexPosition;
		//using Renderable2D::setVec3VertexPosition;
		using Renderable2D::setVertexColor;
		using Renderable2D::setVertexTexCoords;
		//using Renderable2D::setVertex;
		using Renderable2D::setColor;

		//other specific methods

	private:
		void init(pixIndexType sides);
	};
}