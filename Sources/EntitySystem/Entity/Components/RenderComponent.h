#pragma once
#include "Component.h"
#include <string>

class RenderComponent : public Component
{
private:

public:
	static const int ID;
	int GetID() { return ID;}
	
};

typedef std::shared_ptr<RenderComponent> RenderComponentSP;