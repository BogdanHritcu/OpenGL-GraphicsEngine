#pragma once

#include <iostream>
#include <limits>
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>

#include "../defines/defines.h"
#include "../renderable/renderable2d.h"
#include "../shader/shader.h"
#include "../texture/texture.h"

namespace pix
{
	class Renderer2D
	{
	protected:
		GLuint m_VertexArrayID;
		GLuint m_VerticesSubmittedCount;

		GLuint m_AttributeBufferID;
		Vertex *m_AttributeBufferPtr;
		
		GLuint m_IndexBufferID;
		pixIndexType *m_IndexBufferPtr;
		GLsizei m_ElementsSubmittedCount;

		std::vector<glm::mat4> m_TransformationStack;

		Shader m_Shader;
		glm::mat4 m_ProjectionMat;

		std::vector<Texture*> m_Textures;
		bool m_Blend;

	protected:
		Renderer2D(const Shader &shader, const glm::mat4 &projectionMat);

	public:
		Renderer2D();
		~Renderer2D();

		void begin();
		virtual void submit(Renderable2D &renderable) = 0;
		void end();
		virtual void flush(bool reset) = 0;
		void enableBlending(bool blend = true);
		void setBlendFunc(GLenum sfactor, GLenum dfactor);

		void push_backTexture(Texture *texture);
		void pop_backTexture();
		void setProjectionMat(const glm::mat4 &projection);
		void push_backTransform(const glm::mat4 &matrix);
		void pop_backTransform();
		void resizeTransformStack(unsigned int size);

		const Shader& getShader() const;

	private:
		void init();
	};
}