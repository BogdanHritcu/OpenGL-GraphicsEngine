#include "renderer2d.h"

namespace pix
{
	Renderer2D::Renderer2D()
	{
		m_TransformationStack.reserve(pixTRANSFORM_STACK_SIZE);
		init();
	}

	Renderer2D::Renderer2D(const Shader &shader, const glm::mat4 &projectionMat) :
		m_Shader(shader),
		m_ProjectionMat(projectionMat)
	{
		m_TransformationStack.reserve(pixTRANSFORM_STACK_SIZE);
		init();
	}

	Renderer2D::~Renderer2D()
	{

	}

	void Renderer2D::begin()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_AttributeBufferID);

		m_AttributeBufferPtr = (Vertex*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		if (m_AttributeBufferPtr == NULL)
		{
			std::cout << "Pointer to attribute buffer is NULL" << std::endl;
		}

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);

		m_IndexBufferPtr = (pixIndexType*)glMapBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_WRITE_ONLY);
		if (m_IndexBufferPtr == NULL)
		{
			std::cout << "Pointer to index buffer is NULL" << std::endl;
		}
	}

	void Renderer2D::end()
	{
		if (!glUnmapBuffer(GL_ARRAY_BUFFER))
		{
			std::cout << "Could not unmap the attribute buffer!" << std::endl;
		}

		glBindBuffer(GL_ARRAY_BUFFER, NULL);

		if (!glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER))
		{
			std::cout << "Could not unmap the index buffer!" << std::endl;
		}

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
	}

	void Renderer2D::enableBlending(bool blend)
	{
		m_Blend = blend;
	}

	void Renderer2D::setBlendFunc(GLenum sfactor, GLenum dfactor)
	{
		glBlendFunc(sfactor, dfactor);
	}

	void Renderer2D::push_backTransform(const glm::mat4 &matrix)
	{
		m_TransformationStack.push_back(m_TransformationStack.back() * matrix);
	}

	void Renderer2D::pop_backTransform()
	{
		m_TransformationStack.pop_back();
	}

	void Renderer2D::push_backTexture(Texture *texture)
	{
		m_Textures.push_back(texture);
	}

	void Renderer2D::pop_backTexture()
	{
		m_Textures.pop_back();
	}

	void Renderer2D::setProjectionMat(const glm::mat4 &projection)
	{
		m_ProjectionMat = projection;
		m_Shader.use();
		m_Shader.setMat4("projection", glm::value_ptr(m_ProjectionMat));
	}

	void Renderer2D::resizeTransformStack(unsigned int size)
	{
		if (size > 0)
		{
			m_TransformationStack.resize(size);
		}
	}

	const Shader& Renderer2D::getShader() const
	{
		return m_Shader;
	}

	void Renderer2D::init()
	{
		glGenBuffers(1, &m_AttributeBufferID);
		glGenVertexArrays(1, &m_VertexArrayID);

		glBindVertexArray(m_VertexArrayID);

		glBindBuffer(GL_ARRAY_BUFFER, m_AttributeBufferID);
		glBufferData(GL_ARRAY_BUFFER, pixVERTEX_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

		glEnableVertexAttribArray(pixVERTEX_POSITION_LAYOUT);
		glEnableVertexAttribArray(pixVERTEX_COLOR_LAYOUT);
		glEnableVertexAttribArray(pixVERTEX_TEX_COORDS_LAYOUT);

		glVertexAttribPointer(pixVERTEX_POSITION_LAYOUT, pixPOS_FLOAT_COUNT, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)pixATTR0_OFFSET);
		glVertexAttribPointer(pixVERTEX_COLOR_LAYOUT, pixCOLOR_FLOAT_COUNT, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(pixATTR1_OFFSET * sizeof(GLfloat)));
		glVertexAttribPointer(pixVERTEX_TEX_COORDS_LAYOUT, pixTEX_COORDS_FLOAT_COUNT, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(pixATTR2_OFFSET * sizeof(GLfloat)));
		
		glBindBuffer(GL_ARRAY_BUFFER, NULL);


		glGenBuffers(1, &m_IndexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, pixINDEX_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

		glBindVertexArray(NULL);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);

		//default values
		m_Blend = false;
		glBlendFunc(GL_ONE, GL_ONE);
		m_ElementsSubmittedCount = 0;
		m_VerticesSubmittedCount = 0;
		m_TransformationStack.push_back(glm::mat4(1.0f));
	}

}