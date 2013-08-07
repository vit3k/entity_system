#pragma once
#include "Component.h"

class RenderComponent : public Component
{
private:
	
public:
	static const int ID;
	int GetID() { return ID;}
	
	RenderComponent(){};
};

typedef std::shared_ptr<RenderComponent> RenderComponentSP;