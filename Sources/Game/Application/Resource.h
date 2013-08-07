#pragma once

#include <memory>
#include <string>
typedef char* ResourceId;

class Resource
{
private:
	std::string sourceName;
	ResourceId id;
	char* buffer;
	size_t size;
public:
	bool Load(std::string fileName,const ResourceId& name);
	~Resource();
	void Delete();
	char* Buffer() { return buffer; }
	size_t Size() { return size; }
};

typedef std::shared_ptr<Resource> ResourceStrongPtr;