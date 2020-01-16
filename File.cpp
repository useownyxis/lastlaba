#include "File.h"

File::File(const char* fileName)
{
	this->isOpen = false;
}

File::~File()
{
	fileStream.close();
}

void File::openBinaryFileRead(const char* fileName)
{
	if (this->isOpen) {
		fileStream.close();
		this->isOpen = false;
	}
	this->fileStream.open(fileName, std::ios_base::binary | std::ios_base::in);
	if (!this->fileStream.is_open()) {
		throw std::exception("Cannot open your file");
	}
	this->isOpen = true;
}

void File::openBinaryFileWrite(const char* fileName)
{
	if (this->isOpen) {
		fileStream.close();
		this->isOpen = false;
	}
	this->fileStream.open(fileName, std::ios_base::binary | std::ios_base::out);
	if (!this->fileStream.is_open()) {
		throw std::exception("Cannot open your file");
	}
	this->isOpen = true;
}

void File::openTextFileRead(const char* filename)
{
	if (this->isOpen) {
		fileStream.close();
		this->isOpen = false;
	}
	this->fileStream.open(filename, std::ios_base::in);
	if (!this->fileStream.is_open()) {
		throw std::exception("Cannot open your file");
	}
	this->isOpen = true;
}

void File::openTextFileWrite(const char* filename)
{
	if (this->isOpen) {
		fileStream.close();
		this->isOpen = false;
	}
	this->fileStream.open(filename, std::ios_base::out);
	if (!this->fileStream.is_open()) {
		throw std::exception("Cannot open your file");
	}
	this->isOpen = true;
}