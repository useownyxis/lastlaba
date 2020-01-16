#include "WristWatch.h"
#include "RangeException.h"

WristWatch::WristWatch(std::string newProducer, std::string newName, std::string newMechanism, int newDialSize):
	MechanicalWatch(newProducer, newName, newMechanism)
{
	this->setDialSize(newDialSize);
}

int WristWatch::getDialSize() const
{
	return this->dialSize;
}

void WristWatch::setDialSize(int newDialSize)
{
	this->dialSize = newDialSize;
}

void WristWatch::headOfTable()
{
	MechanicalWatch::headOfTable();
	std::cout << std::setw(25);
	std::cout << "Dial size";
}

std::istream& operator>>(std::istream& in, WristWatch& watch)
{
	in >> dynamic_cast<MechanicalWatch&>(watch);

	std::cout << "Dial size: ";
	int inputInt = RangeException::inputInt(in, 1, 50);
	watch.setDialSize(inputInt);

	return in;
}

std::ostream& operator<<(std::ostream& out, const WristWatch& watch)
{
	out << static_cast<const MechanicalWatch&>(watch);
	out << std::setw(25) << std::left;
	out << watch.dialSize;
	return out;
}

bool WristWatch::sortingDialSize(WristWatch& first, WristWatch& second)
{
	return (first.getDialSize() < second.getDialSize());
}

bool WristWatch::sortingName(WristWatch& first, WristWatch& second)
{
	return (Watch::sortingName(dynamic_cast<Watch&>(first), dynamic_cast<Watch&>(second)));
}

bool WristWatch::sortingProducer(WristWatch& first, WristWatch& second)
{
	return (Watch::sortingProducer(dynamic_cast<Watch&>(first), dynamic_cast<Watch&>(second)));
}

bool WristWatch::sortingMechanismDesign(WristWatch& first, WristWatch& second)
{
	return (MechanicalWatch::sortingMechanismDesign(dynamic_cast<MechanicalWatch&>(first), dynamic_cast<MechanicalWatch&>(second)));
}

bool operator==(const WristWatch& first, const WristWatch& second)
{
	if (static_cast<const MechanicalWatch&>(first) == static_cast<const MechanicalWatch&>(second)) {
		if (first.dialSize == -1 || second.dialSize == -1 || second.dialSize == first.dialSize) {
			return true;
		}
	}
	return false;
}
