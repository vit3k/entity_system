#pragma once
#include <string>
#include <fstream>

namespace Files
{
	bool LoadBinary(std::string fileName,char** buffer,int* size);
}