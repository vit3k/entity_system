#pragma once
#include "Control.h"
class RenderControl :
	public Control
{
public:
	void Render(Time delta,sf::RenderTarget* target);
};

typedef std::shared_ptr<RenderControl> RenderControlStrongPtr;
