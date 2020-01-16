#include "RangeException.h"
#include <iostream>
#include <string>

RangeException::RangeException(int newErrorIndex, int newMinIndex, int newMaxIndex)
{
	this->errorIndex = newErrorIndex;
	this->maxIndex = newMaxIndex;
	this->minIndex = newMinIndex;
}

void RangeException::what()
{
	std::cerr << "Error. Invalid range of value." << "Minimum possible value: " << this->minIndex << ".Maximum possible value: " << this->maxIndex << ".Using value: " << this->errorIndex << std::endl;
}

int RangeException::inputInt(std::istream& in, int min, int max)
{
	int input;
	while (true) {
		in.clear();
		try {
			in >> input;
			if (RangeException::checkInt(input,min,max))
				throw RangeException(input, min, max);
			break;
		}
		catch (RangeException exception) {
			exception.what();
			rewind(stdin);
		}
	}
	return input;
}

bool RangeException::checkInt(int checkInt, int min, int max)
{
	if (checkInt == -1) {
		return true;
	}
	if (checkInt < min || checkInt > max) {
		return true;
	}
	return false;
}


