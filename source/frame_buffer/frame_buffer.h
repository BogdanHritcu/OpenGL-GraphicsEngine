#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

namespace pix
{
	class FrameBuffer
	{
	private:
		unsigned int m_FrameBufferID;

	public:
		FrameBuffer();
		~FrameBuffer();
	
		void bind();
		void attachTexture(unsigned int attachmentID, unsigned int attachmentType);
		void attachRenderBuffer(unsigned int attachmentID, unsigned int attachmentType);
		void clearBuffer(GLbitfield mask = GL_COLOR_BUFFER_BIT);
		void clearColorBuffer(glm::vec4 color);
	};
}