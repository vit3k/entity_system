#pragma once
#include <string>
#include <glm.hpp>

class Shader
{
private:
	int shaderId;
public:
	Shader(std::string vertex, std::string pixel);
	void Use();
	void SetMatrix4(std::string name, glm::mat4 matrix);
};