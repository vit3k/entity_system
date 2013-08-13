#pragma once
#include <memory>

class ResourceBase
{
public:
	virtual ~ResourceBase() {};
};
typedef std::shared_ptr<ResourceBase> ResourceBaseSP;

template <class T>
class Resource : public ResourceBase
{
protected:
	std::shared_ptr<T> object;
public:
	std::shared_ptr<T> Get() { return object; }
	Resource()
	{
		object = std::make_shared<T>();
	}
};
