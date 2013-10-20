#include "Texture.h"
#include <SFML\Graphics.hpp>
#include <GL\glew.h>

namespace Graphics
{
	Texture::Texture()
	{
	}
	void Texture::LoadFromFile(std::string fileName)
	{
		sf::Image img;
		img.loadFromFile(fileName);
		Generate(img);
	}
	void Texture::LoadFromMemory(void* buffer,int size)
	{
		sf::Image img;
		img.loadFromMemory(buffer,size);
		Generate(img);
	}

	void Texture::Generate(sf::Image img)
	{
		auto size = img.getSize();
		width = size.x;
		height = size.y;
		glGenTextures(1, &textureId);
		glBindTexture(GL_TEXTURE_2D, textureId);
		glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.getPixelsPtr());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	void Texture::Use()
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureId);
	}
}