#pragma once

#include "Resource.h"
#include <map>
#include <memory>
#include <string>

typedef std::string ResourceId;

typedef std::map<ResourceId,ResourceBaseSP> ResourcesList;

class Resources
{
	ResourcesList resources;
public:
	template <typename R>
	std::shared_ptr<R> Load(const ResourceId& name,const char* fileName)
	{
		char* buffer = nullptr;
		int size;
		LoadFromFile(fileName,&buffer,&size);
		std::shared_ptr<R> r = std::make_shared<R>(buffer,size);
		resources[name] = r;
		return r;
	}
	void LoadFromFile(const std::string fileName,char** buffer,int* size);
	template <typename R>
	std::shared_ptr<R> Get(const ResourceId& id)
	{
		return std::dynamic_pointer_cast<R>(resources[id]);
	}
};

