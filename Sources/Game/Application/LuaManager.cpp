#include "LuaManager.h"


LuaManager::LuaManager(void)
{
	luaState = LuaPlus::LuaState::Create();
}


LuaManager::~LuaManager(void)
{
	LuaPlus::LuaState::Destroy(luaState);
	luaState = NULL;
}

void LuaManager::ExecuteFile(char* fileName)
{
	luaState->DoFile(fileName);
}
