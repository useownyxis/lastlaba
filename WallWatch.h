#pragma once
#include "MechanicalWatch.h"
class WallWatch :
	public MechanicalWatch
{
private:
	int footprint;
public:
	WallWatch(std::string newProducer = "", std::string newName = "", std::string newMechanism = "", int newFootprint = -1);
	virtual ~WallWatch() = default;
public:
	int getFootprint() const;
public:
	void setFootprint(int newFootprint);
public:
	friend std::istream& operator>>(std::istream& in, WallWatch& watch);
	friend std::ostream& operator<<(std::ostream& out, const WallWatch& watch);
public:
	static void headOfTable();
public:
	static bool sortingFootprint(WallWatch& first, WallWatch& second);
	static bool sortingName(WallWatch& first, WallWatch& second);
	static bool sortingProducer(WallWatch& first, WallWatch& second);
	static bool sortingMechanismDesign(WallWatch& first, WallWatch& second);
	friend bool operator == (const WallWatch& first, const WallWatch &second);
};

