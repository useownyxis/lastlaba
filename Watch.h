#pragma once
#include <iostream>
#include <iomanip>

#define MAX_STRING_SIZE 100

class Watch
{
protected:
	char producer[MAX_STRING_SIZE];
	char name[MAX_STRING_SIZE] ;
public:
	Watch(std::string newProducer = "", std::string newName = "");
	virtual ~Watch() = default;
public:
	std::string getName() const;
	std::string getProducer() const;
public:
	void setName(std::string newName);
	void setProducer(std::string newProducer);
public:
	friend std::istream& operator>>(std::istream &in, Watch &watch);
	friend std::ostream& operator<<(std::ostream& out, const Watch &watch);
public:
	static void headOfTable();
public:
	static bool sortingName(Watch& first, Watch& second);
	static bool sortingProducer(Watch& first, Watch& second);
	friend bool operator == (const Watch &first, const Watch &second);
};

