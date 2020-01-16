#pragma once
#include "Watch.h"
class DigitalWatch :
	public Watch
{
protected:
	int batteryCapacity;
public:
	DigitalWatch(std::string newName = "", std::string newProducer = "", int newCapaciry = -1);
	virtual ~DigitalWatch() = default;
public:
	int getBatteryCapacity() const;
public:
	void setBatteryCapacity(int newCapacity);
public:
	friend std::istream& operator>>(std::istream& in, DigitalWatch &watch);
	friend std::ostream& operator<<(std::ostream& out, const DigitalWatch& watch);
public:
	static void headOfTable();
public:
	static bool sortingBatteryCapacity(DigitalWatch& first, DigitalWatch& second);
	friend bool operator == (const DigitalWatch &first, const DigitalWatch &second);
};

