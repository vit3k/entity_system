#include "Shader.h"
#include "..\Resources\ShaderResource.h"
#include "..\Engine.h"
#include "GL\glew.h"
#include "..\Logger.h"
#include <gtc/type_ptr.hpp>

Shader::Shader(std::string vertex, std::string pixel)
{
	auto vertex_shader = Engine::Instance().GetResources()->Get<ShaderResource>(vertex)->Get()->c_str();
	auto fragment_shader = Engine::Instance().GetResources()->Get<ShaderResource>(pixel)->Get()->c_str();
	
	unsigned int vs = glCreateShader (GL_VERTEX_SHADER);
	glShaderSource (vs, 1, &vertex_shader, NULL);
	glCompileShader (vs);

	unsigned int fs = glCreateShader (GL_FRAGMENT_SHADER);
	glShaderSource (fs, 1, &fragment_shader, NULL);
	glCompileShader (fs);

	shaderId = glCreateProgram ();
	glAttachShader (shaderId, fs);
	glAttachShader (shaderId, vs);
	glLinkProgram (shaderId);

	int params = -1;
	glGetProgramiv (shaderId, GL_LINK_STATUS, &params);
	if (GL_TRUE != params) {
		Logger::Error( "ERROR: could not link shader programme GL index " +shaderId );
		int max_length = 2048;
		int actual_length = 0;
		char log[2048];
		glGetShaderInfoLog (shaderId, max_length, &actual_length, log);
		Logger::Error(log); 
	}
}

void Shader::SetMatrix4(std::string name, glm::mat4 matrix)
{
	int matrix_location = glGetUniformLocation (shaderId, name.c_str());
	glUseProgram (shaderId);
	glUniformMatrix4fv (matrix_location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::Use()
{
	glUseProgram (shaderId);
}