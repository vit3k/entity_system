#pragma once

template <class T> class Sequencer
{
private:
	T current;
	void Inc() 
	{
		current++;
	}
public:
	Sequencer(T initial) 
	{
		current = initial;
	};
	T Next() 
	{
		T ret = current;
		Inc();
		return ret;
	};
};

