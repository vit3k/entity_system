#pragma once
#include "Component.h"


class TransformComponent : public Component
{
public:
	static const int ID;
	int GetID() { return ID;}
	float x,y,rotation;
	float originX,originY;
	
	TransformComponent(float x,float y,float rotation):x(x),y(y),rotation(rotation),originX(0),originY(0)
	{
	}
};

typedef std::shared_ptr<TransformComponent> TransformComponentSP;