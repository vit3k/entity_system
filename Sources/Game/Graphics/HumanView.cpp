#include "HumanView.h"
#include "../UI/RenderControl.h"
#include "../Application/Application.h"
#include "../UI/ConsoleControl.h"

HumanView::HumanView(void)
{
}


HumanView::~HumanView(void)
{
}

void HumanView::Render(Time delta) 
{
	// screens render comes here
	// fps cap to 60 does we need more???
	if(delta < 1/60 * 1000 * 1000)
		return;
	
	window->clear();
	
	/* render all screen elements attached to view */
	ControlList::iterator controlIt;
	for (controlIt = controls.begin(); controlIt != controls.end(); controlIt++)
	{
		ControlStrongPtr control = (*controlIt);
		if(control->Visible()) 
		{
			sf::RenderTexture dest;
			dest.create(control->Width(),control->Height());
			control->Render(delta,&dest);
			dest.display();
			sf::Sprite spr(dest.getTexture());
			spr.setPosition(control->X(),control->Y());
			window->draw(spr);
		}
	}

	window->display();
}

void HumanView::Init(void) 
{
	window = Application::Instance().Window();
	RenderControlStrongPtr render(new RenderControl());
	AddControl(render);
	ConsoleControlStrongPtr console(new ConsoleControl());
	console->Height(100);
	console->Y(500);
	AddControl(console);
	ControlList::iterator controlIt;
	for (controlIt = controls.begin(); controlIt != controls.end(); controlIt++)
	{
		ControlStrongPtr control = (*controlIt);
		control->Init();
	}
}

bool HumanView::AddControl(ControlStrongPtr control)
{
	controls.push_back(control);
	return true;
}