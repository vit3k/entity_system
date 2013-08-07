#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "../Application/Resource.h"

typedef char* TextureId;

typedef std::shared_ptr<sf::Texture> TextureStrongPtr;
typedef std::map<TextureId,TextureStrongPtr> TextureList;

class Textures 
{
private:
	TextureList textures;
public:
	TextureStrongPtr Get(const TextureId& id);
	bool Load(const TextureId& id,const ResourceId& resource);
};