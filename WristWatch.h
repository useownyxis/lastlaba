#pragma once
#include "MechanicalWatch.h"
class WristWatch :
	public MechanicalWatch
{
private:
	int dialSize;
public:
	WristWatch(std::string newProducer = "", std::string newName = "", std::string newMechanism = "", int newDialSize = -1);
	virtual ~WristWatch() = default;
public:
	int getDialSize() const;
public:
	void setDialSize(int newDialSize);
public:
	friend std::istream& operator>>(std::istream& in, WristWatch& watch);
	friend std::ostream& operator<<(std::ostream& out, const WristWatch& watch);
public:
	static void headOfTable();
public:
	static bool sortingDialSize(WristWatch& first, WristWatch& second);
	static bool sortingName(WristWatch& first, WristWatch& second);
	static bool sortingProducer(WristWatch& first, WristWatch& second);
	static bool sortingMechanismDesign(WristWatch& first, WristWatch& second);
	friend bool operator == (const WristWatch &first, const WristWatch &second);
};

