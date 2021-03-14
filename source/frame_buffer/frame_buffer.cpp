#include "frame_buffer.h"

namespace pix
{
	FrameBuffer::FrameBuffer()
	{
		glGenFramebuffers(1, &m_FrameBufferID);
	}

	FrameBuffer::~FrameBuffer()
	{
		glDeleteFramebuffers(1, &m_FrameBufferID);
	}

	void FrameBuffer::bind()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_FrameBufferID);
	}

	void FrameBuffer::attachTexture(unsigned int attachmentID, unsigned int attachmentType)
	{
		bind();
		glFramebufferTexture2D(GL_FRAMEBUFFER, attachmentType, GL_TEXTURE_2D, attachmentID, 0);
	}

	void FrameBuffer::attachRenderBuffer(unsigned int attachmentID, unsigned int attachmentType)
	{
		bind();
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachmentType, GL_RENDERBUFFER, attachmentID);
	}

	void FrameBuffer::clearBuffer(GLbitfield mask)
	{
		bind();
		glClear(mask);
	}

	void FrameBuffer::clearColorBuffer(glm::vec4 color)
	{
		bind();
		glClearColor(color.x, color.y, color.z, color.w);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}