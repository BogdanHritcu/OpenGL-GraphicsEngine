#include "render_buffer.h"

namespace pix
{
	RenderBuffer::RenderBuffer()
	{
		glGenRenderbuffers(1, &m_RenderBufferID);
	}

	RenderBuffer::RenderBuffer(unsigned int width, unsigned int height, unsigned int type)
	{
		glGenRenderbuffers(1, &m_RenderBufferID);

		create(width, height, type);
	}

	RenderBuffer::~RenderBuffer()
	{

	}

	void RenderBuffer::bind()
	{
		glBindRenderbuffer(GL_RENDERBUFFER, m_RenderBufferID);
	}

	void RenderBuffer::create(unsigned int width, unsigned int height, unsigned int type)
	{
		if (m_RenderBufferID != 0)
		{
			bind();
			
			glRenderbufferStorage(GL_RENDERBUFFER, type, width, height);
		}
	}

	unsigned int RenderBuffer::getWidth()
	{
		return m_Width;
	}

	unsigned int RenderBuffer::getHeight()
	{
		return m_Height;
	}

	unsigned int RenderBuffer::getID()
	{
		return m_RenderBufferID;
	}
}