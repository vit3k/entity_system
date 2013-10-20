#pragma once
#include <string>
#include <glm.hpp>
#include <memory>

namespace Graphics
{
	class Shader
	{
	private:
		int shaderId;
	public:
		Shader();
		Shader(std::string vsSource,std::string psSource);
		void SetVertexShader(std::string source);
		void SetPixelShader(std::string source);
		void Link();
		void Use();
		void SetMatrix4(std::string name, glm::mat4 matrix);
	};

	typedef std::shared_ptr<Shader> ShaderSP;
}