#pragma once
#include "Component.h"
#include <memory>

class TransformComponent :
	public Component
{
private:
	float x;
	float y;
	float rotation;
	
public:
	float X() { return x; }
	void X(float x) { this->x = x; }
	float Y() { return y; }
	void Y(float y) { this->y = y; }
	static const ComponentId ID;
};



typedef std::shared_ptr<TransformComponent> TransformComponentStrongPtr;