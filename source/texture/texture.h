#pragma once

#include <iostream>

#include <glad/glad.h>

namespace pix
{
	class Texture
	{
	private:
		unsigned int m_TextureID;
		unsigned int m_Width;
		unsigned int m_Height;
		unsigned char *m_DataPointer;

	public:
		Texture();
		Texture(unsigned int width, unsigned int height, unsigned char *data_pointer);
		~Texture();

		void bind();
		void create(unsigned int width, unsigned int height, unsigned char *data_pointer);
		unsigned int getWidth();
		unsigned int getHeight();
		unsigned char* getDataPtr();
		unsigned int getID();
	};
}