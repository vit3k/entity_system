#pragma once
#include <iostream>
#include <string>

class Logger
{
public:
	static void Log(std::string msg)
	{
		std::cout << msg << std::endl;
	}
};