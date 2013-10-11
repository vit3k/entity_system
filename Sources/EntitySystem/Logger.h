#pragma once
#include <iostream>
#include <string>

class Logger
{
public:
	static void Log(std::string msg)
	{
		//Write(msg);
	}
	static void Info(std::string msg)
	{
		Write(msg);
	}
	static void Write(std::string msg)
	{
		std::cout << msg << std::endl;
	}
	static void Error(std::string msg)
	{
		Write(msg);
	}
};