#include "Resources.h"
#include <string>
#include <fstream>

void Resources::LoadFromFile(const char* fileName,char* buffer,int* size)
{

	std::string path("d:\\Projekty\\entity_system\\Assets\\");
	path+=fileName;
		
	
	std::ifstream file (path, std::ios::in|std::ios::binary|std::ios::ate);
	if(file.is_open())
	{
		size_t s = file.tellg();
		file.seekg (0, std::ios::beg);
		buffer = new char[s];
		file.read (buffer, s);
		file.close();
		*size = s;
	}
}
