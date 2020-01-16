#include "DigitalWatch.h"
#include "RangeException.h"

DigitalWatch::DigitalWatch(std::string newName, std::string newProducer, int newCapaciry):
	Watch(newName,newProducer)
{
	this->setBatteryCapacity(newCapaciry);
}

int DigitalWatch::getBatteryCapacity() const
{
	return this->batteryCapacity;
}

void DigitalWatch::setBatteryCapacity(int newCapacity)
{
	this->batteryCapacity = newCapacity;
}

void DigitalWatch::headOfTable()
{
	Watch::headOfTable();
	std::cout << std::setw(25);
	std::cout << "Battery capacity";
}

std::istream& operator>>(std::istream& in, DigitalWatch& watch)
{
	in >> dynamic_cast<Watch&>(watch);

	std::cout << "Battery capacity: ";
	int inputInt = RangeException::inputInt(in, 1, 10000);
	watch.setBatteryCapacity(inputInt);

	return in;
}

std::ostream& operator<<(std::ostream& out, const DigitalWatch& watch)
{
	out << static_cast<const Watch&> (watch);
	out << std::setw(20);
	out << watch.batteryCapacity;
	return out;
}

bool DigitalWatch::sortingBatteryCapacity(DigitalWatch& first, DigitalWatch& second)
{
	return (first.getBatteryCapacity() < second.getBatteryCapacity());
}

bool operator==(const DigitalWatch& first, const DigitalWatch& second)
{
	if (static_cast<const Watch&>(first) == static_cast<const Watch&>(second)) {
		if (first.batteryCapacity == -1 || second.batteryCapacity == -1 || second.batteryCapacity == first.batteryCapacity) {
			return true;
		}
	}
	return false;
}
