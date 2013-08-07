#pragma once
#include <bitset>

class ComponentsBits : public std::bitset<10>
{
public:
	ComponentsBits(int num,...);
	ComponentsBits(int num,va_list arguments);
	ComponentsBits() {};

	void Init(int num,va_list arguments);
	void AddComponent(int id);
};