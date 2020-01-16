#include "BinaryWatch.h"
#include "DigitalWatch.h"
#include "RangeException.h"

BinaryWatch::BinaryWatch(std::string newProducer, std::string newName, int newCapacity, int newNumberOfLuminodiodes):
	DigitalWatch(newProducer,newName, newCapacity)
{
	this->setNumberOfLuminodiodes(newNumberOfLuminodiodes);
}

int BinaryWatch::getNumberOfLuminodiodes() const
{
	return this->numberOfLuminodiodes;
}

void BinaryWatch::setNumberOfLuminodiodes(int newNumberOfLuminodiodes)
{
	this->numberOfLuminodiodes = newNumberOfLuminodiodes;
}

void BinaryWatch::headOfTable()
{
	DigitalWatch::headOfTable();
	std::cout << std::setw(25);
	std::cout << "Number of luminodiodes";
}

std::istream& operator>>(std::istream& in, BinaryWatch& watch)
{
	in >> dynamic_cast<DigitalWatch&>(watch);

	std::cout << "Number of lumibodiodes: ";
	int inputInt = RangeException::inputInt(in, 1, 50);
	watch.setNumberOfLuminodiodes(inputInt);

	return in;
}

std::ostream& operator<<(std::ostream& out, const BinaryWatch& watch)
{
	out << static_cast<const DigitalWatch&>(watch);
	out << std::setw(25) << std::left;
	out << watch.numberOfLuminodiodes;
	return out;
}

bool BinaryWatch::sortingNumberOfLumiodiodes(BinaryWatch& first, BinaryWatch& second)
{
	return (first.getNumberOfLuminodiodes() < second.getNumberOfLuminodiodes());
}

bool BinaryWatch::sortingName(BinaryWatch& first, BinaryWatch& second)
{
	return (Watch::sortingName(dynamic_cast<Watch&>(first), dynamic_cast<Watch&>(second)));
}

bool BinaryWatch::sortingProducer(BinaryWatch& first, BinaryWatch& second)
{
	return (Watch::sortingProducer(dynamic_cast<Watch&>(first), dynamic_cast<Watch&>(second)));
}

bool BinaryWatch::sortingBatteryCapacity(BinaryWatch& first, BinaryWatch& second)
{
	return (DigitalWatch::sortingBatteryCapacity(dynamic_cast<DigitalWatch&>(first), dynamic_cast<DigitalWatch&>(second)));
}

bool operator==(const BinaryWatch& first, const BinaryWatch& second)
{
	if (static_cast<const DigitalWatch&>(first) == static_cast<const DigitalWatch&>(second)) {
		if (first.numberOfLuminodiodes == -1 || second.numberOfLuminodiodes == -1 || second.numberOfLuminodiodes == first.numberOfLuminodiodes) {
			return true;
		}
	}
	return false;
}
