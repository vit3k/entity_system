#include "Resources.h"
#include <string>
#include <fstream>

void Resources::LoadFromFile(const char* fileName,char* buffer,int* size)
{

	std::string path("C:\\Users\\Pawe³\\Documents\\Visual Studio 2012\\Projects\\Game\\Assets\\");
	path+=fileName;
		
	
	std::ifstream file (fileName, std::ios::in|std::ios::binary|std::ios::ate);
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
