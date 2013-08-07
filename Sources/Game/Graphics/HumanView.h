#pragma once

#include "../UI/Control.h"
#include "IView.h"

#include <list>

typedef std::list<ControlStrongPtr> ControlList;
class HumanView :
	public IView
{
private:
	ControlList controls;
	sf::RenderWindow* window;
public:
	HumanView(void);
	~HumanView(void);
	void Render(Time delta) override;
	void Init() override;
	bool AddControl(ControlStrongPtr control);
};

typedef std::shared_ptr<HumanView> HumanViewStrongPtr;