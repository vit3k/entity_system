#include "Engine.h"

int main()
{
	Engine::Instance().Init();
	Engine::Instance().Run();
	return 0;
}