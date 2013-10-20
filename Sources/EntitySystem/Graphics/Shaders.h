#pragma once
#include <map>
#include <string>
#include "Shader.h"

namespace Graphics
{
	class Shaders
	{
	private:
		static std::map<std::string,ShaderSP> shaders;
	public:
		static void LoadFromFiles(std::string name,std::string vertexShader, std::string pixelShader);
		static ShaderSP Get(std::string name) { return shaders[name]; }
	};
}