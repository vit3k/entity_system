#pragma once

#include "LuaPlus.h"

/*	Manages lua state object */
class LuaManager
{
private:
	LuaPlus::LuaState* luaState;
public:
	LuaManager(void);
	~LuaManager(void);
	void ExecuteFile(char* fileName);
};

