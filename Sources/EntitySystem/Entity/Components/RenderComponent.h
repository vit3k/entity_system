#pragma once
#include "Component.h"
#include <string>

class RenderComponent : public Component
{
private:
	std::string spriteName;	
public:
	static const int ID;
	int GetID() { return ID;}
	std::string GetSpriteName() { return spriteName; }	
	RenderComponent(const std::string spriteName):spriteName(spriteName)
	{
	};
};

typedef std::shared_ptr<RenderComponent> RenderComponentSP;