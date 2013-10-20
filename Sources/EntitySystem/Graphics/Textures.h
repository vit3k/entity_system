#pragma once

#include <map>
#include <string>
#include "Texture.h"

namespace Graphics
{
	class Textures
	{
	private:
		static std::map<std::string,TextureSP> textures;
	public:
		static void LoadFromFile(std::string name, std::string filename);
		static TextureSP Get(std::string name) { return textures[name]; }
	};
}