#pragma once
#include "Component.h"

class VelocityComponent : public Component
{
public:
	static const int ID;
	int GetID() { return ID;}
	float vX,vY;
	VelocityComponent(float vX,float vY):vX(vX),vY(vY) {}
};

typedef std::shared_ptr<VelocityComponent> VelocityComponentSP;