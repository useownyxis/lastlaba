#pragma once

#include <iostream>
#include <fstream>
#include "SmartWatch.h"
#include "WallWatch.h"
#include "WristWatch.h"
#include "BinaryWatch.h"
#include "Deque.h"
#include "RangeException.h"

class File
{
private:
	std::fstream fileStream;
	bool isOpen;
public:
	File(const char* fileName = "");
	~File();

	template <class type>
	void write_text(Deque<type>& deque);

	template<class type>
	void read_text(Deque<type>& deque);

	template <class type>
	void write_binary(Deque<type>& deque);

	template<class type>
	void read_binary(Deque<type>& deque);

	template<class type>
	void read_index_binary(Deque<type>& deque);

	template<class type>
	void swap_first_last(Deque<type>& deque, const char* fileName);

	void openBinaryFileRead(const char* fileName);
	void openBinaryFileWrite(const char* fileName);

	void openTextFileRead(const char* filename);
	void openTextFileWrite(const char* filename);


};

template<class type>
inline void File::write_text(Deque<type>& deque)
{
	if (this->isOpen == false) {
		throw std::exception("File is not openning");
	}
	typename Deque<type>::iterator it;
	int i = 0;
	for (it = deque.it_begin(); it != deque.it_end(); it++) {
		type test = (*it);
		if (++i == deque.size()) {
			this->fileStream << test;
		}
		else
			this->fileStream << test << std::endl;
	}
}

template<class type>
inline void File::read_text(Deque<type>& deque)
{
	if (this->isOpen == false) {
		throw std::exception("File is not openning");
	}
	while (!this->fileStream.eof()) {
		type T;
		this->fileStream >> T;
		deque.pushTop(T);
		//this->fileStream.peek();
	}
}

template<class type>
inline void File::write_binary(Deque<type>& deque)
{
	if (this->isOpen == false) {
		throw std::exception("File is not openning");
	}
	typename Deque<type>::iterator it;
	for (it = deque.it_begin(); it != deque.it_end(); it++) {
		this->fileStream.write(reinterpret_cast<char*>(&(*it)), sizeof(type));
	}
}

template<class type>
inline void File::read_binary(Deque<type>& deque)
{
	if (this->isOpen == false) {
		throw std::exception("File is not openning");
	}
	while (!this->fileStream.eof()) {
		type T;
		this->fileStream.read(reinterpret_cast<char*>(&T), sizeof(type));
		deque.pushTop(T);
	}

	deque.popTop();
}

template<class type>
inline void File::read_index_binary(Deque<type>& deque)
{
	if (this->isOpen == false) {
		throw std::exception("File is not openning");
	}
	this->fileStream.peek();
	std::cout << "Input index" << std::endl;
	int index = RangeException::inputInt(std::cin, 0, 100000);
	this->fileStream.seekg(index * sizeof(type), ios::beg);
	this->fileStream.peek();
	if (this->fileStream.eof()) {
		std::cout << "Out of range" << std::endl;
		system("PAUSE");
		return;
	}
	type T;
	this->fileStream.read(reinterpret_cast<char*>(&T), sizeof(type));
	std::cout << T << std::endl;
	std::cout << "OK" << std::endl;
	system("PAUSE");
}

template<class type>
inline void File::swap_first_last(Deque<type>& deque, const char *filename)
{
	if (this->isOpen == false) {
		throw std::exception("File is not openning");
	}
	this->fileStream.peek(); 
	if (this->fileStream.eof()) {
		std::cout << "File is empty" << std::endl;
		system("PAUSE");
		return;
	}

	int classSize = sizeof(type);

	this->fileStream.seekg(0, ios::beg);
	type first;
	this->fileStream.read(reinterpret_cast<char*>(&first), sizeof(type));

	this->fileStream.seekg(-classSize, ios::end);
	type second;
	this->fileStream.read(reinterpret_cast<char*>(&second), sizeof(type));

	this->fileStream.close();

	std::fstream newStream;
	newStream.open(filename, std::ios_base::binary | std::ios_base::out);

	newStream.seekg(-classSize, ios::end);
	newStream.write(reinterpret_cast<char*>(&first), sizeof(type));

	newStream.seekg(0, ios::beg);
	newStream.write(reinterpret_cast<char*>(&second), sizeof(type));

	system("PAUSE");
}
