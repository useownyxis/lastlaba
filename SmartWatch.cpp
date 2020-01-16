#include "SmartWatch.h"
#include "RangeException.h"

SmartWatch::SmartWatch(std::string newProducer, std::string newName, int newCapacity, int newDisplaySize):
	DigitalWatch(newProducer, newName, newCapacity)
{
	this->setDisplaySize(newDisplaySize);
}

int SmartWatch::getDisplaySize() const
{
	return this->displaySize;
}

void SmartWatch::setDisplaySize(int newDisplaySize)
{
	this->displaySize = newDisplaySize;
}

void SmartWatch::headOfTable()
{
	DigitalWatch::headOfTable();
	std::cout << std::setw(25);
	std::cout << "Display Size";
}

std::istream& operator>>(std::istream& in, SmartWatch& watch)
{
	in >> dynamic_cast<DigitalWatch&>(watch);

	std::cout << "Display size: ";
	int inputInt = RangeException::inputInt(in, 1, 50);
	watch.setDisplaySize(inputInt);

	return in;
}

std::ostream& operator<<(std::ostream& out, const SmartWatch& watch)
{
	out << static_cast<const DigitalWatch&>(watch);
	out << std::setw(25);
	out << watch.displaySize;
	return out;
}

bool SmartWatch::sortingDisplaySize(SmartWatch& first, SmartWatch& second)
{
	return (first.getDisplaySize() < second.getDisplaySize());
}

bool SmartWatch::sortingName(SmartWatch& first, SmartWatch& second)
{
	return (Watch::sortingName(dynamic_cast<Watch&>(first), dynamic_cast<Watch&>(second)));
}

bool SmartWatch::sortingProducer(SmartWatch& first, SmartWatch& second)
{
	return (Watch::sortingProducer(dynamic_cast<Watch&>(first), dynamic_cast<Watch&>(second)));
}

bool SmartWatch::sortingBatteryCapacity(SmartWatch& first, SmartWatch& second)
{
	return (DigitalWatch::sortingBatteryCapacity(dynamic_cast<DigitalWatch&>(first), dynamic_cast<DigitalWatch&>(second)));
}

bool operator==(const SmartWatch& first, const SmartWatch& second)
{
	if (static_cast<const DigitalWatch&>(first) == static_cast<const DigitalWatch&>(second)) {
		if (first.displaySize == -1 || second.displaySize == -1 || second.displaySize == first.displaySize) {
			return true;
		}
	}
	return false;
}
