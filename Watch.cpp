#include "Watch.h"
#include <string>
#include "NameException.h"

Watch::Watch(std::string newProducer, std::string newName)
{
	this->setName(newName);
	this->setProducer(newProducer);
}

std::string Watch::getName() const
{
	return this->name;
}

std::string Watch::getProducer() const
{
	return this->producer;
}

void Watch::setName(std::string newName)
{
	memset(this->name, 0, MAX_STRING_SIZE);
	strcpy_s(this->name, newName.size() + 1, newName.c_str());
}

void Watch::setProducer(std::string newProducer)
{
	memset(this->producer, 0, MAX_STRING_SIZE);
	strcpy_s(this->producer, newProducer.size() + 1, newProducer.c_str());
}

void Watch::headOfTable()
{
	std::cout << "Producer";
	std::cout << std::setw(25);
	std::cout << "Name";
}


std::istream& operator>>(std::istream& in, Watch& watch)
{
	std::cout << "Producer: ";
	std::string inputString = NameException::inputString(in);
	watch.setProducer(inputString);
	
	std::cout << "Name: ";
	inputString = NameException::inputString(in);
	watch.setName(inputString);

	return in;
}

std::ostream& operator<<(std::ostream& out, const Watch& watch)
{
	out << watch.producer;
	out << std::setw(35 - watch.getProducer().size()) ;
	out << watch.name;
	return out;
}

bool Watch::sortingName(Watch& first, Watch& second)
{
	return (first.getName().compare(second.getName()) < 0);
}

bool Watch::sortingProducer(Watch& first, Watch& second)
{
	return (first.getProducer().compare(second.getProducer()) < 0);
}

bool operator==(const Watch& first, const Watch& second)
{
	if (first.getName() == "" || second.getName() == "" || first.getName() == second.getName()) {
		if (first.getProducer() == "" || second.getProducer() == "" || first.getProducer() == second.getProducer()) {
			return true;
		}
	}
	return false;
}
