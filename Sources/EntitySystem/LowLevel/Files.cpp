#include "Files.h"

namespace Files
{
	bool LoadBinary(std::string fileName,char** buffer,int* size)
	{
		std::string path("d:\\Projekty\\entity_system\\Assets\\");
		path+=fileName;
		
	
		std::ifstream file (path, std::ios::in|std::ios::binary|std::ios::ate);
		if(file.is_open())
		{
			size_t s = file.tellg();
			file.seekg (0, std::ios::beg);
			char* tempbuffer = new char[s];
			*buffer = new char[s];
			file.read (tempbuffer, s);
			file.close();
			*size = s;
			memcpy(*buffer,tempbuffer,s);
		}
		return true;
	}
}