#include "Resources.h"
#include <string>

bool Resources::Load(const ResourceId& name,const char* fileName)
{
	if(resources[name]!=NULL)
		return false;

	ResourceStrongPtr resource(new Resource());
	std::string path("C:\\Users\\Pawe³\\Documents\\Visual Studio 2012\\Projects\\Game\\Assets\\");
	path+=fileName;
	
	bool res = resource->Load(path,name);
	if(!res)
		return false;
	
	resources[name] = resource;
	return true;

}

ResourceStrongPtr Resources::Get(const ResourceId& id)
{
	return resources[id];
}