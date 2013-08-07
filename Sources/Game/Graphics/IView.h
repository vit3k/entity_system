#pragma once

#include "../Application/Clock.h"

class IView
{
public:
	virtual void Render(Time delta) {};
	virtual void Init() {};
};

typedef std::shared_ptr<IView> IViewStrongPtr;
