#pragma once
#include <memory>

class Component
{
public:
	static const int ID;
	virtual	int GetID() { return ID;}
};

typedef std::shared_ptr<Component> ComponentSP;