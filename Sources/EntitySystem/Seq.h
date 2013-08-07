#pragma once

template <typename T>
class Seq 
{
	T next;
	T current;
public:
	Seq()
	{
		next = 0;
		current = next;
	}
	T Next()
	{
		current = next;
		next++;
		return current;
	}
	T Current()
	{
		return current;
	}
};