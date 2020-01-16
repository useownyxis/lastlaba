#pragma once

class NameException :
	public std::exception
{
public:
	NameException();
	explicit NameException(std::string newErrorString);
	virtual ~NameException() = default;
	void what();
	static bool checkString(std::string checkStr);
	static std::string inputString(std::istream &in);
protected:
	std::string errorString;
};

