#pragma once

#include <vector>
//#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>

#include "../defines/defines.h"
#include "../vertex/vertex.h"

namespace pix
{
	class Renderable2D
	{
	protected:
		std::vector<Vertex> m_VertexArray;
		std::vector<pixIndexType> m_IndexArray; //set by every child class

	public:
		Renderable2D();
		~Renderable2D();

	public:
		const Vertex& getVertex(unsigned int index) const;
		unsigned int getVertexCount() const;
		pixIndexType getIndex(unsigned int index) const;
		unsigned int getIndexCount() const;
		const glm::vec2 getVec2VertexPosition(unsigned int index) const;
		const glm::vec3 getVec3VertexPosition(unsigned int index) const;

		void setVec2VertexPosition(unsigned int index, const glm::vec2 &point);
		void setVec3VertexPosition(unsigned int index, const glm::vec3 &point);

		void setVertexColor(unsigned int index, const glm::vec4 &color);
		void setVertexTexCoords(unsigned int index, const glm::vec2 &tex_coords);

		void setVertex(unsigned int index, const Vertex &vertex);
		
		void setColor(const glm::vec4 &color);

		void setIndex(pixIndexType index, pixIndexType element_index);
		
		void appendVertex(const Vertex &vertex);
		void appendIndex(pixIndexType element_index);
		
		void resizeCapacity(unsigned int size);
		void clearAll();
		void clearVertices();
		void clearIndices();
	};
}