#include "WallWatch.h"
#include "RangeException.h"

WallWatch::WallWatch(std::string newProducer, std::string newName, std::string newMechanism, int newFootprint):
	MechanicalWatch(newProducer, newName, newMechanism)
{
	this->setFootprint(newFootprint);
}

int WallWatch::getFootprint() const
{
	return this->footprint;
}

void WallWatch::setFootprint(int newFootprint)
{
	this->footprint = newFootprint;
}

void WallWatch::headOfTable()
{
	MechanicalWatch::headOfTable();
	std::cout << std::setw(25);
	std::cout << "Footprint";
}

std::istream& operator>>(std::istream& in, WallWatch& watch)
{
	in >> dynamic_cast<MechanicalWatch&>(watch);

	std::cout << "Footprint: ";
	int inputInt = RangeException::inputInt(in, 1, 50);
	watch.setFootprint(inputInt);

	return in;
}

std::ostream& operator<<(std::ostream& out, const WallWatch& watch)
{
	out << static_cast<const MechanicalWatch&>(watch);
	out << std::setw(25) << std::left;
	out << watch.footprint;
	return out;
}

bool WallWatch::sortingFootprint(WallWatch& first, WallWatch& second)
{
	return (first.getFootprint() < second.getFootprint());
}

bool WallWatch::sortingName(WallWatch& first, WallWatch& second)
{
	return (Watch::sortingName(dynamic_cast<Watch&>(first), dynamic_cast<Watch&>(second)));
}

bool WallWatch::sortingProducer(WallWatch& first, WallWatch& second)
{
	return (Watch::sortingProducer(dynamic_cast<Watch&>(first), dynamic_cast<Watch&>(second)));
}

bool WallWatch::sortingMechanismDesign(WallWatch& first, WallWatch& second)
{
	return (MechanicalWatch::sortingMechanismDesign(dynamic_cast<MechanicalWatch&>(first), dynamic_cast<MechanicalWatch&>(second)));
}

bool operator==(const WallWatch& first, const WallWatch& second)
{
	if (static_cast<const MechanicalWatch&>(first) == static_cast<const MechanicalWatch&>(second)) {
		if (first.footprint == -1 || second.footprint == -1 || second.footprint == first.footprint) {
			return true;
		}
	}
	return false;
}
