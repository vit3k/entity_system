#pragma once
#include "Component.h"

class TransformComponent : public Component
{
public:
	static const int ID;
	int GetID() { return ID;}
	float x,y;
	TransformComponent(float x,float y):x(x),y(y) {}
};

typedef std::shared_ptr<TransformComponent> TransformComponentSP;