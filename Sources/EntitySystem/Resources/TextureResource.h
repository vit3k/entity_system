#pragma once
#include "Resource.h"
#include "../Graphics/Texture.h"

class TextureResource : public Resource<Graphics::Texture>
{
public:
	TextureResource(char* buffer,int size):Resource()
	{
		//object->loadFromMemory(buffer,size);
		object->LoadFromMemory(buffer,size);
	}
};

typedef std::shared_ptr<TextureResource> TextureResourceSP;