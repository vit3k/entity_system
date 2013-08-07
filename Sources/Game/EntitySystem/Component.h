#pragma once

#include <memory>

typedef int ComponentId;

class Component
{
public:
	static const ComponentId ID;
	virtual ~Component() {};
};

typedef std::shared_ptr<Component> ComponentStrongPtr;


