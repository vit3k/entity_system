#pragma once
#include "Resource.h"
#include <SFML/Graphics.hpp>

class TextureResource : public Resource<sf::Texture>
{
public:
	TextureResource(char* buffer,int size)
	{
		object.loadFromMemory(buffer,size);
	}
};

typedef std::shared_ptr<TextureResource> TextureResourceSP;