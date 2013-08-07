#pragma once
#include <vector>
#include "../Events/Event.h"
#include <string>

class Console 
{
private:
	std::vector<std::string> lines;
public:
	void Init();
	void OnEvent(EventStrongPtr e);
	std::vector<std::string> Lines() { return lines; }
};