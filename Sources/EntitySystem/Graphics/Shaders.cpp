#include "Shaders.h"
#include "../LowLevel/Files.h"

namespace Graphics
{
	std::map<std::string,ShaderSP> Shaders::shaders;

	void Shaders::LoadFromFiles(std::string name,std::string vertexShader, std::string pixelShader)
	{
		char* buffer;
		int size;

		bool result = Files::LoadBinary(vertexShader,&buffer,&size);
		if(!result)
			return;
		std::string vsSource(buffer,size);
		delete buffer;
		
		result = Files::LoadBinary(pixelShader,&buffer,&size);
		if(!result)
			return;
		std::string psSource(buffer,size);
		delete buffer;

		ShaderSP shader = std::make_shared<Shader>(vsSource,psSource);
		
		shaders[name] = shader;
	}
}