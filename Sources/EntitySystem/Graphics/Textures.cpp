#include "Textures.h"
#include "../LowLevel/Files.h"

namespace Graphics
{
	std::map<std::string,TextureSP> Textures::textures;

	void Textures::LoadFromFile(std::string name,std::string fileName)
	{
		char* buffer;
		int size;
		bool result = Files::LoadBinary(fileName,&buffer,&size);
		if(!result)
			return;
		TextureSP texture = std::make_shared<Texture>();
		texture->LoadFromMemory(buffer,size);
		textures[name] = texture;
	}
}