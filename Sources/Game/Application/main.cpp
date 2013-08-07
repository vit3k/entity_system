#include "Application.h"

int main()
{
	Application& app = Application::Instance();
	app.Init();
	app.Loop();
	
    return 0;
}