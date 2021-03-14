#include "layer.h"

namespace pix
{
	Layer::Layer(const char* vertShaderPath, const char* fragShaderPath, const glm::mat4 &projectionMat) :
		Renderer2D(Shader(vertShaderPath, fragShaderPath), projectionMat)
	{
		setProjectionMat(m_ProjectionMat);
	}

	Layer::~Layer()
	{

	}

	void Layer::submit(Renderable2D &renderable)
	{
		unsigned int i;

		for (i = 0; i < renderable.getIndexCount(); i++)
		{
			*m_IndexBufferPtr = m_VerticesSubmittedCount + renderable.getIndex(i);
			m_IndexBufferPtr++;

			m_ElementsSubmittedCount++;
		}

		for (i = 0; i < renderable.getVertexCount(); i++)
		{
			m_AttributeBufferPtr->position = glm::vec3(m_TransformationStack.back() * glm::vec4(renderable.getVertex(i).position, 1.0f));

			m_AttributeBufferPtr->color = renderable.getVertex(i).color;
			m_AttributeBufferPtr->texCoords = renderable.getVertex(i).texCoords;
			m_AttributeBufferPtr++;

			m_VerticesSubmittedCount++;
		}
	}

	void Layer::flush(bool reset)
	{
		//use shader
		m_Shader.use();

		glBindVertexArray(m_VertexArrayID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
		
		//use textures if any
		unsigned int i;
		for (i = 0; i < m_Textures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			m_Textures[i]->bind();
		}
		
		//enable blending
		if (m_Blend)
		{
			glEnable(GL_BLEND);
		}

		glDrawElements(GL_TRIANGLES, m_ElementsSubmittedCount, pixINDEX_TYPE, NULL);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
		glBindVertexArray(NULL);

		//disable blending
		glDisable(GL_BLEND);
		glActiveTexture(GL_TEXTURE0);

		if (reset)
		{
			m_ElementsSubmittedCount = 0;
			m_VerticesSubmittedCount = 0;
		}
	}
}
