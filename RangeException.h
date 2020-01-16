#pragma once
#include <iostream>

class RangeException:
	public std::exception
{
public:
	RangeException(int newErrorIndex = 0, int newMinIndex = 0, int newMaxIndex = 0);
	void what();
	virtual ~RangeException() = default;
	static int inputInt(std::istream &in, int min, int max);
	static bool checkInt(int checkInt, int min, int max);
protected:
	int minIndex;
	int maxIndex;
	int errorIndex;
	
};

