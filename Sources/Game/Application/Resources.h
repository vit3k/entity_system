#pragma once

#include "Resource.h"
#include <map>

typedef std::map<ResourceId,ResourceStrongPtr> ResourcesList;

class Resources
{
	ResourcesList resources;
public:
	bool Load(const ResourceId& name,const char* fileName);
	ResourceStrongPtr Get(const ResourceId& id);
};

