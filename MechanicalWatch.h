#pragma once
#include "Watch.h"
class MechanicalWatch :
	public Watch
{
protected:
	char mechanismDesign[MAX_STRING_SIZE];
public:
	MechanicalWatch(std::string newProducer = "", std::string newName = "", std::string newMechanism = "");
	virtual ~MechanicalWatch() = default;
public:
	std::string getMechanismDesign() const;
public:
	void setMechanismDesign(std::string newMechanism);
public:
	friend std::istream& operator>>(std::istream& in, MechanicalWatch& watch);
	friend std::ostream& operator<<(std::ostream& out, const MechanicalWatch& watch);
public:
	static void headOfTable();
public:
	static bool sortingMechanismDesign(MechanicalWatch& first, MechanicalWatch& second);
	friend bool operator == (const MechanicalWatch& first, const MechanicalWatch &second);
};

