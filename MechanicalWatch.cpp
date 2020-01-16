#include "MechanicalWatch.h"
#include"NameException.h"

MechanicalWatch::MechanicalWatch(std::string newProducer, std::string newName, std::string newMechanism):
	Watch(newProducer, newName)
{
	this->setMechanismDesign(newMechanism);
}

std::string MechanicalWatch::getMechanismDesign() const
{
	return this->mechanismDesign;
}

void MechanicalWatch::setMechanismDesign(std::string newMechanism)
{
	memset(this->mechanismDesign, 0, MAX_STRING_SIZE);
	strcpy_s(this->mechanismDesign, newMechanism.size() + 1, newMechanism.c_str());
}

void MechanicalWatch::headOfTable()
{
	Watch::headOfTable();
	std::cout << std::setw(25);
	std::cout << "Mechanism";
}

std::istream& operator>>(std::istream& in, MechanicalWatch& watch)
{
	in >> dynamic_cast<Watch&>(watch);
	
	std::cout << "Mechanism design: ";
	std::string inputString = NameException::inputString(in);
	watch.setMechanismDesign(inputString);

	return in;
}

std::ostream& operator<<(std::ostream& out, const MechanicalWatch& watch)
{
	out << static_cast<const Watch&>(watch);
	out << std::setw(25) << std::left;
	out << watch.mechanismDesign;
	return out;
}

bool MechanicalWatch::sortingMechanismDesign(MechanicalWatch& first, MechanicalWatch& second)
{
	return (first.getMechanismDesign().compare(second.getMechanismDesign()) < 0);
}

bool operator==(const MechanicalWatch& first, const MechanicalWatch& second)
{
	if (static_cast<const Watch&>(first) == static_cast<const Watch&>(second)) {
		if (first.getMechanismDesign() == "" || second.getMechanismDesign() == "" || second.getMechanismDesign() == first.getMechanismDesign()) {
			return true;
		}
	}
	return false;
}
