#include "Resource.h"
#include <fstream>

using namespace std;

bool Resource::Load(std::string fileName,const ResourceId& name)
{
	sourceName = fileName;
	this->id = name;
	buffer = NULL;
	ifstream file (fileName, ios::in|ios::binary|ios::ate);
	if (file.is_open())
	{
		this->size = file.tellg();
		file.seekg (0, ios::beg);
		buffer = new char[this->size];
		file.read (buffer, this->size);
		file.close();
	 }
	else
		return false;
	return true;
}

Resource::~Resource()
{
	Delete();
}

void Resource::Delete()
{
	if(buffer != NULL)
		delete buffer;
}

