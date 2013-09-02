#pragma once
#include "Component.h"
#include "../../Math/Point2.h"

class TransformComponent : public Component
{
public:
	static const int ID;
	int GetID() { return ID;}
	float x,y,rotation;
	Math::Point2f position;
	TransformComponent(float x,float y):x(x),y(y),position(x,y)
	{
	}
};

typedef std::shared_ptr<TransformComponent> TransformComponentSP;