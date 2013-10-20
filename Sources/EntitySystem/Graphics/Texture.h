#pragma once

#include <string>
#include <SFML/Graphics/Image.hpp>
#include <memory>

namespace Graphics 
{

	class Texture
	{
	private:
		unsigned int textureId;
		unsigned short width,height;
		void Generate(sf::Image img);
	public:
		Texture();
		void LoadFromFile(std::string fileName);
		void LoadFromMemory(void* buffer,int size);
		void Use();
	};

	typedef std::shared_ptr<Texture> TextureSP;
}