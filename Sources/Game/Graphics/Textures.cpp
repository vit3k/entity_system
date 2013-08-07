#include "Textures.h"
#include "../Application/Application.h"

bool Textures::Load(const TextureId& id,const ResourceId& resource)
{
	TextureStrongPtr texture(new sf::Texture());
	ResourceStrongPtr res = Application::Instance().Resources()->Get(resource);
	texture->loadFromMemory(res->Buffer(),res->Size());
	textures[id] = texture;
	
	return true;
}

TextureStrongPtr Textures::Get(const TextureId& id)
{
	return textures[id];
}