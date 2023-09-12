#pragma once
#include <iostream>

//template<typename type>
struct Slot
{
	char data = ' ';
	bool taken = false;
	Slot() {};
	Slot(char x): data(x) {};
	void Set(char x) {
		data = x;
		taken = true;
	}
	void Free()
	{
		data = ' ';
		taken = false;
	}
	friend std::ostream& operator<<(std::ostream& stream, const Slot& Slot)
	{
		stream << Slot.data;
		return stream;
	}
};

