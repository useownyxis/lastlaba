#include <iostream>
#include <string>
#include <Windows.h>

#include "NameException.h"

NameException::NameException()
{
	this->errorString = "Unknown string";
}

NameException::NameException(std::string newErrorString)
{
	this->errorString = newErrorString;
}

void NameException::what()
{
	std::cerr << "Exception: " << "Error. Can't use string with several languages or numbers." << this->errorString << std::endl;
}

bool NameException::checkString(std::string checkStr)
{
	bool RussianSymbols = false;
	bool EnglishSymbols = false;
	for (int i = 0; i < checkStr.size(); i++) {
		if ((checkStr[i] >= 'a' && checkStr[i] <= 'z') || (checkStr[i] >= 'A' && checkStr[i] <= 'Z'))
			EnglishSymbols = true;
		else
			if ((checkStr[i] >= 'à' && checkStr[i] <= 'ÿ') || (checkStr[i] >= 'À' && checkStr[i] <= 'ß'))
				RussianSymbols = true;
			else
				if (checkStr[i] != ' ')
					return true;

	}
	if (RussianSymbols && EnglishSymbols) {
		return true;
	}
	return false;
}

std::string NameException::inputString(std::istream &in)
{
	std::string input;
	while (true) {
		in.clear();
		try {
			in >> input;
			if (NameException::checkString(input))
				throw NameException(input);
			break;
		}
		catch (NameException exception) {
			rewind(stdin);
			exception.what();
		}
	}
	return input;
}
