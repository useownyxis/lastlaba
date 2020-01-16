#pragma once
#include "DigitalWatch.h"
class BinaryWatch :
	public DigitalWatch
{
private:
	int numberOfLuminodiodes;
public:
	BinaryWatch(std::string newProducer = "", std::string newName = "", int newCapacity = -1, int newNumberOfLuminodiodes = -1);
	virtual ~BinaryWatch() = default;
public:
	int getNumberOfLuminodiodes() const;
public:
	void setNumberOfLuminodiodes(int newNumberOfLuminodiodes);
public:
	friend std::istream& operator>>(std::istream& in, BinaryWatch& watch);
	friend std::ostream& operator<<(std::ostream& out, const BinaryWatch& watch);
public:
	static void headOfTable();
public:
	static bool sortingNumberOfLumiodiodes(BinaryWatch& first, BinaryWatch& second);
	static bool sortingName(BinaryWatch& first, BinaryWatch& second);
	static bool sortingProducer(BinaryWatch& first, BinaryWatch& second);
	static bool sortingBatteryCapacity(BinaryWatch& first, BinaryWatch& second);
	friend bool operator == (const BinaryWatch& first, const BinaryWatch& second);
};

