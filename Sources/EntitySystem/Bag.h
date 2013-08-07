#pragma once

template<class T>
class Bag
{
private:
	std::shared_ptr<T> data[];
	int firstEmpty;
	
	void FindNextEmpty()
	{
		for(int i = prev;i < size; i++)
		{
			if(!data[i]) {
				firstEmpty = i;
				break;
			}
		}
	}
	/*void Grow()
	{
	}*/
public:
	Bag()
	{
		Bag(64);
	}
	Bag(int size)
	{
		data = new T[size];
		firstEmpty = 0;
	}
	~Bag()
	{
		delete data;
	}

	T Add(std::sharedT t)
	{
		t.ID = firstEmpty;
		data[firstEmpty] = t;
		FindNextEmpty();
		return t;
	}
	T Set(T t)
	{
		data[t.ID] = t;
	}
};