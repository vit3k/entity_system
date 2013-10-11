#include "Engine.h"

int main()
{
	Engine::Instance().Init();
	Engine::Instance().Run();
	Engine::Instance().Deinit();
	return 0;
}