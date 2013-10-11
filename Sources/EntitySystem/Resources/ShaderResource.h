#pragma once
#include "Resource.h"
#include <string>

class ShaderResource : public Resource<std::string>
{
public:
	ShaderResource(char* buffer,int size):Resource()
	{
		object->assign(buffer, size);
	}
	char* GetAsCharArray()
	{

	}
};

typedef std::shared_ptr<ShaderResource> ShaderResourceSP;