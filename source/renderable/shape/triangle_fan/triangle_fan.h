#pragma once

#include "../../renderable2d.h"

namespace pix
{
	class TriangleFan : public Renderable2D
	{
	public:
		TriangleFan();
		TriangleFan(pixIndexType triangles);
		~TriangleFan();

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
		using Renderable2D::setIndex;
		using Renderable2D::setColor;

		using Renderable2D::appendVertex;
		using Renderable2D::appendIndex;

		//other specific methods
		void reserve(pixIndexType triangles);

	private:
		void init(pixIndexType triangles);
	};
}