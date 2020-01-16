#pragma once
#include "DigitalWatch.h"
class SmartWatch :
	public DigitalWatch
{
private:
	int displaySize;
public:
	SmartWatch(std::string newProducer = "", std::string newName = "", int newCapacity = -1, int newDisplaySize = -1);
	virtual ~SmartWatch() = default;
public:
	int getDisplaySize() const;
public:
	void setDisplaySize(int newDisplaySize);
public:
	friend std::istream& operator>>(std::istream& in, SmartWatch& watch);
	friend std::ostream& operator<<(std::ostream& out, const SmartWatch& watch);
public:
	static void headOfTable();
public:
	static bool sortingDisplaySize(SmartWatch& first, SmartWatch& second);
	static bool sortingName(SmartWatch& first, SmartWatch& second);
	static bool sortingProducer(SmartWatch& first, SmartWatch& second);
	static bool sortingBatteryCapacity(SmartWatch& first, SmartWatch& second);
	friend bool operator == (const SmartWatch& first, const SmartWatch &second);
};

