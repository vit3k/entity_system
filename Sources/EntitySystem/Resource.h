#pragma once
#include <memory>

class ResourceBase
{
};
typedef std::shared_ptr<ResourceBase> ResourceBaseSP;

template <class T>
class Resource : public ResourceBase
{
protected:
	T object;
public:
	T Get() { return object; }
};
