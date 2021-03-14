#pragma once

#include <iostream>

#include <glad/glad.h>

namespace pix
{
	class RenderBuffer
	{
	private:
		unsigned int m_RenderBufferID;
		unsigned int m_Width;
		unsigned int m_Height;

	public:
		RenderBuffer();
		RenderBuffer(unsigned int width, unsigned int height, unsigned int type);
		~RenderBuffer();
		
		void bind();
		void create(unsigned int width, unsigned int height, unsigned int type);
		unsigned int getWidth();
		unsigned int getHeight();
		unsigned int getID();
	};
}