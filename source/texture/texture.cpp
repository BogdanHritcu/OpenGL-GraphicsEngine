#include "texture.h"

namespace pix
{
	Texture::Texture()
	{
		glGenTextures(1, &m_TextureID);

		m_Width = 0;
		m_Height = 0;
		m_DataPointer = NULL;
	}

	Texture::Texture(unsigned int width, unsigned int height, unsigned char *data_pointer)
	{
		glGenTextures(1, &m_TextureID);

		m_Width = width;
		m_Height = height;
		m_DataPointer = data_pointer;

		create(m_Width, m_Height, m_DataPointer);
	}
	
	Texture::~Texture()
	{

	}

	void Texture::bind()
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, m_TextureID);
	}

	void Texture::create(unsigned int width, unsigned int height, unsigned char *data_pointer)
	{
		if (m_TextureID != 0)
		{
			m_Width = width;
			m_Height = height;
			m_DataPointer = data_pointer;

			bind();

			//RGB or RGBA
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data_pointer);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_NEAREST or GL_LINEAR
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //GL_NEAREST or GL_LINEAR
		}
	}

	unsigned int Texture::getWidth()
	{
		return m_Width;
	}

	unsigned int Texture::getHeight()
	{
		return m_Height;
	}

	unsigned char* Texture::getDataPtr()
	{
		return m_DataPointer;
	}

	unsigned int Texture::getID()
	{
		return m_TextureID;
	}
}